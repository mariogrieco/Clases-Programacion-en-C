#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "myconio.h"

  void separar_int(int,int*,int);
  int largo_numero(int);
  void reverse_array(int *, int);

int main(void){

  int filas,columnas;
  int n1,n2,i,y,c,resultado;
  int **vec;
  int swapy1[4][4];
  int level4[4][4][2];

  puts("algoritmo de multiplicacion arabe\n");
  printf("Ingrese dos numeros a multiplicar Mayor que 99 y menor que 9999\n Numero 1: ");
  scanf("%i", &n1);
  while ( largo_numero(n1) != 3 && largo_numero(n1) != 4 ) {
    printf("Ingrese dos numeros a multiplicar Mayor que 99 y menor que 9999\n Numero 1: ");
    scanf("%i", &n1);
  }
  printf(" Numero 2: ");
  scanf("%i", &n2);
  while ( largo_numero(n2) != 3 && largo_numero(n2) != 4 ) {
    printf("Ingrese dos numeros a multiplicar Mayor que 99 y menor que 9999\n Numero 2: ");
    scanf("%i", &n2);
  }

  columnas = largo_numero(n2);
  filas = largo_numero(n1);

  vec = (int**)malloc(filas*sizeof(int*));
  for( i = 0 ; i < filas; ++i ){
      vec[i] = (int*)malloc(columnas*sizeof(int));
  }
  	int *array1,*array2;

  	array1 = (int*)malloc(largo_numero(n1)*sizeof(int));
  	array2 = (int*)malloc(largo_numero(n2)*sizeof(int));

	separar_int(n1,array1,largo_numero(n1));
	separar_int(n2,array2,largo_numero(n2));
	reverse_array(array1,largo_numero(n1));

	for ( y = 0; y < largo_numero(n1); y++)
	{
		for ( i = 0; i < largo_numero(n2); i++)
		{
			swapy1[y][i] = array1[y] * array2[i];
				
				if ( y == 0 )
				{
					separar_int(swapy1[y][i],level4[0][i],2);
				}
				if ( y == 1 ) 
				{
					separar_int(swapy1[y][i],level4[1][i],2);
				}
				if ( y == 2 )
				{
					separar_int(swapy1[y][i],level4[2][i],2);
				}
				if ( y == 3 )
				{
					separar_int(swapy1[y][i],level4[3][i],2);
				}
		}
	}

		if ( largo_numero(n1) == 3 && largo_numero(n2) == 3 )
		{
				int r1 = 0;
				int r2 = 0;
				int r3 = 0;
				int r4 = 0;
				int r5 = 0;
				int r6 = 0;
				int swap_1[2];

				r1 += level4[0][2][1];
				r2 += level4[0][2][0] + level4[0][1][1] + level4[1][2][1];
				if ( r2 > 9 )
				{
					separar_int(r2,swap_1,largo_numero(r2));
					r2 = swap_1[1];
					r3 += swap_1[0];
				}
				r3 += level4[0][0][1] + level4[0][1][0] + level4[1][1][1] + level4[1][2][0] + level4[2][2][1];
				if ( r3 > 9 )
				{
					separar_int(r3,swap_1,largo_numero(r3));
					r3 = swap_1[1];
					r4 += swap_1[0];
				}
				r4 += level4[0][0][0] + level4[1][0][1] + level4[1][1][0] + level4[2][1][1] + level4[2][2][0];
				if ( r4 > 9 )
				{
					separar_int(r4,swap_1,largo_numero(r4));
					r4 = swap_1[1];
					r5 += swap_1[0];
				}
				r5 += level4[1][0][0] + level4[2][0][1] + level4[2][1][0];
				if ( r5 > 9 )
				{
					separar_int(r5,swap_1,largo_numero(r5));
					r5 = swap_1[1];
					r6 += swap_1[0];
				}
				r6 += level4[2][0][0];

				printf("el resultado es : %d%d%d%d%d%d\n", r6,r5,r4,r3,r2,r1);
	}
	else if ( largo_numero(n1) == 4 && largo_numero(n2) == 4 )
	{
		int r1 = 0;
		int r2 = 0;
		int r3 = 0;
		int r4 = 0;
		int r5 = 0;
		int r6 = 0;
		int r7 = 0;
		int r8 = 0;
		int swap_1[2];

		r1 += level4[0][3][1];
		r2 += level4[0][2][1] + level4[0][3][0] + level4[1][3][1];
			if ( r2 > 9 )
				{
					separar_int(r2,swap_1,largo_numero(r2));
					r2 = swap_1[1];
					r3 += swap_1[0];
				}
		r3 += level4[0][1][1] + level4[0][2][0] + level4[1][2][1] + level4[1][3][0] + level4[2][3][1];
				if ( r3 > 9 )
				{
					separar_int(r3,swap_1,largo_numero(r3));
					r3 = swap_1[1];
					r4 += swap_1[0];
				}
		r4 += level4[0][0][1] + level4[0][1][0] + level4[1][1][1] + level4[1][2][0] + level4[2][2][1] + level4[2][3][0] + level4[3][3][1];
				if ( r4 > 9 )
				{
					separar_int(r4,swap_1,largo_numero(r4));
					r4 = swap_1[1];
					r5 += swap_1[0];
				}
		r5 += level4[0][0][0] + level4[1][0][1] + level4[1][1][0] + level4[2][1][1] + level4[2][2][0] + level4[3][2][1] + level4[3][3][0];
				if ( r5 > 9 )
				{
					separar_int(r5,swap_1,largo_numero(r5));
					r5 = swap_1[1];
					r6 += swap_1[0];
				}
		r6 += level4[1][0][0] + level4[2][0][1] + level4[2][1][0] + level4[3][1][1] + level4[3][2][0];
				if ( r6 > 9 )
				{
					separar_int(r6,swap_1,largo_numero(r6));
					r6 = swap_1[1];
					r7 += swap_1[0];
				}
		r7 += level4[2][0][0] + level4[3][0][1] + level4[3][1][0];
				if ( r7 > 9 )
				{
					separar_int(r7,swap_1,largo_numero(r7));
					r7 = swap_1[1];
					r8 += swap_1[0];
				}
		r8 += level4[3][0][0];

		printf("el resultado es : %d%d%d%d%d%d%d%d\n",r8,r7,r6,r5,r4,r3,r2,r1);


	}
	else if ( largo_numero(n1) == 3 && largo_numero(n2) == 4)
	{
		int r1 = 0;
		int r2 = 0;
		int r3 = 0;
		int r4 = 0;
		int r5 = 0;
		int r6 = 0;
		int r7 = 0;
		int swap_1[2];

		r1 += level4[0][3][1];
		r2 += level4[0][2][1] + level4[0][3][0] + level4[1][3][1];
				if ( r2 > 9 )
				{
					separar_int(r2,swap_1,largo_numero(r2));
					r2 = swap_1[1];
					r3 += swap_1[0];
				}
		r3 += level4[0][1][1] + level4[0][2][0] + level4[1][2][1] + level4[1][3][0] + level4[2][3][1];
				if ( r3 > 9 )
				{
					separar_int(r3,swap_1,largo_numero(r3));
					r3 = swap_1[1];
					r4 += swap_1[0];
				}
		r4 += level4[0][0][1] + level4[0][0][0] + level4[1][1][1] + level4[1][2][0] + level4[2][2][1] + level4[2][3][0];
					if ( r4 > 9 )
				{
					separar_int(r4,swap_1,largo_numero(r4));
					r4 = swap_1[1];
					r5 += swap_1[0];
				}
		r5 += level4[0][0][0] + level4[1][0][1] + level4[1][1][0] + level4[2][1][1] + level4[2][2][0];
				if ( r5 > 9 )
				{
					separar_int(r5,swap_1,largo_numero(r5));
					r5 = swap_1[1];
					r6 += swap_1[0];
				}
		r6 += level4[1][0][0] + level4[2][0][1] + level4[2][1][0];
				if ( r6 > 9 )
				{
					separar_int(r6,swap_1,largo_numero(r6));
					r6 = swap_1[1];
					r7 += swap_1[0];
				}
		r7 += level4[2][0][0];

		printf("el resultado es : %d%d%d%d%d%d%d\n",r7,r6,r5,r4,r3,r2,r1);

	}
	else if ( largo_numero(n1) == 4 && largo_numero(n2) == 3 )
	{
		int r1 = 0;
		int r2 = 0;
		int r3 = 0;
		int r4 = 0;
		int r5 = 0;
		int r6 = 0;
		int r7 = 0;
		int r8 = 0;
		int swap_1[2];

		r1 += level4[0][2][1];

		r2 += level4[0][1][1] + level4[0][2][0] + level4[1][2][1];
				if ( r2 > 9 )
				{
					separar_int(r2,swap_1,largo_numero(r2));
					r2 = swap_1[1];
					r3 += swap_1[0];
				}
		r3 += level4[0][0][1] + level4[0][1][0] + level4[1][1][1] + level4[1][2][0] + level4[2][2][1];
			if ( r3 > 9 )
				{
					separar_int(r3,swap_1,largo_numero(r3));
					r3 = swap_1[1];
					r4 += swap_1[0];
				}
		r4 += level4[0][0][0] + level4[1][0][1] + level4[1][1][0] + level4[2][1][1] + level4[2][2][0] + level4[3][2][1];
						if ( r4 > 9 )
				{
					separar_int(r4,swap_1,largo_numero(r4));
					r4 = swap_1[1];
					r5 += swap_1[0];
				}
		r5 += level4[1][0][0] + level4[2][0][1] + level4[2][1][0] + level4[3][1][1] + level4[3][2][0];
				if ( r5 > 9 )
				{
					separar_int(r5,swap_1,largo_numero(r5));
					r5 = swap_1[1];
					r6 += swap_1[0];
				}
		r6 += level4[2][0][0] + level4[3][0][1] + level4[3][1][0];
					if ( r6 > 9 )
				{
					separar_int(r6,swap_1,largo_numero(r6));
					r6 = swap_1[1];
					r7 += swap_1[0];
				}
		r7 += level4[3][0][0];

		printf("el resultado es : %d%d%d%d%d%d%d\n",r7,r6,r5,r4,r3,r2,r1);
	}

	system("PAUSE");
  return 0;

}

