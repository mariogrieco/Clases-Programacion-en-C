#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "myconio.h"

		/* Prototypes */
		void defaultColor(void);
		void mprint(int, int);
		void moveJugador(int, int);
		void deleteJugador(void);

		int campo[20][20] = { 
								{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
								{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
								{ 1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1 },
								{ 1,0,1,0,0,0,3,0,0,1,0,0,0,3,0,0,0,0,0,1 },
								{ 1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1 },
								{ 1,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1,0,1 },
								{ 1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,1,1,1,0,1 },
								{ 1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1 },
								{ 1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1 },
								{ 1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1 },
								{ 1,0,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1 },
								{ 1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,0,1 },
								{ 1,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1 },
								{ 1,3,1,3,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1 },
								{ 1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1 },
								{ 1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1,1,0,1 },
								{ 1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,0,1 },
								{ 1,0,1,1,0,1,1,3,1,3,1,1,1,1,3,1,1,1,0,1 },
								{ 1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
								{ 1,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
							};
		char option;

		struct Player
		{
			int filas;
			int columnas;
			char cuerpo;
		};

		struct Player jugador;
		struct Player helper;


int main()
{		
	system("cls");
		jugador.filas = 1;
		jugador.columnas = 0;
		jugador.cuerpo = 'x';

		helper.filas = 1;
		helper.columnas = 0;

		mprint(20,20);
	
		while ( 1 == 1 )
		{
			moveJugador(0,0);
			option = getch();

			if (  option == 113 /* es igual 'q' */	)
			{
				return 0;
			}
			if ( option == 'd' )
			{
				if ( campo[helper.filas][helper.columnas+1] == 0 && helper.columnas < 20 )
				{
					helper.columnas += 1;
					deleteJugador();
					moveJugador(+2,0);
				}
				if ( campo[helper.filas][helper.columnas+1] == 9	)
				{
					printf("(YOU WIN! XD)!");
				}
				if (campo[helper.filas][helper.columnas+1]  == 3)
				{
					printf("BOOM! eso era una mina you lose sorry xD\n");
				}
			}
			if ( option == 'a' )
			{
				if ( campo[helper.filas][helper.columnas-1] == 0 && helper.columnas >= 0 )
				{
					helper.columnas -= 1;
					deleteJugador();
					moveJugador(-2,0);
				}
				if ( campo[helper.filas][helper.columnas-1] == 9	)
				{
					printf("(YOU WIN! XD)!");
				}
				if (campo[helper.filas][helper.columnas-1]  == 3)
				{
					printf("BOOM! eso era una mina you lose sorry xD\n");
				}
			}
			if ( option == 'w' )
			{
				if ( campo[helper.filas-1][helper.columnas] == 0 && helper.filas >= 0 )
				{
					helper.filas -= 1;
					deleteJugador();
					moveJugador(0,-1);
				}
				if ( campo[helper.filas-1][helper.columnas] == 9	)
				{
					printf("(YOU WIN! XD)!");
				}
				if (campo[helper.filas-1][helper.columnas] == 3)
				{
					printf("BOOM! eso era una mina you lose sorry xD\n");
				}
			}
			if ( option == 's' )
			{
				if ( campo[helper.filas+1][helper.columnas] == 0 && helper.filas < 20 )
				{
					helper.filas += 1;
					deleteJugador();
					moveJugador(0,+1);
				}
				if ( campo[helper.filas+1][helper.columnas] == 9	)
				{
					printf("(YOU WIN! XD)!");
				}
				if (campo[helper.filas+1][helper.columnas] == 3)
				{
					printf("BOOM! eso era una mina you lose sorry xD\n");
				}
			}

		}
}

void defaultColor(void){
	textbgcolor(WHITE,BLACK);
}

void mprint(int f, int c){
	int x,i;

	defaultColor();
	for ( x = 0; x < f; x++)
	{
		for ( i = 0; i < c; i++)
		{
			if ( campo[x][i] == 0 || campo[x][i] == 9 )
			{
				/* print caminos */
				textbgcolor(BLACK,BLACK);
				printf("%i ",campo[x][i]);
			}
			else if ( campo[x][i] == 1 )
			{
				/* print pare */
				textbgcolor(BLUE,BLUE);
				printf("%i ",campo[x][i]);
			}	
			else if ( campo[x][i] == 3 )
			{
				/* print mina */
				textbgcolor(GRAY,GRAY);
				printf("%i ",campo[x][i]);
			}	
		}
			printf("\n");
	}
	defaultColor();

}

void moveJugador(int x, int y){

	jugador.filas += y;
	jugador.columnas += x;

	textbgcolor(GREEN,GREEN);
	gotoxy(jugador.columnas,jugador.filas);
	printf("%c ",jugador.cuerpo);
	defaultColor();
}
void deleteJugador(void){
	gotoxy(jugador.columnas,jugador.filas);
	defaultColor();
	printf("  ");
}