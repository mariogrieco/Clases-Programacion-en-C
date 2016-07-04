#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "myconio.h"


int main()
{
	int i,X;
	int array[] = { 1,2,3,4,5 };
	int swap;

	for ( i = 0; i < 5; i++ )
	{
		printf("%i ", array[i]);
	}
	printf("\n");
	/*	
	FORMA NUMERO 1
	ref1:
	for ( i = 0; i < 5-1; i++ )
	{
		if ( array[i] < array[i+1] )
		{
			swap = array[i];
			array[i] = array[i+1];
			array[i+1] = swap;	
		}
	}

	for ( i = 0; i < 5-1; i++ )
	{
		if ( array[i] > array[i+1] )
		{
			goto ref1;	
		}
	}
	*/
	/* fORMA NUMERO 2 */
	for ( X = 0; X < 5; X++ )
	{
		for ( i = 0; i < 5-1; i++ )
		{
			if ( array[i] < array[i+1] )
			{
				swap = array[i];
				array[i] = array[i+1];
				array[i+1] = swap;	
			}
		}
	}
	for ( i = 0; i < 5; i++ )
	{
		printf("%i ", array[i]);
	}
	printf("\n");

	return 0;
}