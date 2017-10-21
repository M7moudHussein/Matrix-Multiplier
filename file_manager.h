#ifndef LAB_02_FILE_READER_H
#define LAB_02_FILE_READER_H

#include "model.h"

matrix *read_matrix(FILE *);

void write_matrix(FILE *, matrix **);

void write_str(FILE *, char **);

#endif //LAB_02_FILE_READER_H
