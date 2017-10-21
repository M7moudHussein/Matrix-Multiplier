#include <stdio.h>
#include "file_manager.h"

matrix *read_matrix(FILE *input_file_ptr) {
    int rows, columns;
    fscanf(input_file_ptr, "row=%d col=%d\n", &rows, &columns);
    matrix *result = build_matrix(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            fscanf(input_file_ptr, "%lld", &result->data[i][j]);\
    fclose(input_file_ptr);
    return result;
}

void write_matrix(FILE *output_file_ptr, matrix **mat) {
    int new_line_index = (*mat)->columns_count - 1;
    for (int i = 0; i < (*mat)->rows_count; i++) {
        for (int j = 0; j < (*mat)->columns_count; j++) {
            fprintf(output_file_ptr, "%lld%c", (*mat)->data[i][j], j != new_line_index ? '\t' : '\n');
        }
    }
    fclose(output_file_ptr);
}

void write_str(FILE *output_file_ptr, char **str) {
    fprintf(output_file_ptr, "%s\n", *str);
    fclose(output_file_ptr);
}
