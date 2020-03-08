/*
 * trick_or_treat.c
 *
 * Author: Jonathan Dobson <dobsonj@gmail.com>
 * Date:   09/02/2017
 *
 * Problem:
 *   Given an input file containing the max number of homes in a neighborhood,
 *   the max pieces of candy allowed to be collected, and the number of pieces
 *   provided by each home, find the sequence of homes that yields the most
 *   pieces of candy without exceeding the max.
 *   
 * Assumptions:
 *   0 < max_homes <= 10,000
 *   0 <= max_pieces <= 1,000
 *   0 <= pieces <= 1,000
 *
 * Directions:
 *   gcc -fopenmp -o trick_or_treat trick_or_treat.c
 *   export OMP_NUM_THREADS=[numthreads]
 *   ./trick_or_treat [input_file]
 *
 *   If no input file is provided, this program will try to open "input.txt"
 *   in the local directory.
 *
 * Performance with 1 thread and 10,000 homes:
 *   # gcc -o trick_or_treat trick_or_treat.c && time ./trick_or_treat 
 *   Start at home 1 and go to home 10000 getting 10000 pieces of candy
 *
 *   real	0m0.212s
 *   user	0m0.208s
 *   sys	0m0.000s
 *
 * Performance with 4 threads and 10,000 homes:
 *   # export OMP_NUM_THREADS=4
 *   # gcc -fopenmp -o trick_or_treat trick_or_treat.c && time ./trick_or_treat
 *   Start at home 1 and go to home 10000 getting 10000 pieces of candy
 *
 *   real	0m0.121s
 *   user	0m0.312s
 *   sys	0m0.000s
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define	DEFAULT_FILE	"input.txt"
#define MAX_LINE_SIZE	6

/*
 * Unsigned 16-bit integers are used to limit memory consumption since all of
 * the variables are constrained to values between 0 and 10,000.
 */
typedef struct {
	uint16_t start;	/* starting home number */
	uint16_t end;	/* ending home number */
	uint16_t total; /* total pieces of candy collected */
} sequence_t;

/*
 * Each input file is limited no more than 10,000 homes, which means we can
 * comfortably fit the entire input set in 20kb memory or less. We'll allocate
 * at most another 60kb of sequence_t entries during find_sequence(). This
 * means that it should be safe on any reasonably modern system to read the
 * input file exactly once and do everything else in-memory so that we're not
 * I/O limited while finding the best sequence.
 */
static int
read_input(const char *filename, uint16_t *max_homes, uint16_t *max_pieces,
    uint16_t **home_list)
{
	FILE *fp = NULL;
	char *buf = NULL;
	size_t len = MAX_LINE_SIZE;
	size_t index = 0;
	uint16_t nhomes = 0;
	uint16_t *input_set = NULL;
	int rval = -1;

	if (filename == NULL) {
		printf("no filename provided to read_input()\n");
		goto out;
	}

	if ((fp = fopen(filename, "r")) == NULL) {
		printf("read_input() failed to open %s for reading.\n",
		    filename);
		goto out;
	}

	if ((buf = malloc(len)) == NULL) {
		printf("read_input() failed to allocate %lu bytes\n", len);
		goto out;
	}

	uint16_t line_num = 0;
	while (getline(&buf, &len, fp) != -1) {
		unsigned long value = strtoul(buf, NULL, 10);
		if (errno == ERANGE || errno == EINVAL || value > UINT16_MAX) {
			printf("read_input() failed to convert %s to "
			    "uint16_t on line %u\n", buf, line_num);
			goto out;
		}

		/*
		 * line 0: max number of homes on the block
		 * line 1: max pieces of candy that may be collected
		 * lines 2 - n: number of pieces of candy given at each home
		 */
		switch (line_num) {
		case 0:
			nhomes = (uint16_t)value;
			if (max_homes != NULL)
				*max_homes = (uint16_t)value;

			size_t size = nhomes * sizeof (uint16_t);
			if ((input_set = malloc(size)) == NULL) {
				printf("read_input() failed to allocate %lu "
				    "bytes for %u homes\n", size, nhomes);
				goto out;
			}
			memset(input_set, 0, size);
			break;

		case 1:
			if (max_pieces != NULL)
				*max_pieces = (uint16_t)value;
			break;

		default:
			/*
			 * Quietly ignore any homes beyond the max number
			 * to avoid buffer overflows. Alternatively, this could
			 * be treated as an input validation error.
			 */
			index = line_num - 2;
			if (index >= nhomes) {
				rval = 0;
				goto out;
			}
			input_set[index] = (uint16_t)value;
			break;
		}

		line_num++;
	}

	rval = 0;
out:
	if (rval == 0 && home_list != NULL)
		*home_list = input_set;
	else
		free(input_set);
	if (fp != NULL)
		fclose(fp);
	free(buf);
	return (rval);
}

