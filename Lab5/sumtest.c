#include "funcs.h"

void main(){
  int k = 0;
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
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix3->pointer[i][j] = k;
      k = k + 2;
    }
  }
  int a = 1;
  k = 0;
  matrix5 = mul_matrix(matrix5,matrix4);
  if(!matrix5){printf("\nOK!\n");}
  matrix = init_smatrix(3,3);
  matrix1 = init_smatrix(3,3);
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix1->pointer[i][j] = k;
      k++;
    }
  }
  k = 0;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix1->pointer[i][j] = k;
      k++;
    }
  }
  printf("\nTesting matrix addition...\n");
  matrix2 = init_smatrix(3,3);
  matrix2 = mul_matrix(matrix,matrix1);
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if (matrix2->pointer[i][j] != matrix1->pointer[i][j]){
        a = 0;
      }
    }
  }
  if(a){printf("\nOK!\n");}

}
