#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef void (* menu_t)();

void opcion1();
void opcion2();
void opcion3();
void opcion4();

int main(){

	int opcion = -1;

	menu_t * opciones = (menu_t *) malloc(N * sizeof(menu_t));

	*opciones = opcion1;
	*(opciones+1) = opcion2;
	*(opciones+2) = opcion3;
	*(opciones+3) = opcion4;

	while(opcion != 0){
		printf("1.- OPcion 1\n2.- Opcion 2\n3.- Opcion 3\n4.- Opcion 4\n0.- Salir\n");
		printf("Selecciona la opcion: ");
		scanf("%d", &opcion);

		if(opcion != 0)
			(*(opciones[opcion-1]))();
	}

	free(opciones);

	return 0;
}

void opcion1(){
	printf("Opcion 1 seleccionada\n");
}

void opcion2(){
        printf("Opcion 2 seleccionada\n");
}

void opcion3(){
        printf("Opcion 3 seleccionada\n");
}

void opcion4(){
        printf("Opcion 4 seleccionada\n");
}
