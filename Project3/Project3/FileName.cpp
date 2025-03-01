#include <stdio.h>
#include <stdbool.h>

#define ROWS 3
#define COLS 4

bool is_match(int matrix[ROWS][COLS], int row_index, int target_row[COLS]) {
    for (int i = 0; i < COLS; i++) {
        if (matrix[row_index][i] != target_row[i]) {
            return false;
        }
    }
    return true;
}

void find_rows(int matrix[ROWS][COLS], int target_row[COLS], int* result, int* count) {
    *count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (is_match(matrix, i, target_row)) {
            result[(*count)++] = i;
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4}
    };

    int target_row[COLS] = { 1, 2, 3, 4 };
    int result[ROWS];
    int count;

    find_rows(matrix, target_row, result, &count);

    printf("Найденные индексы строк: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}