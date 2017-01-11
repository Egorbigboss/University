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

		if (argc != 4){puts("Not enough arguments! \n");return -2;}

	  f = fopen(argv[1],"r");
	  f1 = fopen(argv[2],"r");
		if ((!f)){puts("Wrong file names! \n");return -1;}
		if ((!f1)){puts("Wrong file names! \n");fclose(f);return -1;}
	  int w = 0;
	  int h = 0;
	  fscanf(f,"%d",&w);
	  fscanf(f,"%d",&h);
		if((w < 0) || (h < 0)){printf("\nIncorrect parametrs! \n");return -1;}
	  matrix = init_matrix(w,h,f,&ERRNO);
	  if(!ERRNO){


			printf("\nWidth - %d\nHeight - %d\n",w,h);
			print_matrix(matrix);
		  fscanf(f1,"%d",&w);
		  fscanf(f1,"%d",&h);
			if((w < 0) || (h < 0)){printf("\nIncorrect parametrs! \n");return -1;}
		  matrix1 = init_matrix(w,h,f1,&ERRNO);

		  printf("\nWidth - %d\nHeight - %d\n",w,h);
			int j = 0;
			int i = 0;
			int k = 0;


		  print_matrix(matrix1);

			if(!strcmp(argv[3], "A")){
				puts("Addition\n");
				matrixr1 = mul_matrix(matrix, matrix1);
				print_matrix(matrixr1);
				free_matrix(matrixr1);
			}
			if(!strcmp(argv[3], "M")){
				puts("Multiplication\n");
				matrixr = sum_matrix(matrix, matrix1);
				print_matrix(matrixr);
				free_matrix(matrixr);
			}
			if(!strcmp(argv[3], "D")){
				puts("Determinant of first matrix\n");
				int a = FIND_Det(matrix->pointer,matrix->width,matrix->height );
				printf("\nDeterminant = %d\n",a);

			}

			free_matrix(matrix);
		  free_matrix(matrix1);

			fclose(f);
			fclose(f1);
		  return 0;

  }
	free_matrix(matrix);

}
