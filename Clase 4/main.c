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

		struct Jugador player;
		struct Jugador contador;
		int campo[20][20] = {
								{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
								{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
								{ 1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
								{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
								{ 1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1 },
								{ 1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,1 },
								{ 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
								{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
								{ 1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 },
								{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1 },
								{ 1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1 },
								{ 1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1 },
								{ 1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,1 },
								{ 1,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1 },
								{ 1,1,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1 },
								{ 1,1,1,1,0,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1 },
								{ 1,1,1,1,1,0,0,1,0,1,0,1,0,1,1,0,0,0,0,1 },
								{ 1,1,1,1,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1 },
								{ 1,1,1,1,1,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1 },
								{ 1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,1,1,1,1,1 },
							};


		void mprint(int[][20],int,int);
		void deletePlayer(void);
		void printPlayer(int x, int y);

int main()
{
		
		player.x = 0;
		player.y = 1;
		player.forma = 'X';
		contador.x = 0;
		contador.y = 1;

	system("cls");
	textbgcolor(WHITE,BLACK);
	mprint(campo,20,20);

	gotoxy(player.x,player.y);
	printf("%c",player.forma);
		
	while( 1 == 1 ){
			option = getch();
			
			if ( option == 'q' )
			{
				return 0;
			}
			if ( option == 100 /*100 == d*/ )
			{
			
				if ( campo[contador.y][contador.x+1] == 0 && ( contador.x+1 < 20))
				{
					contador.x += 1;
					deletePlayer();
					printPlayer(+2,0);
					if ( campo[contador.y][contador.x+1] == 9 )
					{
						system("cls");
						printf("you win! :)");
					}
				}
			}
			if ( option == 'a' /*100 == d*/ )
			{
			
				if ( campo[contador.y][contador.x-1] == 0 && ( contador.x+1 >= 0))
				{
					contador.x -= 1;
					deletePlayer();
					printPlayer(-2,0);
					if ( campo[contador.y][contador.x-1] == 9 )
					{
						system("cls");
						printf("you win! :)");
					}
				}
			}
			if ( option == 'w' )
			{
				if ( campo[contador.y-1][contador.x] == 0 && contador.y-1 >= 0 )
				{
					contador.y -= 1;
					deletePlayer();
					printPlayer(0,-1);
					if ( campo[contador.y-1][contador.x] == 9 )
					{
						system("cls");
						printf("you win! :)");
					}
				}
			}
			if ( option == 's' )
			{
				if ( campo[contador.y+1][contador.x] == 0 && contador.y+1 < 20 )
				{
					contador.y += 1;
					deletePlayer();
					printPlayer(0,+1);
					if ( campo[contador.y+1][contador.x] == 9 )
					{
						system("cls");
						printf("you win! :)");
					}
				}

			}
	}
}

void mprint(int campo[][20],int f,int c ){
	int i,x;

	textbgcolor(WHITE,BLACK);
	for ( i = 0; i < 20; i++)
	{
		for ( x = 0; x < 20; x++)
		{
			if (campo[i][x] == 0 || campo[i][x] == 9 )
			{
				textbgcolor(BLACK,BLACK);
				printf("%i ",campo[i][x]);
			}
			else
			{
				textbgcolor(1,1);
				printf("%i ",campo[i][x]);
			}
		}
		printf("\n");
	}
	textbgcolor(WHITE,BLACK);
}

void deletePlayer(void){
		gotoxy(player.x,player.y);
		textbgcolor(WHITE,BLACK);
		printf("  ");

}

void printPlayer(int x, int y){
    
    player.y += y;
    player.x += x;
    textbgcolor(GREEN,GREEN);
	gotoxy(player.x,player.y);
	printf("  ");

	textbgcolor(WHITE,BLACK);
}