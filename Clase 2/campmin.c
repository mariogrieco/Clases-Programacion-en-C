#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"

	void initRand();


	int minas;
	int noMina;
	int f,c,i;
	int campo[10][10];


int main()
{

	initRand();	

	for ( f = 0; f < 10; f++)
	{
		for ( c = 0; c < 10; c++)
		{
			campo[f][c] = rand() % 2;
			if ( campo[f][c] == 1 )
			{
				minas++;
			}
			else
			{
				noMina++;
			}
		}
	}
	
	ref1:
	printf("\n\n\n\n");
	for ( f = 0; f < 10; f++)
	{
		for ( c = 0; c < 10; c++)
		{
			if ( campo[f][c] == 9 )
			{
				//printf("%i ", campo[f][c] );
				printf(" O ");
			}
			else
			{
				//printf("%i ", campo[f][c] );
				printf(" X ");
			}
		}
		printf("\n");
	}
	printf("Dificultad: %i\n Espacio en blanco: %i\n\n", minas,noMina);

	printf("ingresa en filas y columnas donde quieres pararte?.. \n");
	printf("filas: ");
	scanf("%i",&f);
	printf("columnas: ");
	scanf("%i",&c);

		while ( f >= 10 || c >= 10 )
		{
			printf("\n");
			printf("Ingresa una opcion menor a 3 para las filas y las columnas\n");
			printf("ingresa en filas y columnas donde quieres pararte?.. \n");
			printf("filas: ");
			scanf("%i",&f);
			printf("columnas: ");
			scanf("%i",&c);
		}

	if ( campo[f][c] == 1 )
	{
		printf("Moriste sorry :( \n");
	}
	else if ( campo[f][c] == 0 )
	{
		campo[f][c] = 9;
		noMina--;
		goto ref1;
	}
	else if ( campo[f][c] == 9 )
	{
		printf("Usted ya ingreso ese lugar en filas y columnas\n");
		goto ref1;
	}
	else if ( noMina == 0 )
	{
		printf("Tu ganaste! \n");
		system("PAUSE");
	}
		
	return 0;

}

void initRand(){
	srand(time(NULL));
}
