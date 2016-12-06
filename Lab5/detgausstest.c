#include "funcs.h"

int main(int argc, char const *argv[]) {
  int sizeh = 5;
  int sizew = 4;
  matrix_s *matrix = init_smatrix(sizeh, sizew);
  int res = det_gause(matrix);
  if (res == 0 ) {
    printf("Test1 passed.\n");
  }
  else{
    printf("Test1 failed.\n");
  }
  sizeh = 3;
  sizew = 3;
  matrix = init_smatrix(sizeh,sizew);
  int k = 0;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      matrix->pointer[i][j] = k;
      k = k + 3;
    }
  }
  matrix->pointer[0][0] = 1000;
  res = det_gause(matrix);
  if (res == -27000){
    printf("Test2 passed.\n");
  }
  else{
    printf("Test2 failed.\n");
  }
  return 0;
}
