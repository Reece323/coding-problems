// 
// adjacentElementsProduct
// 
// Given an array of integers, find the pair of adjacent elements that has the largest product and return that product.
// 
// Example
// 
// For inputArray = [3, 6, -2, -5, 7, 3], the output should be
// adjacentElementsProduct(inputArray) = 21.
// 
// 7 and 3 produce the largest product.
// 
// Input/Output
// 
// [execution time limit] 0.5 seconds (c)
// 
// [input] array.integer inputArray
// 
// An array of integers containing at least two elements.
// 
// Guaranteed constraints:
// 2 ≤ inputArray.length ≤ 10,
// -1000 ≤ inputArray[i] ≤ 1000.
// 
// [output] integer
// 
// The largest product of adjacent elements.
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

int adjacentElementsProduct(arr_integer inputArray) {
    int maxProd = -INT_MAX;
    for (int i = 0; i < inputArray.size - 1; i++) {
        int prod = inputArray.arr[i] * inputArray.arr[i+1];
        if (prod > maxProd)
            maxProd = prod;
    }
    return maxProd;
}

