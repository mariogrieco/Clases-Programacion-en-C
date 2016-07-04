#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "myconio.h"

	int **sopa;
	int **Bandera;

	int *p;

	int filas,columnas;
	int f,c,i,x;
	int paraBuscar;

			void setMNumbers(int**,int,int);
			void printM(int**,int,int);
			int lengthOfNumber(int);
			void splitNumber(int,int);
			void searchH(int**,int);
			int cualEsMenor(int,int);
			void invertirNumber(int);
			void searchV(int** m,int largo);
			void searchDizqdere(int** m,int largo);

int main(int argc, char const *argv[])
{
	
	/* code */
	srand(time(NULL));

	printf("Ingresa la cantidad de filas: ");
	scanf("%i",&filas);

	printf("Ingresa la cantidad de columnas: ");
	scanf("%i",&columnas);

	sopa = (int**)malloc(filas*(sizeof(int*)));
	Bandera = (int**)malloc(filas*(sizeof(int*)));

	for ( i = 0; i < filas; i++ )
	{
		sopa[i] = (int*)malloc(columnas*(sizeof(int)));
		Bandera[i] = (int*)malloc(columnas*(sizeof(int)));
	}

	setMNumbers(sopa,filas,columnas);
		
		
	ref1:
		/* Inicializar bandera en 0 y 1*/
	for ( f = 0; f < filas; f++)
	{
		for ( c = 0; c < columnas; c++)
		{
			Bandera[f][c] = 0;
		}
	}

	printM(sopa,filas,columnas);


	printf("Ingresa el numero a buscar en entero que sea menor o igual %i: ",cualEsMenor(filas,columnas));
	scanf("%i",&paraBuscar);


	while ( lengthOfNumber(paraBuscar) > cualEsMenor(filas,columnas) ){
		printf("\n\n\n");
		printf("Tu numero no sigue los parametro pre-establecidos porfavor siga las instrucciones\n");
		printf("Ingresa el numero a buscar en entero que sea menor o igual %i: ",cualEsMenor(filas,columnas));
		scanf("%i",&paraBuscar);
	}

	//printf("el largo del numero es de %i \n", lengthOfNumber(paraBuscar));

	/* IMPORTANTE PARA QUE FUNCIONE EL CODIGO  */
	splitNumber(lengthOfNumber(paraBuscar),paraBuscar);
	
	/* Busqueda horizontal izq dere y dere izq */
	searchH(sopa, lengthOfNumber(paraBuscar));
	invertirNumber(lengthOfNumber(paraBuscar));
	searchH(sopa, lengthOfNumber(paraBuscar));
	invertirNumber(lengthOfNumber(paraBuscar));

	/* Busqueda vertical arriba abajo y abajo arriba */
	searchV(sopa, lengthOfNumber(paraBuscar));
	invertirNumber(lengthOfNumber(paraBuscar));
	searchV(sopa, lengthOfNumber(paraBuscar));
	invertirNumber(lengthOfNumber(paraBuscar));

	/* Busquedas diagonales */
	searchDizqdere(sopa, lengthOfNumber(paraBuscar));
	invertirNumber(lengthOfNumber(paraBuscar));
	searchDizqdere(sopa, lengthOfNumber(paraBuscar));
	invertirNumber(lengthOfNumber(paraBuscar));



	printf("\n\n\n");
	printM(sopa,filas,columnas);

	
	goto ref1;

	system("PAUSE");
	return 0;
} 	

void setMNumbers(int** m,int filas,int columnas){

	for ( f = 0; f < filas; f++)
	{
		for ( c = 0; c < columnas; c++)
		{
			m[f][c] = rand()%10;
		}
	}
}

