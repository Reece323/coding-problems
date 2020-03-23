// 
// isCryptSolution
// 
// A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits, such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.
// 
// You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits, solution. The array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3], which should be interpreted as the word1 + word2 = word3 cryptarithm.
// 
// If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution, becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true. If it does not become a valid arithmetic solution, the answer is false.
// 
// Note that number 0 doesn't contain leading zeroes (while for example 00 or 0123 do).
// 
// Example
// 
// For crypt = ["SEND", "MORE", "MONEY"] and
// 
// solution = [['O', '0'],
//             ['M', '1'],
//             ['Y', '2'],
//             ['E', '5'],
//             ['N', '6'],
//             ['D', '7'],
//             ['R', '8'],
//             ['S', '9']]
// the output should be
// isCryptSolution(crypt, solution) = true.
// 
// When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.
// 
// For crypt = ["TEN", "TWO", "ONE"] and
// 
// solution = [['O', '1'],
//             ['T', '0'],
//             ['W', '9'],
//             ['E', '5'],
//             ['N', '4']]
// the output should be
// isCryptSolution(crypt, solution) = false.
// 
// Even though 054 + 091 = 145, 054 and 091 both contain leading zeroes, meaning that this is not a valid solution.
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

void decrypt(char *out, const char *in, size_t len, arr_arr_char *solution) {
    int i, j;
    
    for (i = 0; i < len; i++) {
        for (j = 0; j < solution->size; j++) {
            if (in[i] == solution->arr[j].arr[0]) {
                out[i] = solution->arr[j].arr[1];
                break;
            }
        }
    }
    
}

bool hasLeadingZeros(const char *str, size_t len) {
    return (str[0] == '0' && len > 1);
}

bool isCryptSolution(arr_string crypt, arr_arr_char solution) {
    char num[3][256] = {0};
    
    // decrypt and check for leading zeros
    for (int i = 0; i < crypt.size; i++) {
        size_t len = strlen(crypt.arr[i]);
        decrypt(num[i], crypt.arr[i], len, &solution);
        if (hasLeadingZeros(num[i], len))
            return false;
    }
    
    // compare numbers
    if (atoi(num[0]) + atoi(num[1]) != atoi(num[2]))
        return false;
    
    return true;
}

