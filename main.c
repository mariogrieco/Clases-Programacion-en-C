#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "time.h"
#include "conio.h"
#include "math.h"
#include "myconio.h"

//comentarios


int filas,columnas;
int **m;
int *number_arreglado;
int number;

/* para los for */
int f,c,i,x;

	void init_rand(void);
	int tamano_minimo_matriz(int,int);
	int inicializar_matriz(int**);
	void m_print(int**);
	int length(int);
	void arreglar_number();

int main(int argc, char const *argv[]) {

 	init_rand();

 	printf("Ingresa la cantidad de filas para la matriz: ");
 	scanf("%i",&filas);

 	printf("Ingresa la cantidad de columnas para la matriz: ");
 	scanf("%i",&columnas);

 	ref1:
 	printf("Ingresa el numero a buscar debe ser menor a %i: ",tamano_minimo_matriz(filas,columnas));
 	scanf("%i",&number);
 	if ( length(number) > tamano_minimo_matriz(filas,columnas) )
 	{
 		goto ref1;
 	}

 	arreglar_number();

 	// Crear matriz 

 		m = (int**)malloc(filas*sizeof(int*));

	for ( i = 0; i < filas; i++)
	{
		m[i] = (int*)malloc(columnas*sizeof(int*));
	}
	//end

 	inicializar_matriz(m);
 	m_print(m);

 	// magia 
 	// buscar izq dere
 	// buscar dere izq
 	// buscar arriba abako
 	// buscar abako arriba
 	// diagonal 





}

void init_rand(void){
	srand(time(NULL));
}

int tamano_minimo_matriz(int a, int b){
	if ( a > b )
	{
		return b;
	}
	else
	{
		return a;
	}
}

int inicializar_matriz(int** m){

	for ( i = 0; i < filas; i++)
	{
		for ( x = 0; x < columnas; x++)
		{
			m[i][x] = rand()%10;
		}
	}

}

void m_print(int** m){
	for ( i = 0; i < filas; i++)
	{
		for ( x = 0; x < columnas; x++)
		{
			printf("%i ",m[i][x] );
		}
		printf("\n");
	}
}

int length(int a){
	
	if ( a > 9 && a < 99 )
	{
		return 2;
	}
	else if ( a > 99 && a < 999 )
	{
		return 3;
	}
	else if ( a > 999 && a < 9999 )
	{
		return 4;
	}
	else if ( a > 9999 )
	{
		return 5;
	}
	else if ( a <= 9)
	{
		return 1;
	}

}

void arreglar_number(){

	number_arreglado = (int*)malloc(length(number)*sizeof(int));
	
	if ( length(number) == 1 )
	{
		number_arreglado[0] = number;
	}
	else if ( length(number) == 2 )
	{
		number_arreglado[0] = (int)number/10;
		number_arreglado[1] = (int)number%10;
	}
	else if ( length(number) == 3 )
	{
		number_arreglado[0] = (int)number/100;
		number_arreglado[1] = (int)number%100/10;
		number_arreglado[2] = (int)number%10;

	}
	else if ( length(number) == 4 )
	{
		number_arreglado[0] = (int)number/1000;
		number_arreglado[1] = (int)number%1000/100;
		number_arreglado[2] = (int)number%100/10;
		number_arreglado[3] = (int)number%10;
	}
	else if ( length(number) == 5 )
	{
		number_arreglado[0] = (int)number/10000;
		number_arreglado[1] = (int)number%10000/1000;
		number_arreglado[2] = (int)number%1000/100;
		number_arreglado[3] = (int)number%100/10;
		number_arreglado[4] = (int)number%10;
	}
}