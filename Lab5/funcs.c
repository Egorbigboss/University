#include "funcs.h"




matrix_s* init_smatrix(int n, int m)
{
    matrix_s* matrix = malloc(sizeof(matrix_s));
    if (!matrix)
        return NULL;
    matrix->pointer = malloc(n * sizeof(double*) + n * m * sizeof(double));
    if (!matrix->pointer)
    {
        free(matrix);
        return NULL;
    }
    matrix->height = n;
    matrix->width = m;
    for (int i = 0; i < n; i++)
        matrix->pointer[i] = (double*)((char*)matrix->pointer + n * sizeof(double*) +  i * m * sizeof(double));



    return matrix;
}

matrix_s* init_matrix(int n, int m,FILE *f,int *ERRNO)
{
    if ((n == 0) || (m == 0)){
      puts("Matrix size equals 0!");
      *ERRNO = -1;
    }
    matrix_s* matrix = malloc(sizeof(matrix_s));
    if (!matrix)
        return NULL;
    matrix->pointer = malloc(n * sizeof(double*) + n * m * sizeof(double));
    if (!matrix->pointer)
    {
        free(matrix);
        puts("Couldn't malloc!");
        *ERRNO = -2;
    }
    matrix->height = n;
    matrix->width = m;
    for (int i = 0; i < n; i++)
        matrix->pointer[i] = (double*)((char*)matrix->pointer + n * sizeof(double*) +  i * m * sizeof(double));

    for (int i = 0;i < n;i++)
    {
      for (int j = 0;j < m;j++)
      {
        fscanf(f,"%lf",&(matrix->pointer[i][j]));
      }
    }


    return matrix;
}






//Функция нахождения у матрицы порядка size минора M( str, stb ) ( возвращает минор в матричном представлении )
double** FIND_Minor( double **matrix, int size, int str, int stb )
{
	double **minor = malloc((size - 1) * sizeof(double*));
    //m_str, m_stb - коэффициенты, с помощью которых строится сам минор
    int m_str = 0;
    int m_stb;
    for( int i = 0; i < size; i++ )
    {
        //Элементы из строки с номером str не записываются в минор
        if( i != str )
        {
            m_stb = 0;
            minor[ m_str ] = malloc((size - 1) * sizeof(double));
            for( int j = 0; j < size; j++ )
            {
                //Элементы из столбца с номером stb не записываются в минор
                if( j != stb )
                {
                    minor[ m_str ][ m_stb ] = matrix[ i ][ j ];
                    m_stb++;
                }
            }
            m_str++;
        }
    }

    return minor;
}

void print_matrix(matrix_s* matrix)
{
	if(!matrix){puts("Invalid pointer!");}
	else{
		printf("\t\t-Matrix\n");
		for (int i = 0; i<matrix->height; i++)
		{
		   for (int j = 0; j<matrix->width; j++)
			   printf("%.2f\t", matrix->pointer[i][j]);
			printf("\n");
		}
	}
}


int FIND_Det( double **matrix, int sizeh,int sizew )
{
    //Проверка условия выхода из рекурсии
	if (sizeh != sizew){return 0;}
	int size = sizew;
    if( size == 2 )
    {
        return matrix[ 0 ][ 0 ] * matrix[ 1 ][ 1 ] - matrix[ 0 ][ 1 ] * matrix[ 1 ][ 0 ];
    }
    else if( size == 1 )
    {
        return matrix[ 0 ][ 0 ];
    }

    int max_0, str_0 = 0, max_0_b = 0;
    for( int i = 0; i < size; i++ )
    {
        max_0 = 0;
        for( int j = 0; j < size; j++ )
        {
            if( matrix[ i ][ j ] == 0 )
            {
                max_0++;
            }
        }
        if( max_0 > max_0_b )
        {
            str_0 = i;
            max_0_b = max_0;
        }
    }

    //Само рекурсивное разложение по строке
    int result = 0;
    for( int j = 0; j < size; j++ )
    {
        //Небольшой момент оптимизации - если текущий элемент в строке равен нулю, то дальше продолжать рекурсию нету смысла
        //( т.к. произведение будет равно нулю в любом случае )
        if( matrix[ str_0 ][ j ] )
        {
            double** tempm = FIND_Minor( matrix, size, str_0, j );
            result += matrix[ str_0 ][ j ] * pow( -1, j ) * FIND_Det( tempm, size - 1,size - 1  );
            free(tempm);
        }
    }

    return result;
}







void free_matrix(matrix_s* matrix)
{
    free(matrix->pointer);
    free(matrix);
}


matrix_s *sum_matrix(matrix_s* a, matrix_s* b){
	if(a->width == b->height){
		matrix_s* result = init_smatrix(a->width, b->height);
    printf("%d %d\n",a->width, b->height );
		print_matrix(result);
		for(size_t i = 0; i < a->height; i++)
				for(size_t j = 0; j < b->width; j++){
						for(size_t k = 0; k < a->width; k++){
							result->pointer[i][j]+=(a->pointer[i][k])*(b->pointer[k][j]);
						}
						printf("\n ");
					}

		return result;

	}
	else{return NULL;}

}

