#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"


int main()
{	
 	int i[] = { 1,2,3,4,5,6 };
 	int x;

 	for ( x = 0; x < sizeof(i)/sizeof(int); x++)
 	{
 		printf("%i \n", i[x]);
 	}
	system("PAUSE");
	return 0;
}

