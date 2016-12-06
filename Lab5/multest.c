#include "funcs.h"




void main(){
  int k = 15;
  matrix_s* matrix;
  matrix_s* matrix1;
  matrix_s* matrix2;
  matrix_s* matrix3;
  matrix_s* matrix4;
  matrix_s* matrix5;
  matrix4 = init_smatrix(3,4);
  matrix5 = init_smatrix(3,3);
  matrix3 = init_smatrix(3,3);
  printf("\nTesting matrix \n");
  for(int i = 0;i < 1;i++){
    for(int j = 0;j < 3;j++){
      matrix3->pointer[i][j] = k;
      k = k + 3;
    }
  }
  k = 42;
  for(int i = 1;i < 2;i++){
    for(int j = 0;j < 3;j++){
      matrix3->pointer[i][j] = k;
      k = k + 12;
    }
  }
  k = 69;
  for(int i = 2;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix3->pointer[i][j] = k;
      k = k + 21;
    }
  }
  print_matrix(matrix3);
  int a = 1;
  k = 0;
  matrix = init_smatrix(3,3);
  matrix1 = init_smatrix(3,3);
  matrix5 = mul_matrix(matrix1,matrix4);

  if(!matrix5){printf("\nOK\n");}
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix1->pointer[i][j] = k;
      k++;
    }
  }
  k = 0;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix->pointer[i][j] = k;
      k++;
    }
  }
  printf("\nTesting matrix multiplication...\n");
  matrix2 = init_smatrix(3,3);
  print_matrix(matrix2);
  print_matrix(matrix);
  print_matrix(matrix1);
  matrix2 = sum_matrix(matrix,matrix1);
  print_matrix(matrix2);
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if (matrix2->pointer[i][j] != matrix3->pointer[i][j]){
        a = 0;
      }
    }
  }
  if(a){printf("\nOK!\n");}

}