int largo_numero(int numero){
    if ( numero >= 99 && numero <= 999 ) {
        return 3;
    }
    else if ( numero >= 999 && numero <= 9999 ) {
        return 4;
    }
    else if ( numero <= 9 )
    {
    	return 1;
    }
    else if (numero >= 9 && numero <= 99) {
    	return 2;
    }
    else
    {
      return 0;
    }

}

void separar_int(int numero,int *array,int largo){

    int i;
    int *swap;

    if ( largo == 1 )
    {
    	swap = (int*)malloc(2*sizeof(int));
    	 swap[1] = 0;
      	 swap[0] = numero;
      	array[0] = swap[1];
      	array[1] = swap[0];
    }
    else
    {
    	swap = (int*)malloc(largo*sizeof(int));

      if ( largo == 3 ) {
          swap[2] = (int)numero % 10;
          swap[1] = (int)numero % 100 / 10;
          swap[0] = (int)numero % 1000 / 100;
      }
      else if ( largo == 4) {
          swap[3] = (int)numero % 10;
          swap[2] = (int)numero % 100 / 10;
          swap[1] = (int)numero % 1000 / 100;
          swap[0] = (int)numero % 10000 / 1000;
      }
      else if ( largo == 2) {
      	  swap[1] = (int)numero % 10;
          swap[0] = (int)numero % 100 / 10;
      }
       for ( i = 0; i < largo; ++i){
          array[i] = swap[i];
      }

    }
}
void reverse_array(int *array, int largo){

	int i;
	int swap;
  	for ( i = 0; i < largo-2; i++)
  	{
  		swap = array[i];
  		array[i] = array[(largo-1)-i];
  		array[(largo-1)-i] = swap;
  	}

}