static int
find_sequence(uint16_t max_homes, uint16_t max_pieces, uint16_t *home_list,
    sequence_t *winner)
{
	sequence_t *list = NULL;
	uint16_t i, j, sum;

	size_t size = max_homes * sizeof (sequence_t);
	if ((list = malloc(size)) == NULL) {
		printf("find_sequence() failed to allocate %lu bytes for "
		    "%u homes\n", size, max_homes);
		return (-1);
	}

	/*
	 * First, we calculate the amount of candy that can be gained starting
	 * at each house in the list. The outer loop iterations can be executed
	 * in parallel by multiple threads, as long as j and sum are thread
	 * local variables.
	 */
	#pragma omp parallel for private(j,sum)
	for (i = 0; i < max_homes; i++) {
		list[i].total = 0;
		list[i].start = i + 1;
		/*
		 * If there's no candy at this house, then there's no reason
		 * to start here.
		 */
		if (home_list[i] == 0)
			continue;

		for (j = i; j < max_homes; j++) {
			sum = list[i].total + home_list[j];
			/*
			 * Only update the total and end number if this
			 * house increases our total without exceeding the max.
			 */
			if (sum > list[i].total && sum <= max_pieces) {
				list[i].total = sum;
				list[i].end = j + 1;
			}
			/* We're done if we met or exceeded the max. */
			if (sum >= max_pieces)
				break;
		}
	}

	/*
	 * Now that the heavy lifting is done, we just need to make one final
	 * pass through the list to find the 'winner'. The winner is the
	 * sequence of homes that yields the most pieces of candy without
	 * exceeding the max. In cases where there are multiple sequences that
	 * yield the same amount of candy, we choose the first one.
	 */
	winner->total = 0;
	for (i = 0; i < max_homes; i++) {
		if (list[i].total > winner->total)
			(void) memcpy(winner, &list[i], sizeof (sequence_t));
		if (winner->total == max_pieces)
			break;
	}

	free(list);
	return (0);
}

static void
print_summary(sequence_t *winner)
{
	if (winner == NULL)
		printf("no winner provided to print_summary()\n");
	else if (winner->total == 0)
		printf("Don't go here\n");
	else
		printf("Start at home %u and go to home %u getting %u pieces "
		    "of candy\n", winner->start, winner->end, winner->total);
}

int
main(int argc, char **argv)
{
	char *filename = DEFAULT_FILE;
	uint16_t max_homes = 0, max_pieces = 0;
	uint16_t *home_list = NULL;
	sequence_t winner = { 0 };
	int rval = -1;

	if (argc > 2) {
		printf("usage: %s [input_file]\n", argv[0]);
		goto out;
	} else if (argc == 2) {
		filename = argv[1];
	}

	if (read_input(filename, &max_homes, &max_pieces, &home_list) != 0) {
		printf("read_input() returned an error, exiting.\n");
		goto out;
	}

	if (find_sequence(max_homes, max_pieces, home_list, &winner) != 0) {
		printf("find_sequence() returned an error, exiting.\n");
		goto out;
	}

	print_summary(&winner);
	rval = 0;
out:
	free(home_list);
	return (rval);
}
