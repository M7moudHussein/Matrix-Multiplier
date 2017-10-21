#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "file_manager.h"
#include "multiply.h"

int main(int argc, char **argv) {
    char *inputA, *inputB, *outputC, *separator;
    if (argc == 1) {
        inputA = "a.txt", inputB = "a.txt", outputC = "c.out";
    } else if (argc == 4) {
        inputA = argv[1], inputB = argv[2], outputC = argv[3];
    } else {
        fprintf(stderr, "Wrong number of arguments!\n");
        exit(0);
    }
    matrix *A = read_matrix(fopen(inputA, "r"));
    matrix *B = read_matrix(fopen(inputB, "r"));

    struct timeval stop, start;

    gettimeofday(&start, NULL);
    matrix *method_1_ans = multiply_method_1(&A, &B);
    gettimeofday(&stop, NULL);

    long long method_1_time = stop.tv_usec - start.tv_usec;

    separator = "==============Rows Method==============\n";
    puts(separator);
    write_str(fopen(outputC, "w"), &separator);
    write_matrix(fopen(outputC, "a"), &method_1_ans);
    printf("Method One Number Of Threads = %d\n", method_1_ans->rows_count);
    printf("Method One Time = %lld micro seconds\n", method_1_time);

    gettimeofday(&start, NULL);
    matrix *method_2_ans = multiply_method_1(&A, &B);
    gettimeofday(&stop, NULL);

    long long method_2_time = stop.tv_usec - start.tv_usec;

    separator = "==============Cells Method=============\n";
    puts(separator);
    write_str(fopen(outputC, "a"), &separator);
    write_matrix(fopen(outputC, "a"), &method_2_ans);
    printf("Method Two Number Of Threads = %d\n", method_2_ans->rows_count * method_2_ans->columns_count);
    printf("Method Two Time = %lld micro seconds\n", method_2_time);
    return 0;
}