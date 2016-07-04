#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "myconio.h"

struct jugador {
    char identificador;
    int coordenadas[2];

};

        int tablero[31][31] = {
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {0,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                          {1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                          {1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1},
                          {1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,0,0,0,1,1,0,1,1},
                          {1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1},
                          {1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1},
                          {1,0,0,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1},
                          {1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0,1,1},
                          {1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1},
                          {1,0,1,1,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1},
                          {1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
                          {1,0,0,0,1,0,1,1,0,0,0,0,0,0,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
                          {1,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
                          {1,0,0,0,1,0,1,1,0,1,1,1,0,0,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1},
                          {1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1},
                          {1,0,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,1},
                          {1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
                          {1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
                          {1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,0,1,0,1,0,1},
                          {1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1},
                          {1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
                          {1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                          {1,0,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1,1,1,0,1,0,1,0,1},
                          {1,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,1},
                          {1,0,1,1,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,1,0,1,0,1},
                          {1,0,1,1,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1},
                          {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,1},
                          {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1},
                          {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,9,1,1},
                      };

#define default_text 10
#define default_background 0

  int to_play = 0;

int main(int argc, char const *argv[]) {

	system("cls");
  struct jugador gamer;
  int level;
  int option;
  int x,y;
  gamer.identificador = 'o';
  gamer.coordenadas[0] = 1;
  gamer.coordenadas[1] = 0;
  int filas = gamer.coordenadas[0];
  int columnas = gamer.coordenadas[1];

  int seen_filas = gamer.coordenadas[0];
  int seen_columnas = gamer.coordenadas[1];

  printf("Laberinto, The game! \n");
  for ( x = 0; x < 31; x++) {
      for ( y = 0; y < 31; y++) {
         if ( tablero[x][y] == 1) {

         	 textbgcolor(7,7);
             printf("||");
         }
         else
         {
           textbgcolor(default_text,default_background);
           printf("  ");
         }
      }
      printf("\n");
  }
  seen_filas+=1;

  textbgcolor(default_text,default_background);
  while (1 == 1) {
    gotoxy(30,0);
    printf("level %i",to_play);

    gotoxy(seen_columnas,seen_filas);
    textbgcolor(default_text,default_background);
    printf("%c",gamer.identificador );
      option = getch();

        //up
      if ( option == 72 ) {

        if (tablero[filas-1][columnas] == 0) {
            gotoxy(seen_columnas,seen_filas);
            printf(" ");
            filas-=1;
            seen_filas-=1;
        }
        else if (tablero[filas-1][columnas] == 9 ){
          system("cls");
          printf("YOU WIN!\n");
          to_play++;
        }
      }
      //down
      if ( option == 80 ) {

        if (tablero[filas+1][columnas] == 0 ) {
            gotoxy(seen_columnas,seen_filas);
            printf(" ");
            filas+=1;
            seen_filas+=1;
        }
        else if (tablero[filas+1][columnas] == 9 ){
          system("cls");
          printf("YOU WIN!\n");
          to_play++;
        }
      }
      //Rigth
      if ( option == 77 ) {
          if (tablero[filas][columnas+1] == 0 ) {
              gotoxy(seen_columnas,seen_filas);
              printf(" ");
              columnas+=1;
              seen_columnas+=2;
          }
          else if (tablero[filas][columnas+1] == 9 ){
            system("cls");
            printf("YOU WIN!\n");
            to_play++;
          }
      }
      //lefth
      if ( option == 75 ) {
        if (tablero[filas][columnas-1] == 0 ) {
            gotoxy(seen_columnas,seen_filas);
            printf(" ");
            columnas-=1;
            seen_columnas-=2;
        }
        else if (tablero[filas][columnas+1] == 9 ){
          system("cls");
          printf("YOU WIN!\n");
          to_play++;
        }
      }

      //enter
      if ( option == 13 ) {

      }

      if ( option == 'q' ) {
        return 0;
        }

  }



  gotoxy(0,30);
  system("PAUSE");
  return 0;
}
