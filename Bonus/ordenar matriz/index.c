#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "myconio.h"

  void reverse_array(int *array, int largo);
  void separar_int(int numero,int *array,int largo);
  int largo_numero(int numero);

int main() {


  int *a;
  int i = 1234;
  int c;

  a = (int*)malloc(largo_numero(i)*sizeof(int));

  separar_int(i,a,largo_numero(i));

  for ( c = 0; c < largo_numero(i); ++c)
  {
      printf("%d ", a[c]);
  }
  printf("\n");
  reverse_array(a,largo_numero(i));
  for ( c = 0; c < largo_numero(i); ++c)
  {
      printf("%d ", a[c]);
  }

}

int largo_numero(int numero){
    if ( numero >= 99 && numero <= 999 ) {
        return 3;
    }
    else if ( numero >= 999 && numero <= 9999 ) {
        return 4;
    }
    else if ( numero <= 9 )
    {
      return 1;
    }
    else if (numero >= 9 && numero <= 99) {
      return 2;
    }
    else
    {
      return 0;
    }

}

void separar_int(int numero,int *array,int largo){

    int i;
    int *swap;

    if ( largo == 1 )
    {
      swap = (int*)malloc(2*sizeof(int));
       swap[1] = 0;
         swap[0] = numero;
        array[0] = swap[1];
        array[1] = swap[0];
    }
    else
    {
      swap = (int*)malloc(largo*sizeof(int));

      if ( largo == 3 ) {
          swap[2] = (int)numero % 10;
          swap[1] = (int)numero % 100 / 10;
          swap[0] = (int)numero % 1000 / 100;
      }
      else if ( largo == 4) {
          swap[3] = (int)numero % 10;
          swap[2] = (int)numero % 100 / 10;
          swap[1] = (int)numero % 1000 / 100;
          swap[0] = (int)numero % 10000 / 1000;
      }
      else if ( largo == 2) {
          swap[1] = (int)numero % 10;
          swap[0] = (int)numero % 100 / 10;
      }
       for ( i = 0; i < largo; ++i){
          array[i] = swap[i];
      }

    }
}
void reverse_array(int *array, int largo){

  int i;
  int swap;
      
    if ( largo == 3 )
    {
        swap = array[0];
        array[0] = array[(largo-1)-0];
        array[(largo-1)-0] = swap;
    }
    else if ( largo == 4 )
    {
        swap = array[0];
        array[0] = array[(largo-1)-0];
        array[(largo-1)-0] = swap;

        swap = array[1];
        array[1] = array[(largo-1)-1];
        array[(largo-1)-1] = swap;
    }
}