void printM(int** m,int filas,int columnas){
	printf("\n\n\n");
	for ( f = 0; f < filas; f++)
	{
		for ( c = 0; c < columnas; c++)
		{
				
			if ( Bandera[f][c] == 0 )
			{
				printf("%i ", m[f][c]);
			}
			else
			{
				textcolor(RED);
				printf("%i ", m[f][c]);
				textcolor(WHITE);	
			}
		}
		printf("\n");
	}

}
 
 int lengthOfNumber(int a){

 	if ( a < 10 )
 	{
 		return 1;
 	}
 	else if ( a >= 10 && a <= 99 )
 	{
 		return 2;
 	}
 	else if ( a > 99 && a <= 999 )
 	{
 		return 3;
 	}
 	else if ( a > 999 && a <= 9999 )
 	{
 		return 4;
 	}

 }

 void splitNumber(int b,int c){

 	p = (int*)malloc((lengthOfNumber(paraBuscar)+1)*sizeof(int));

 	if ( b == 1 ) 
 	{
 		p[0] = (int)c;
 
 	}
 	else if ( b == 2 )
 	{
 		p[0] = (int)c/10;
 		p[1] = (int)c%10;
 	}
 	else if ( b == 3 )
 	{	
 		p[0] = (int)c/100;
		p[1] = (int)c%100/10;
		p[2] = (int)c%10;
 	}
 	else if ( b == 4 )
 	{
 		p[0] = (int)c/1000;
		p[1] = (int)c%1000/100;
		p[2] = (int)c%100/10;
		p[3] = (int)c%10;
	}

 }

 int cualEsMenor(int a,int b){
 	if ( a < b )
 	{
 		return a;
 	}
 	else
 	{
 		return b;
 	}
 }

 void searchH(int** m,int largo){

 	int contador = 0;
 	int posI[2] = { 0,0 };
 	int posF[2] = { 0,0 };
 	int pp = 0;

 	for ( f = 0; f < filas; f++ )
 	{
 		for ( c = 0; c < (columnas-(largo-1)); c++)
 		{
 			contador = 0;
 			for ( i = 0; i < largo; ++i)
 				{
 					if ( m[f][c+i] == p[i] )
 					{
 						if ( contador == 0 )
 						{
 							posI[0] = f;
 							posI[1] = c+i;
 							pp = posI[1]; 
 						}
 						else{
 							posF[0] = f;
 							posF[1] = c+i;
 						}
 						contador++;
 					}
 					else
 					{
 						contador = 0;
 					}
 					if ( contador == largo )
 					{
 						while( pp <= posF[1] )
 						{
 							Bandera[posI[0]][pp] = 1;
 							pp++;
 						}
 					}
 				}	
 		}
 	}

 }

  void searchV(int** m,int largo){

 	int contador = 0;
 	int posI[2] = { 0,0 };
 	int posF[2] = { 0,0 };
 	int pp = 0;

 	for ( c = 0; c < columnas; c++)
 	{
 		for ( f = 0; f < (filas-(largo-1)); f++ )
 		{
 			//printf("%i ", m[f][c]);
 			contador = 0;
 			for ( i = 0; i < largo; ++i)
 			{
 				if ( m[f+i][c] == p[i] )
 				{
 					if ( contador == 0 )
 					{
 						   posI[0] = f+i;
 						   posI[1] = c;
 						   pp = posI[0]; 
 					}	
 					else{
 							posF[0] = f+i;
 							posF[1] = c;
 						}
 					contador++;
 				}
 				else
 				{
 					contador = 0;
 				}
 				if ( contador == largo )
 				{
 						while( pp <= posF[0] )
 						{
 							Bandera[pp][posI[1]] = 1;
 							pp++;
 						}
 				}
 			}
 		}
 		printf("\n");
 	}
 }

 void invertirNumber(int largo){
 	int swap;

 	if ( largo%2 == 0)
 	{
 		for ( i = 0; i < largo/2; i++)
 		{
 			swap = p[i];
 			p[i] = p[((largo-1)-i)];
 			p[((largo-1)-i)] = swap;
 		}
 	}
 	else
 	{
 		for ( i = 0; i < ((largo-1)/2); i++)
 		{
 			swap = p[i];
 			p[i] = p[((largo-1)-i)];
 			p[((largo-1)-i)] = swap;
 		}
 	}
 }

void searchDizqdere(int** m,int largo){
	
	int contador = 0;
 	int posI[2] = { 0,0 };
 	int posF[2] = { 0,0 };
 	f = 0;
 	c = 0;
 	int pp = 0;

 	for ( i = 0; i < filas; i++)
 	{
 		for ( x = 0; x < columnas; x++)
 		{
 			f = i;
 			c = x;
 			while( i < filas && x < columnas )
 			{

 				if ( p[contador] == m[i][x] )
 				{
 					if ( contador == 0 )
 					{
 						posI[0] = i;
 						posI[1] = x;
 					}
 					if ( contador == largo-1 )
 					{
 						posF[0] = i;
 						posF[1] = x;
 						//printf("numero encontrado en f:%i c:%i hasta f:%i c:%i \n",posI[0],posI[1],posF[0],posF[1] );
 						while ( posI[0] <= (posF[0]+1) && posI[1] < (posF[1]+1) ){
 							Bandera[posI[0]][posI[1]] = 1;
 							posI[0] += 1;
 							posI[1] += 1;
 						}
 					
 					}
 					contador++;
 				}
 				else
 				{
 					contador = 0;
 					i = 999999;
 					x = 999999;
 				}
 				i++;
 				x++;
 			}
 			i = f;
 			x = c;
 			contador = 0;
 		}
 	}

}