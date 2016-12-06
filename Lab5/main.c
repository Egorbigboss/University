#include "funcs.h"

int main(int argc, char *argv[])
{
	  int ERRNO = 0;
	  matrix_s* matrix;
	  matrix_s* matrix1;
	  matrix_s* matrixr;
	  matrix_s* matrixr1;
	  FILE *f = NULL;
	  FILE *f1 = NULL;
		if (argc != 3){puts("Not enough arguments! \n");return -2;}
	  f = fopen(argv[1],"r");
	  f1 = fopen(argv[2],"r");
		if ((!f)){puts("Wrong file names! \n");return -1;}
		if ((!f1)){puts("Wrong file names! \n");fclose(f);return -1;}
	  int w = 0;
	  int h = 0;
	  fscanf(f,"%d",&w);
	  fscanf(f,"%d",&h);
	  matrix = init_matrix(w,h,f,&ERRNO);
	  if(!ERRNO){

		  fscanf(f1,"%d",&w);
		  fscanf(f1,"%d",&h);
		  matrix1 = init_matrix(w,h,f1,&ERRNO);

		  printf("\nWidth - %d\nHeight - %d\n",w,h);
			int j = 0;
			int i = 0;
			int k = 0;

		  print_matrix(matrix);
		  print_matrix(matrix1);
		  for (int i = 0; i<matrix1->height; i++)
		  {
			 for (int j = 0; j<matrix1->width; j++)
				 printf("%.2f\t", matrix1->pointer[i][j]);
			  printf("\n");
		  }
		  int a = FIND_Det(matrix->pointer,matrix->width,matrix->height );
		  printf("\nDeterminant' - %d\n",a);
		  matrixr = sum_matrix(matrix, matrix1);
		  matrixr1 = mul_matrix(matrix, matrix1);

		  print_matrix(matrixr1);
		  print_matrix(matrixr);
			free_matrix(matrix);
		  free_matrix(matrix1);
		  free_matrix(matrixr);
			free_matrix(matrixr1);
		  return 0;

  }
	free_matrix(matrix);

}
