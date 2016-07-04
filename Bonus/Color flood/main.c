#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "myconio.h"

#define default_text 7
#define default_background 10

int **tablero,**llave;

      int option;
      int menu_option;
      int jugada = 0;
      int cantidad_de_pasos = 0;

      int generar_tablero(int,int,int**);
      int imprimir_tablero(int,int,int**);
      int init_rand(void);
      int cambiar_paletas(int,int,int **,int);

int main(int argc, char const *argv[]) {
  int filas,columnas,x,y;
  textbgcolor(default_text,default_background);
  ref2:
  printf("Bienvenido a color flood ingrese el ancho y largo del tablero \nancho: ");
  scanf("%i",&filas );
  printf("largo: ");
  scanf("%i",&columnas );

  tablero = (int**)malloc(filas*(sizeof(int*)));
  llave = (int**)malloc(filas*(sizeof(int*)));
  for ( x = 0; x < filas; x++) {
    tablero[x] = (int*)malloc(columnas*(sizeof(int)));
    llave[x] = (int*)malloc(columnas*(sizeof(int)));
  }

  init_rand();
  generar_tablero(filas,columnas,tablero);
    for ( x = 0; x < filas; x++) {
          for ( y = 0; y < columnas; y++) {
				llave[x][y] = 0;
          }

      }
      //OJO INICIO DONDE CAMBIA
        llave[0][0] = 1;
        int i;
        cantidad_de_pasos = filas + columnas + 2;
		system("cls");

           menu:
        	printf("MENU\n1] Ayuda\n2] Jugar\n3] Cambiar medidas \n4] salir\n");
        	scanf("%i",&menu_option);

        	if ( menu_option == 2 )
        	{
        		      while ( 1 == 1 ) {
       						system("cls");
        					printf("Jugada %i/%i",jugada,cantidad_de_pasos);
					        printf("\n");
          					imprimir_tablero(filas,columnas,tablero);
          					//opciones
          					for ( i = 0; i < 7; i++)
          					{
          							if ( i == 0 )
          							{
          								gotoxy((i*4)+1,filas+2);
          					   			printf("%i",i);
          								textbgcolor(7,7);
          								printf(". ");
          								textbgcolor(default_text,default_background);
          								printf(" ");
          							}
          							else
          							{
          								gotoxy((i*4)+1,filas+2);
          								printf("%i",i);
          								textbgcolor(i,i);
          								printf(". ");
          								textbgcolor(default_text,default_background);
          								printf(" ");
          							}
          					}
          				 textbgcolor(default_text,default_background);

          					cambiar_paletas(filas,columnas,tablero,option);
          					option = getch();
          				if ( option == '9') {
          	 					 system("cls");
             					 goto menu;
          				}
          				else
          				{
          					jugada+=1;
          					 	if ( jugada > cantidad_de_pasos)
							 	{
 										system("cls");
								 		gotoxy(0,0);
 										printf("YOU lose\n");
 										break;
 								}
          					cambiar_paletas(filas,columnas,tablero,option);
          				}
      				}
        	}
        	else if ( menu_option == 1 )
        	{
        		ref1:
        		system("cls");
        		printf(" AYUDA\n1.-para salir de pantallade menu con '9'\n2.-Cambiar los colores con las teclas 0 hasta el 1\n las opciones son Paleta: 0-blanco 1-azul 2-verde 3-agua 4-Rojo 5-Purpura 6-Amarillo\n");
        		printf("opcion: ");
        		scanf("%i",&menu_option);
	        	switch(menu_option){
	        		case 9:
		        		system("cls");
	        			goto menu;
	        			break;
	        		default:
	        			goto ref1;
	        			break;
	        	}
        	}
        	else if (menu_option == 3 )
        	{
        		goto ref2;
        	}
        	else
        	{
        		return 0;
        	}

  system("PAUSE");
  return 0;
}