matrix_s *mul_matrix(matrix_s* a, matrix_s* b){
	if((a->width == b->width) && (a->height == b->height)){
		matrix_s* result = init_smatrix(b->height, b->height);
		for(size_t i=0; i<b->height ; ++i)
				for(size_t j=0; j<b->height; ++j)
					result->pointer[i][j]+=(a->pointer[i][j])+(b->pointer[i][j]);
		return result;
	}
	else{return NULL;}

}

void swap_str(double** matrix, int n, int m)
{
    double* t = matrix[n];
    matrix[n] = matrix[m];
    matrix[m] = t;
}


/**
double det_gause(matrix_s* matrix)
{
    double det = 1;

    double *temp = (double*)malloc(matrix->height *  matrix->height * sizeof(double*));
    // memcpy(temp, matrix->pointer, sizeof(matrix->pointer));
    // double** temp =  malloc(matrix->height * sizeof(double*) + matrix->height * matrix->height * sizeof(double));
    // memcpy(temp,matrix->pointer, matrix->height * sizeof(double*) + matrix->height * matrix->height * sizeof(double));

	for (int i = 0; i < matrix->height; i++)
    {
       for (int j = 0; j < matrix->height; j++){
         temp[i][j] = matrix->pointer[i][j];
       }

    }

    for (int i = 0; i < matrix->height; i++)
      {
         for (int j = 0; j < matrix->height; j++)
             printf("%d\n",temp[i][j] );
      }


    for (int i=0; i < matrix->height; i++)
       {
           int k = i;
           for (int j=i+1; j< matrix->height; j++)
               if (fabs (temp[j][i]) > fabs(temp[k][i]))
                   k = j;

           if (fabs (temp[k][i]) < EPS)
           {
               return 0;
           }

           if (i != k)
           {
               swap_str(temp, i, k);
               det = -det;
           }

           det *= temp[i][i];
           for (int j=i+1; j<matrix->height; ++j)
               temp[i][j] /= temp[i][i];
           for (int j=0; j<matrix->height; ++j)
               if (j != i && fabs (temp[j][i]) > EPS)
                   for (int k=i+1; k<matrix->height; ++k)
                       temp[j][k] -= temp[i][k] * temp[j][i];
       }
    free(temp);
    return det;

  }









**/











//
// double det_raz(matrix_s* matrix,int w,int h,double* opr)
// {
// 	double det = 1;
// 	static int pr = -1;
//
//
// 	double *data;
//
// 	data = malloc(w * h * sizeof(double));
//
//
//
// 	printf("\npr - %d,h - %d\n",pr,h);
//
//
// 	//printf("\n%d\n",sizeof(matrix->pointer));
// 	//double** temp =  malloc((h) * sizeof(double*) + (h) * (h) * sizeof(double));
// 	//printf("\n%d\n",(h * sizeof(double*)) + (h * h * sizeof(double)));
//     //memcpy(temp,matrix->pointer + (matrix->height - h) * sizeof(double*), (matrix->height - h) * sizeof(double*) + (matrix->height - h) * (matrix->height - h) * sizeof(double));
// 	//memcpy(temp,matrix->pointer + ((matrix->height - h) * sizeof(double*)), h * sizeof(double*));
// 	double** temp =  malloc(matrix->height * sizeof(double*) + matrix->height * matrix->height * sizeof(double));
//     memcpy(temp,matrix->pointer, matrix->height * sizeof(double*) + matrix->height * matrix->height * sizeof(double));
// 	int i = 0;
// 	int j = 0;
//
// 	if (data)
// 	{
// 		for (int i = 0; i < matrix->width; i++)
// 			for (int j = matrix->width - h; j < matrix->width; j++)
// 				if((i != pr) && (i >= matrix->width - h))
// 				data[i*h+j] = matrix->pointer[i][j];
//
//
// 	}
// 	/**
// 	for (i = 0; i < h ; i++)
// 	{
// 		memcpy(temp + (h * sizeof(double*)),matrix->pointer + ((matrix->height - h) * sizeof(double*)) + (i * (matrix->height - h) * sizeof(double)) + ((matrix->height - h) * sizeof(double)), (h) * sizeof(double*) + (h) * (h) * sizeof(double));
// 		printf("\nkek%d\n",i);
// 	}**/
// 	//puts("Printing");
//
// 	puts("Temp matr:");
// 	for (i = 0; i < matrix->width; i++)
//     {
//        for (j = matrix->width - h; j < matrix->width; j++)
// 		   if ((i != pr) && (i >= matrix->width - h))
// 		   //printf("\nkek%d\n",j);
//            printf("%.2f\t", data[i*h+j]);
//         printf("\n");
//     }
// 	//++pr;
//
// 	printf("\npr - %d,h - %d\n",pr,h);
//
// 	if ((w == h) && (h == 2))
// 	{
// 		printf("\nOpr 2x2 = %d\n",data[0]*data[3]-data[1]*data[2]);
// 		return data[0]*data[3]-data[1]*data[2];
// 	}
// 	else
// 	{
// 		for (i = 0; i < w; i++)
// 		{
// 			j = 0;
// 			*opr += pow((-1),i+j+2)*data[i*h+j]*det_raz(matrix,w-1,h-1,opr);
// 			printf("\n%d Cikl - %d\n",i,*opr);
// 			w = matrix->width+1;
// 			h = matrix->width+1;
// 			pr = i+1;
// 			printf("\n%d\n",*opr);
// 		}
// 	}
// 	puts("\n\n\n\n\n\n");
//
// }
//
//
//
