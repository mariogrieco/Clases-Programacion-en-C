#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "myconio.h"


int main(int argc, char const *argv[])
{
	int i;
	int swap;
	
	int array[] = { 1,2,3,4 };
	int arrayImpar[] = { 1,2,3,4,5 };



	for ( i = 0; i < 4; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");

	/* Codigo para par */
	for ( i = 0; i < 4/2; i++)
	{
		swap = array[i];
		array[i] = array[(4-1)-i];
		array[(4-1)-i] = swap;

	}

	for ( i = 0; i < 4; i++)
	{
		printf("%i ", array[i]);
	}
	printf("\n");

	/* Codigo para impar */
	for ( i = 0; i < 5; i++)
	{
		printf("%i ", arrayImpar[i]);
		
	}

	printf("\n");

	for ( i = 0; i < ((5-1)/2); i++)
	{
		swap = arrayImpar[i];
		arrayImpar[i] = arrayImpar[(5-1)-i];
		arrayImpar[(5-1)-i] = swap;

	}

	for ( i = 0; i < 5; i++)
	{
		printf("%i ", arrayImpar[i]);
	}
	printf("\n");




	system("PAUSE");
	return 0;
}