
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "multiply.h"

matrix *m1, *m2, *ans;

void *solve_row(void *row_index);

void *solve_cell(void *param);

matrix *multiply_method_1(matrix **matA, matrix **matB) {
    m1 = *(matA);
    m2 = *(matB);
    ans = build_matrix(m1->rows_count, m2->columns_count);
    pthread_t rows_solvers[ans->rows_count];
    for (int i = 0; i < ans->rows_count; i++) {
        int *row_index = malloc(sizeof(int));
        *row_index = i;
        if (pthread_create(&rows_solvers[i], NULL, solve_row, row_index)) {
            fprintf(stderr, "Error while creating thread\n");
            return NULL;
        }
    }
    for (int i = 0; i < ans->rows_count; i++) {
        pthread_join(rows_solvers[i], NULL);
    }
    return ans;
}

void *solve_row(void *param) {
    int row_index = *(int *) param;
    for (int i = 0; i < ans->columns_count; i++) {
        long long cell_ans = 0;
        for (int j = 0; j < m1->columns_count; j++) {
            cell_ans += m1->data[row_index][j] * m2->data[j][i];
        }
        ans->data[row_index][i] = cell_ans;
    }
    return NULL;
}

matrix *multiply_method_2(matrix **matA, matrix **matB) {
    m1 = *(matA);
    m2 = *(matB);
    ans = build_matrix(m1->rows_count, m2->columns_count);
    pthread_t threads_matrix[ans->rows_count][ans->columns_count];
    for (int i = 0; i < ans->rows_count; i++) {
        for (int j = 0; j < ans->columns_count; j++) {
            int *pos = malloc(sizeof(int) * 2);
            pos[0] = i;
            pos[1] = j;
            if (pthread_create(&threads_matrix[i][j], NULL, solve_cell, pos)) {
                fprintf(stderr, "Error while creating thread");
                return NULL;
            }
        }
    }
    for (int i = 0; i < ans->rows_count; i++) {
        for (int j = 0; j < ans->columns_count; j++) {
            if (pthread_join(threads_matrix[i][j], NULL)) {
                fprintf(stderr, "Error while waiting for thread to finish\n");
                return NULL;
            }
        }
    }
    return ans;
}

void *solve_cell(void *param) {
    int row = ((int *) param)[0];
    int col = ((int *) param)[1];
    long long cell_ans = 0;
    for (int k = 0; k < m1->columns_count; k++) {
        cell_ans += m1->data[row][k] * m2->data[k][col];
    }
    ans->data[row][col] = cell_ans;
}
