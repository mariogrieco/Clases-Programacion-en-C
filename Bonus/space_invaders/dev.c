#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "conio.h"
#include "myconio.h"

#define x 0
#define y 1

#define up 72
#define down 80
#define left 75
#define rigth 77

#define max_rigth 20
#define max_down 10

void wd(int, int);
void main_controller_limits_and_pass(int,int);
void main_controller(void);
int bullet_controllers(void);

int main_coords[2] = { 10,5 };
int bullets_coords[2] = { 0,0 };
int gameloop = 1;
char c;
char caracter = '>';
int balas = 30;
int lives = 3;

int main() {

  while ( 1 == gameloop ) {
      system("cls");

      //printf("x:%d y:%d", coords[x],coords[y]);
      wd(balas,lives);
      main_controller();
      if ( c == 'q') {
         gameloop = 0;
      }
  }

  return 0;
}

void main_controller_limits_and_pass(int X,int Y){
  main_coords[x] += X;
  main_coords[y] += Y;

  if ( main_coords[x] <= -1 ) {
    main_coords[x] = 0;
  }
  if ( main_coords[y] <= 1 ) {
    main_coords[y] = 1;
  }
  if ( main_coords[x] >= max_rigth ) {
    main_coords[x] = max_rigth-1;
  }
  if ( main_coords[y] >= max_down ) {
    main_coords[y] = max_down-1;
  }
}

void main_controller(){
  gotoxy(main_coords[x],main_coords[y]);
  printf("%c",caracter);
  c = getch();

  if ( c == up ) {
      caracter = '^';
      main_controller_limits_and_pass(0,-1);
  }
  else if ( c == down ) {
    caracter = 'v';
    main_controller_limits_and_pass(0,1);
  }
  else if ( c == left ) {
    caracter = '<';
    main_controller_limits_and_pass(-1,0);
  }
  else if ( c == rigth ) {
    caracter = '>';
    main_controller_limits_and_pass(1,0);
  }
  else if ( c == 'm' ) {
    bullet_controllers();
  }
  else if ( c == 'i') {

  }
}

int bullet_controllers(){
  if ( balas > 0 ) {
    int i;
    bullets_coords[x] = main_coords[x];
    bullets_coords[y] = main_coords[y];

    if ( caracter == '>') {
      for ( i = 1; i < 5; i++) {
        if ( bullets_coords[x]+i >= max_rigth ) {
            balas -= 1;
            return 0;
        }
        gotoxy(bullets_coords[x]+i,bullets_coords[y]);
        printf("-");
        Sleep(200);
        gotoxy(bullets_coords[x]+i,bullets_coords[y]);
        printf(" ");
      }
    }
    else if ( caracter = '<')
    {
      for ( i = 1; i < 5; i++) {
        if ( bullets_coords[x]-i <= 0 ) {
              balas -= 1;
            return 0;

        }
        gotoxy(bullets_coords[x]-i,bullets_coords[y]);
        printf("-");
        Sleep(200);
        gotoxy(bullets_coords[x]-i,bullets_coords[y]);
        printf(" ");
      }

    }
    else if (caracter = '^' ){
      for ( i = 1; i < 5; i++) {
        if ( bullets_coords[y]+i <= 0 ) {
              balas -= 1;
            return 0;

        }
        gotoxy(bullets_coords[x],bullets_coords[y]+i);
        printf("*");
        Sleep(200);
        gotoxy(bullets_coords[x],bullets_coords[y]+i);
        printf(" ");
      }
    }
    else if( caracter = 'v' )
    {
      for ( i = 1; i < 5; i++) {
        if ( bullets_coords[y]+i <= 0 ) {
              balas -= 1;
            return 0;

        }
        gotoxy(bullets_coords[x],bullets_coords[y]-i);
        printf("*");
        Sleep(200);
        gotoxy(bullets_coords[x],bullets_coords[y]-i);
        printf(" ");
      }

    }
    balas -= 1;
  }

}

void wd(int bullets, int lives){
    gotoxy(0,0);
    printf("balas: %i vidas: %i",bullets,lives );
}
