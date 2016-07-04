#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "myconio.h"


int main()
{
	int f,c,x,i;
	int swap;

	int array[][5] = {  { 5,4,3,2,1 },
						{ 5,4,3,2,1 },
						{ 5,4,3,2,1 },
						{ 5,4,3,2,1 },
						{ 5,4,3,2,1 }
					 };

	for( f = 0; f < 5; f++)
	{
		for( c = 0; c < 5; c++)
	 	{
	 	    printf("%i ", array[f][c]);
	 	}
	 	printf("\n");
	}
	printf("\n\n\n\n\n");
	/* Codigo de arreglo */
	for( f = 0; f < 5; f++)
	{
		for( c = 0; c < 5; c++)
	 	{
	 	   for ( i = 0; i < 5; i++)
	 	   {
		 	    for ( x = 0; x < 5; x++)
	 	  		{
	 	  			if ( array[f][c] > array[i][x] )
	 	  			{
	 	  				swap = array[i][x];
	 					array[i][x] = array[f][c];
	 					array[f][c] = swap;
	 	 			}
	 	   		}
	 	   }
	 	}
	}

	for( f = 0; f < 5; f++)
	{
		for( c = 0; c < 5; c++)
	 	{
	 	    printf("%i ", array[f][c]);
	 	}
	 	printf("\n");
	}


	return 0;
}