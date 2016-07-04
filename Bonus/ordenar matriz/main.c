#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
#include "math.h"
#include "myconio.h"

  int set_array(int **,int,int);
  int printm(int **,int,int);
  int buscar(int **,int, int, int);

int main(){
    int filas, columnas, **v,i;
    printf("\ningrese cantidad de filas: ");
    scanf("%i", &filas);
    printf("\ningrese cantidad de columnas: ");
    scanf("%i", &columnas);


      v = (int **)malloc(filas*sizeof(int*));

      for ( i = 0; i < filas; i++) {
        v[i] = (int*)malloc(columnas*sizeof(int));
      }

      set_array(v,filas,columnas);
      printm(v,filas,columnas);
      printf("\n");

      int *ordenado;
      int x,y;
      int contador = 0;
      int swap;

      ordenado = (int*)malloc((filas*columnas)*sizeof(int));

      for ( x = 0; x < filas; x++) {
          for ( y = 0; y < columnas; y++ ){
              ordenado[contador] = v[x][y];
              contador += 1;
          }
      }

      ref1:

      for ( y = 0; y < columnas*filas-1; y++ ){
           if ( ordenado[y] > ordenado[y+1]) {
              swap = ordenado[y+1];
              ordenado[y+1] = ordenado[y];
              ordenado[y] = swap;
           }
      }
      for ( y = 0; y < columnas*filas-1; y++ ){
           if ( ordenado[y] > ordenado[y+1]) {
             goto ref1;
           }
      }
      contador = 0;
      for ( x = 0; x < filas; x++) {
          for ( y = 0; y < columnas; y++ ){
              v[x][y] = ordenado[contador];
              contador += 1;
          }
      }
      printm(v,filas,columnas);




}

int set_array(int **array,int filas,int columnas){
  srand(time(NULL));
  int y,x,i,numero;
  for ( x = 0; x < filas; x++) {
      for ( y = 0; y < columnas; y++ ){
        array[x][y] = -1;
        numero = rand() % (filas*columnas);
        while( buscar(array,numero,filas,columnas) ){
            numero = rand() % (filas*columnas);
        }
        array[x][y] = numero;
      }
  }
}

int printm(int **array,int filas,int columnas){
  int y,x,i;
  for ( x = 0; x < filas; x++) {
      for ( y = 0; y < columnas; y++ ){
          printf("%i ", array[x][y]);
      }
      printf("\n");
  }
}
int buscar(int **array,int numero, int filas, int columnas){
  int y,x,i;
  for ( x = 0; x < filas; x++) {
      for ( y = 0; y < columnas; y++ ){
          if ( numero == array[x][y]) {
            return 1;
          }
      }
  }
  return 0;
}
