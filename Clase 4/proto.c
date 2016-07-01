#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "myconio.h"

	
		struct Jugador
		{
			int x;
			int y;
			char forma;
		};

		char option;

	void instantiate(int,int);

int main()
{
	
	struct Jugador nave;
	nave.x = 20;
	nave.y = 10;

	nave.forma = '>';
	system("cls");

	while( 1 == 1)
	{
		option = getch();

		if ( option == 'q' )
		{
			return 0;
		}
		if ( option == 'd' )
		{
				gotoxy(nave.x,nave.y);
				printf(">");

			instantiate(nave.x,nave.y);
		}
	}

	return 0;
}

void instantiate(int o,int p){
	int i;

	system("cls");

	gotoxy(o,p);
	for ( i = 2; i < 5; ++i)
	{
		Sleep(220);
		gotoxy(o+i,p);
		printf("-");
		Sleep(100);
		printf(" ");
	}
}