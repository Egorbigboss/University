#include "funcs.h"

int main(int argc, char *argv[])
{
	  puts("kek");
	  int ERRNO = 0;
	  matrix_s* matrix;
	  matrix_s* matrix1;
	  matrix_s* matrixr;
	  matrix_s* matrixr1;
	  puts("kek");


	  FILE *f;
	  FILE *f1;
	  f = fopen(argv[1],"r");
	  f1 = fopen(argv[2],"r");
	  int w = 0;
	  int h = 0;
	  fscanf(f,"%d",&w);
	  fscanf(f,"%d",&h);
	  puts("kek");


	  matrix = init_matrix(w,h,f,&ERRNO);
	  puts("kek");
	  if(!ERRNO){

		  fscanf(f1,"%d",&w);
		  fscanf(f1,"%d",&h);
		  matrix1 = init_matrix(w,h,f1,&ERRNO);

		  printf("\nWidth - %d\nHeight - %d\n",w,h);
			int j = 0;
			int i = 0;
			int k = 0;
		  puts("kek");


		  print_matrix(matrix);
		  print_matrix(matrix1);
		  puts("");
		  for (int i = 0; i<matrix1->height; i++)
		  {
			 for (int j = 0; j<matrix1->width; j++)
				 printf("%.2f\t", matrix1->pointer[i][j]);
			  printf("\n");
		  }
		  int a = FIND_Det(matrix->pointer,matrix->width,matrix->height );
		  printf("\nOpdredelitel' - %d\n",a);

			//det_raz(matrix,4,4,&opr);
			printf("\nOpred - %d\n",FIND_Det(matrix->pointer,matrix->width,matrix->height));
		  puts("kek1");
		  matrixr = sum_matrix(matrix, matrix1, matrix->width, matrix1->height);
		  puts("kek2");
		  matrixr1 = mul_matrix(matrix, matrix1, 3, 3);
		  //print_matrix(matrix);
		  print_matrix(matrixr1);
		  print_matrix(matrixr);
		  // det_gause(matrix);
		  // print_matrix(matrix);
		  free_matrix(matrix);
		  free_matrix(matrix1);
		  free_matrix(matrixr);
		  return 0;

  }

}


















//printf("\n%d\n",sizeof(matrix->pointer));
/**
for (i = 0;i < matrix->height;i++)
{
for (j = 0;j < matrix->height;j++)
{
printf("\nm[%d][%d]:%f\n",i,j,matrix->pointer[i][j]);
}
}
**/
//printf("%f\n",det_gause(matrix));
