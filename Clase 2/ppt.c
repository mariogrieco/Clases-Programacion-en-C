#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"

	int turno;
	char jugador1[256];
	char jugador2[256];
	int w1 = 0;
	int w2 = 0;
	int option;
	int optionPlayer;
	char jugada[4][256] = { "", "Piedra","papel","tijeras" };


	void cualGano(int,int);

int main()
{

	srand(time(NULL));
	printf("Ingresa tu nomnbre: \n");
	gets(jugador2);

	while ( turno <= 3)
	{
		repetir:
	
		printf(" 1.- piedra\n 2.- papel\n 3.- Tijeras \n");
		printf("opcion: ");
		scanf("%i",&optionPlayer);

		while ( optionPlayer == 0 || optionPlayer > 3)
		{
			system("cls");
			goto repetir;
		}

		option = rand() % 4;

		while ( option >= 4 || option == 0 )
		{
			option = rand() % 4;			
		}

		turno++;
		cualGano(option,optionPlayer);
		printf("pc %i con %s\n",w1,jugada[option] );
		printf("%s %i con %s\n",jugador2,w2,jugada[optionPlayer] );
	}	
	if ( w1 > w2 )
	{
		printf("Gano la pc sorry :( \n");
	}
	else if ( w1 < w2 )
	{
		printf("%s ganaste! :) \n",jugador2 );
	}
	else
	{
		printf("empate :) \n");
	}


	system("PAUSE");
	return 0;
}

void cualGano(int a,int b)
{
	if ( b == 2 && a == 1 ) //  jugador 2 tiene papel
	{
		w2 += 1;
	}
	else if ( b == 2 && a == 2 )
	{
		printf("Tenemos un empate!\n");
		turno--;
	}
	else if ( b == 2 && a == 3 )
	{
		w1 += 1;
	}
	else if ( b == 1 && a == 1 ) // jugador 2 tiene piedra
	{
		printf("Tenemos un empate!\n");
		turno--;
	}
	else if ( b == 1 && a == 2 )
	{
		w1 += 1;
	}	
	else if ( b == 1 && a == 3 )
	{
		w2 += 1;
	}
	else if ( b == 3 && a == 3 ) //jugador2 tiene tijeras
	{
		printf("Tenemos un empate!\n");
		turno--;
	}
	else if ( b == 3 && a == 2 ) 
	{
		w2++;
	}
	else if ( b == 3 && a == 1 ) 
	{
		w1++;
	}



}
