#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "conio.h"
#include "string.h"

 #define max_len_size 40

	// la vieja 

	char tablero[3][3][max_len_size] = { 
											{"-", "-", "-"},
											{"-", "-", "-"},
											{"-", "-", "-"},
										};


		//Prototypes
					void imprimir_tablero(void);
					int validar_jugada(int,int);

	// nombres random  para el pc
	char nombres_random[34][max_len_size] = {    "Pancracia","Vergassola","Elano","Teofilo","Rosamelano","Marica","Karamoko","Manolo","LolaMento","BailaSola","JonyMelavo",
												 "Proculo","Elvisteck","Alambrito","clitoris","Cornelio","Patrocinio", "Cayetano","Marta","Anastasio","Selomea","Manuela",
												 "Herculano","Petronila","Anacleto","Hipolito","Vergoglio","Alexcremento","Erfundillo","Agapita","Romina","Mariconsuelo","Panfilo","Penelope",
	};

	char nombre_user1[max_len_size];
	char nombre_user2[max_len_size];

int main()
{
	/* code */
	int mode;
	int nombre_random;
	nombre_random = rand()%34;

		// 1 y 2
	srand(time(NULL));
	puts("bienvenido al juego de la vieja en c!!!\n ingrese un modo de juego\n \t 1] User vs PC \n \t 2] User vs User");
	printf("\nIngrese una opcion valida: ");`
	scanf("%d",&mode);

	switch(mode){
		case 1:
			printf("\n Ingrese nombre de usuario: ");
			fflush(stdin);
			gets(nombre_user1);
			printf("%s vs %s \n",nombre_user1, nombres_random[nombre_random] );
			break;
		case 2: 
			

			break;
		default:
			system("cls");
			return main();
			break;
	}

	return 0;
}

void imprimir_tablero(){

	int i = 0;	
	int x = 0;


	puts("La vieja\n tablero \n ");

		for ( i = 0; i < 3; ++i)
		{
			printf("\t");
			for ( x = 0; x < 3; ++x)
			{
				printf("%c ",tablero[i][x] );	
			}
			printf(" \n");
		}


}

int validar_jugada(int x,int y){

	int pos;
	pos = strcmp( tablero[x][y], "-");

	if ( pos != 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}


	
/*
	// Functions Prototypes
		void main_calculadora(int);
		double sumar(int *);
		double restar(void);
		double multiplicar(void);
		double modulo(void);

		char options[4][120] = {"sumar","restar","multiplicar","modulo"};

int main(){

	int option;

	puts("calculadora cientifica");
	printf(" 1] Sumar\n 2] Restar\n 3] Multiplicar\n 4] Modulo\n");
	printf("Ingrese un numero par 1/3: ");
	scanf( "%d",&option);

	switch(option){
		case 1:
			main_calculadora(option);
			break;
		case 2:
			main_calculadora(option);
			break;
		case 3: 
			main_calculadora(option);
			break;
		case 4: 
			main_calculadora(option);
			break;
		default:
			system("CLS");
			return main();
			break;
	};

	system("PAUSE");
	return 0;
}	

void main_calculadora(int option){
	int len_numeros = -10;
	len_numeros = strcmp(options[option-1],options[3]);
	
	if (  len_numeros == 0 )
	{
		modulo();
	}
	else{
		printf("cuantos numeros deceas %s: ", options[option-1]);
		scanf("%d", &len_numeros);

		int *arrays_of_elements;

			arrays_of_elements = (int*)malloc(sizeof(int)*len_numeros);


			
	}


}

double sumar(int *large){

}

double restar(){

}

double multiplicar(){

}

double modulo(){

		int num = 4;
		int tamao;
		int *direc;

		tamao = sizeof(int);
		direc = &num;
		scanf("%d",direc);
			
		printf("tamano %d y direccion %p de %d\n", tamao, direc,num);

}*/