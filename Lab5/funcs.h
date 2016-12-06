#ifndef FUNCS_H
#define FUNCS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPS 0.001

#define NO_ERROR 0
#define ERROR_PARAM -1
#define NO_MEMORY -2

typedef struct matrix
{
    double** pointer;
    int height, width;
} matrix_s;

matrix_s* init_matrix(int n, int m,FILE *f,int *ERRNO);
matrix_s* init_smatrix(int n, int m);
void swap_str(double** matrix, int n, int m);
void print_matrix(matrix_s* matrix);
double det_gause(matrix_s* matrix);
void free_matrix(matrix_s* matrix);
double det_raz(matrix_s* matrix,int w,int h,double *opr);
matrix_s *sum_matrix(matrix_s* a, matrix_s* b, int size_a, int size_b);
matrix_s *mul_matrix(matrix_s* a, matrix_s* b, int size_a, int size_b);
int FIND_Det( double **matrix,int sizeh,int sizew);
double **FIND_Minor( double **matrix, int size, int str, int stb );


#endif // FUNCS_H
