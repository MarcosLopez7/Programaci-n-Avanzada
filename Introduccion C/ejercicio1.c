#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char nombre[25];
	char apellido[25];
	int edad;
}persona;

persona * fill(int );
void promedio(persona *, int);
void menor(persona *, int);
void mayor(persona *, int);
void rango(persona *, int);

int main(){

	int n, opcion;

	printf("Dime cuantas personas quieres agregar\n");
	scanf("%d", &n);

	struct persona * personas = fill(n);

	do{

		opcion = menu();

		if(opcion == 1){
			promedio(personas, n);
		} else if(opcion == 2){
			menor(personas, n);
		} else if(opcion == 3){
			mayor(personas, n);
		} else if(opcion == 4){
			rango(personas, n);
		} else if(opcion == 5){
			printf("Bye\n");
		} else {
			printf("opcion invalida \n\n");
		}

	} while(opcion != 5);		

	return 0;
}

int menu(){

	printf("\n\nDime que quieres hacer?\n\n");
	printf("1.- saber la edad promedio\n");
	printf("2.- saber la persona mas joven\n");
	printf("3.- saber la persona mas vieja\n");
	printf("4.- saber las personas en un rango de edad\n");
	printf("5.- salir\n\n");

	int opcion;

	scanf("%d", &opcion);	

	return opcion;	
}

persona * fill(int n){

	int i;
	persona * personas;
	personas = (persona *) malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++){
		char nombre[25] = "";
		char apellido[25] = "";
		int edad;
	
		printf("Dame nombre\n");
		scanf("%s", nombre);
		printf("Dame apellido\n");
		scanf("%s", apellido);
		printf("Dame edad\n");
		scanf("%d", &edad);

		strcpy(personas[i].nombre, nombre);
		strcpy(personas[i].apellido, apellido);
		personas[i].edad = edad;
	}

	return personas;
}

void promedio(persona * personas, int n){
	
	int i;
	int res = 0;

	for(i = 0; i < n; i++){
		res += personas[i].edad;	
	}

	res /= n;
	
	printf("El promedio de edad es de %d\n\n", res);
}


void menor(persona * personas, int n){
	
	persona menor;
	menor.edad = 9999;
	int i;

	for(i = 0; i < n; i++){
		if(personas[i].edad < menor.edad){
			menor = personas[i];
		}
	}	

	printf("La persona mas joven es: %s %s con %d de edad\n\n", menor.nombre, menor.apellido, menor.edad);
}

void mayor(persona * personas, int n){
	
	persona mayor;
	mayor.edad = 0;
	int i;

	for(i = 0; i < n; i++){
		if(personas[i].edad > mayor.edad){
			mayor = personas[i];
		}
	}	

	printf("La persona mas vieja es: %s %s con %d de edad\n\n", mayor.nombre, mayor.apellido, mayor.edad);
}

void rango(persona * personas, int n){

	int i, menor, mayor;

	printf("\nDame el rango de edad que quieres elegir\n");
	scanf("%d", &menor);
	scanf("%d", &mayor);

	for(i = 0; i < n; i++){
		if(mayor >= personas[i].edad && personas[i].edad >= menor){
			printf("nombre: %s, apellido: %s, edad: %d\n", personas[i].nombre, personas[i].apellido, personas[i].edad);
		}					
	}
}