int generar_tablero(int filas,int columnas,int **array){

    int x,y;
    for ( x = 0; x < filas; x++) {
      for ( y = 0; y < columnas; y++) {
          array[x][y] = rand() % 7;
      }
    }
}

int imprimir_tablero(int filas,int columnas,int **array){
    int x,y;

    for ( x = 0; x < filas; x++) {
      for ( y = 0; y < columnas; y++) {
          if ( array[x][y] == 1 ) {
            textbgcolor(1,1);
            printf(" .");
          }
          else if ( array[x][y] == 2 ) {
              /* code */
              textbgcolor(2,2);
              printf(" .");
          }
          else if ( array[x][y] == 3 ) {
              /* code */
              textbgcolor(3,3);
              printf(" .");
          }
          else if ( array[x][y] == 4 ) {
              /* code */
              textbgcolor(4,4);
              printf(" .");
          }
          else if ( array[x][y] == 5 ) {
              /* code */
              textbgcolor(5,5);
              printf(" .");
          }
          else if ( array[x][y] == 6 ) {
              /* code */
              textbgcolor(6,6);
              printf(" .");
          }
          else if ( array[x][y] == 0 ) {
              /* code */
              textbgcolor(7,7);
              printf(" .");
          }

      }
      textbgcolor(default_text,default_background);
      printf("\n" );
    }
    textbgcolor(default_text,default_background);
}


int init_rand(){
  srand(time(NULL));
}

int cambiar_paletas(int filas,int columnas,int **array,int number){
  int x,y,c;
  int w,z;

  z = 1;

  switch ( number ) {
    case '0':
      c = 0;
      break;
    case '1':
      c = 1;
      break;
    case '2':
      c = 2;
      break;
    case '3':
      c = 3;
      break;
    case '4':
      c = 4;
      break;
    case '5':
      c = 5;
      break;
    case '6':
       c = 6;
       break;
    default:
      c = array[0][0];
      break;
  }

  for ( x = 0; x < filas; ++x)
  {

	for ( y = 0; y < columnas; ++y)
  	{

  			if ( llave[x][y] == 1)
  			{

				 //horizontal iz dere
  				z = 1;
  				for ( w = y; w < columnas; w++)
  				{
  					if ( tablero[x][w] == tablero[0][0] && z == 1)
  					{
  						llave[x][w] = 1;
  					}
  					else
  					{
  						z = 0;
  					}
  				}

  				//horizontal dere izqerd
  				z = 1;
  				for ( w = y; w >= 0; w--)
  				{
  					if ( tablero[x][w] == tablero[0][0] && z == 1)
  					{
  						llave[x][w] = 1;
  					}
  					else
  					{
  						z = 0;

  					}
  				}

 				//vertical arriba abajo

				z = 1;
  				for ( w = x; w < filas; w++)
  				{
  						if ( tablero[w][y] == tablero[0][0] && z == 1)
  						{
  							llave[w][y] = 1;
  						}
  						else
  						{
  							z = 0;
  						}
  			    }


  			    //vertical abajo arriba
				z = 1;
  				for ( w = x; w >= 0; w--)
  				{
  						if ( tablero[w][y] == tablero[0][0] && z == 1)
  						{
  							llave[w][y] = 1;
  						}
  						else
  						{
  							z = 0;
  						}
  			    }


   			}
    }

  }
    for ( x = 0; x < filas; ++x)
    {
		for ( y = 0; y < columnas; ++y)
	  	{
	  	 	if ( llave[x][y] == 1)
	  	 	{
	  	 		tablero[x][y] = c;
	  	 	}
    	}
    }

    int contador,winning;
    winning = 0;
    contador = filas*columnas;
    for ( x = 0; x < filas; ++x)
    {
		for ( y = 0; y < columnas; ++y)
	  	{
	  	 	if ( llave[x][y] == 1 )
	  	 	{
	  	 		winning++;
	  	 	}
    	}

    }
 	if ( winning == contador )
 	{
 		gotoxy(0,0);
 		system("cls");
 		printf("YOU WIN, si continuas perderas!");

 	}
}
