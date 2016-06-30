#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "conio.h"


int main()
{	
 	

	struct Persona
	{
		char nombre[256];
		char apellido[256];
		int edad;
		char sexo;
	};

	struct Datos
	{
		long int id;
		int clave;
		struct Persona User;
		
	};

	struct Datos Registro;

	fflush(stdout);
	fflush(stdin);
	printf("Ingresa nombre: ");
	gets(Registro.User.nombre);

	fflush(stdout);
	fflush(stdin);
	printf("Ingresa Apellido: ");
	gets(Registro.User.apellido);

	fflush(stdout);
	fflush(stdin);
	printf("Ingresa id: ");
	scanf("%i",&Registro.id);

	fflush(stdout);
	fflush(stdin);
	printf("Ingresa clave: ");
	scanf("%i",&Registro.clave);

	fflush(stdout);
	fflush(stdin);
	printf("Ingresa edad: ");
	scanf("%i",&Registro.User.edad);

	fflush(stdout);
	fflush(stdin);

	printf("Ingresa sexo: ");
	scanf("%c",&Registro.User.sexo);


	printf("Nombre: %s\n",Registro.User.nombre);
	printf("Apellido: %s\n",Registro.User.apellido);
	printf("id: %ld\n",Registro.id);
	printf("clave secreta: %i\n",Registro.clave);
	printf("edad: %i\n",Registro.User.edad );
	printf("Sexo: %c\n",Registro.User.sexo);

	system("PAUSE");
	return 0;
}

