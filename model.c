#include <malloc.h>
#include "model.h"


matrix *build_matrix(int rows_count, int columns_count) {
    matrix *result = malloc(sizeof(int) + sizeof(int) + sizeof(long long **));
    result->rows_count = rows_count;
    result->columns_count = columns_count;
    result->data = malloc(sizeof(long long *) * rows_count);
    for (int i = 0; i < rows_count; i++) {
        result->data[i] = malloc(sizeof(long long) * columns_count);
    }
    for (int i = 0; i < rows_count; i++) {
        for (int j = 0; j < columns_count; j++) {
            result->data[i][j] = 0;
        }
    }
    return result;
}
