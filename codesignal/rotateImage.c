// 
// rotateImage
// 
// Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.
// 
// You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).
// 
// Example
// 
// For
// 
// a = [[1, 2, 3],
//      [4, 5, 6],
//      [7, 8, 9]]
// the output should be
// 
// rotateImage(a) =
//     [[7, 4, 1],
//      [8, 5, 2],
//      [9, 6, 3]]
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

arr_arr_integer rotateImage(arr_arr_integer a) {
    for (int i = 0; i < a.size; i++) {
        for (int j = i + 1; j < a.size; j++) {
            int tmp = a.arr[i].arr[j];
            a.arr[i].arr[j] = a.arr[j].arr[i];
            a.arr[j].arr[i] = tmp;
        }
    }
    for (int i = 0; i < a.size; i++) {
        int p1 = 0;
        int p2 = a.size - 1;
        while (p1 < p2) {
            int tmp = a.arr[i].arr[p1];
            a.arr[i].arr[p1] = a.arr[i].arr[p2];
            a.arr[i].arr[p2] = tmp;
            p1++;
            p2--;
        }
    }
    return a;
}

