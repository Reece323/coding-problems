// 
// Make Array Consecutive 2
// 
// Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, each statue having an non-negative integer size. Since he likes to make things perfect, he wants to arrange them from smallest to largest so that each statue will be bigger than the previous one exactly by 1. He may need some additional statues to be able to accomplish that. Help him figure out the minimum number of additional statues needed.
// 
// Example
// 
// For statues = [6, 2, 3, 8], the output should be
// makeArrayConsecutive2(statues) = 3.
// 
// Ratiorg needs statues of sizes 4, 5 and 7.
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
//

int makeArrayConsecutive2(arr_integer statues) {
    int i, min = INT_MAX, max = 0;
    
    for (i = 0; i < statues.size; i++) {
        int val = statues.arr[i];
        if (val > max)
            max = val;
        if (val < min)
            min = val;
    }
    
    int needed = max - min;
    for (i = min; i < max; i++) {
        for (int j = 0; j < statues.size; j++) {
            if (statues.arr[j] == i)
                needed--;
        }
    }
    
    return needed;
}

