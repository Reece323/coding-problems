// 
// sudoku2
// 
// Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.
// 
// Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.
// 
// Example
// 
// For
// 
// grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
//         ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
//         ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
//         ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
//         ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
//         ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
//         ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
// the output should be
// sudoku2(grid) = true;
// 
// For
// 
// grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
//         ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
//         ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
//         ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
//         ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
//         ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
//         ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
//         ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
//         ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
// the output should be
// sudoku2(grid) = false.
// 
// The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.
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

bool sudoku2(arr_arr_char grid) {
    int i,j;
    
    // each row
    for (i = 0; i < grid.size; i++) {
        char seen[10] = {0};
        for (j = 0; j < grid.size; j++) {
            char val = grid.arr[i].arr[j];
            int num = val - '0';
            if (val == '.')
                continue;
            if (seen[num])
                return false;
            seen[num] = 1;
        }
    }
    
    // each col
    for (i = 0; i < grid.size; i++) {
        char seen[10] = {0};
        for (j = 0; j < grid.size; j++) {
            char val = grid.arr[j].arr[i];
            int num = val - '0';
            if (val == '.')
                continue;
            if (seen[num])
                return false;
            seen[num] = 1;
        }
    }
    
    // each 3x3
    for (i = 0; i < grid.size; i += 3) {
        for (j = 0; j < grid.size; j += 3) {
            char seen[10] = {0};
            for (int n = 0; n < grid.size; n++) {
                int q = n / 3;
                int r = n % 3;
                char val = grid.arr[i+q].arr[j+r];
                int num = val - '0';
                if (val == '.')
                    continue;
                if (seen[num])
                    return false;
                seen[num] = 1;
            }
        }
    }
    
    return true;
}

