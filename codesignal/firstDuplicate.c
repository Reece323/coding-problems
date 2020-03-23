// 
// firstDuplicate
// 
// Given an array a that contains only numbers in the range from 1 to a.length, find the first duplicate number for which the second occurrence has the minimal index. In other words, if there are more than 1 duplicated numbers, return the number for which the second occurrence has a smaller index than the second occurrence of the other number does. If there are no such elements, return -1.
// 
// Example
// 
// For a = [2, 1, 3, 5, 3, 2], the output should be firstDuplicate(a) = 3.
// 
// There are 2 duplicates: numbers 2 and 3. The second occurrence of 3 has a smaller index than the second occurrence of 2 does, so the answer is 3.
// 
// For a = [2, 2], the output should be firstDuplicate(a) = 2;
// 
// For a = [2, 4, 3, 5, 1], the output should be firstDuplicate(a) = -1.
// 
// Definition for arrays:
// typedef struct arr_##name {
//   int size;
//   type *arr;
// } arr_##name;
//
// arr_##name alloc_arr_##name(int len) {
//   arr_##name a = {len, len > 0 ? malloc(sizeof(type) * len) : NULL};
//   return a;
// }
//

int firstDuplicate(arr_integer a) {
    int i;
    char *seen = calloc(a.size + 1, sizeof(char));
    for (i = 0; i < a.size; i++) {
        int val = a.arr[i];
        if (seen[val]) {
            free(seen);
            return val;
        } else {
            seen[val]++;
        }
    }
    free(seen);
    return -1;
}

