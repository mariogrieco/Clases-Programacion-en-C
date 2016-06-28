#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

	int suma(int*);

int main(int argc, char *argv[] )
{

	int numeros[3] = { 1,2,3 };
	int i;

	for ( i = 0; i < sizeof(numeros)/sizeof(numeros[0]); ++i)
	{
		printf("%i \n", numeros[i]);
	}

	return 0;
}