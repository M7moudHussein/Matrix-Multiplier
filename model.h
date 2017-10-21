#ifndef LAB_02_MODEL_H
#define LAB_02_MODEL_H

typedef struct matrix {
    int rows_count;
    int columns_count;
    long long **data;
} matrix;

matrix *build_matrix(int, int);

#endif //LAB_02_MODEL_H
