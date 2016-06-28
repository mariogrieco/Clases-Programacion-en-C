#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"
	
	double a;
	double b;
	int opcionUsuario;
	int i;

		double sumar(double,double);
		double restar(double,double);
		double multiplicar(double,double);
		double dividir(double,double);
		int modulo(double,double);

int main()
{
	
	printf("Esto es una calculadora v0.1 \n");
	printf("1.- sumar\n");
	printf("2.- restar\n");
	printf("3.- multiplicar\n");
	printf("4.- dividir\n");
	printf("5.- modulo\n");
	printf("Opcion en valor entero: ");
	scanf("%i",&opcionUsuario);
	printf("\n");
	printf("Ingresa tus 2 numeros\n");
	printf("a: ");
	scanf("%lf",&a);
	printf("\n");
	printf("b: ");
	scanf("%lf",&b);

	printf("a: %f, b: %f \n", a,b);

	switch(opcionUsuario)
	{
		case 1:
			printf(" %f + %f = %f \n",a,b,sumar(a,b));
			break;
		case 2:
			printf(" %f - %f = %f \n",a,b,restar(a,b));
			break;
		case 3:
			printf(" %f * %f = %f \n",a,b,multiplicar(a,b));
			break;
		case 4:
			printf(" %f + %f = %f \n",a,b,dividir(a,b));
			break;
		case 5:
			printf(" %f + %f = %i \n",a,b,sumar(a,b));
			break;
	}

	printf("Ingresa el numero 1 para retomar otro para salir\n");
	scanf("%i",&i);
	if ( i == 1 )
	{
		system("cls");
		return main();
	}
	else
	{
		return 0;
	}

	system("PAUSE");
}

double sumar(double a,double b)
{
	// comentario desde sublime
	return a + b;
}

double restar(double a,double b)
{
	// comentario desde sublime
	return a - b;
}

double multiplicar(double a,double b)
{
	// comentario desde sublime
	return a * b;
}

double dividir(double a,double b)
{
	// comentario desde sublime
	return a / b;
}

int modulo(double a,double b)
{
	// comentario desde sublime
	return (int)a % (int)b;
}