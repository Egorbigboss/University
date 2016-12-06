#include "funcs.h"




void main(){
  int k = 15;
  matrix_s* matrix;
  matrix_s* matrix1;
  matrix_s* matrix2;
  matrix_s* matrix3;
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
  printf("\nkek2\n");
  int a = 1;
  k = 0;
  matrix = init_smatrix(3,3);
  matrix1 = init_smatrix(3,3);
  printf("\nkek3\n");
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix1->pointer[i][j] = k;
      k++;
    }
  }
  printf("\nkek4\n");
  k = 0;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix1->pointer[i][j] = k;
      k++;
    }
  }
  printf("\nTesting matrix addition...\n");
  matrix2 = init_smatrix(3,3);
  matrix2 = mul_matrix(matrix,matrix1,3,3);
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if (matrix2->pointer[i][j] != matrix1->pointer[i][j]){
        a = 0;
      }
    }
  }
  if(a){printf("\nOK!\n");}

}
