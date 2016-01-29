#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
#define L 25

int barcos;

typedef struct{
        char *nombre;
        char *apellido;
        int edad;
	char *rol;
} persona;

typedef struct{
	char *nombre;
	int eslora;
	int manga;
	int max_tripulantes;
	int tripulantes;
	persona *personas;
	persona propietario;
} embarcacion;

void menu(embarcacion *);
void agregarBarco(embarcacion *);
void agregarTripulante(embarcacion *);
void destructor(embarcacion *);
void destructorPersonas(persona *, int);
void imprimirEmbarcaciones(embarcacion *);
void imprimitTripulantes(embarcacion *, int);

int main(){
	barcos = 0;	

	embarcacion *embarcaciones = (embarcacion *) malloc(N * L * L * sizeof(embarcaciones));
	menu(embarcaciones);
	
	destructor(embarcaciones);
	return 0;
}

void menu(embarcacion *e){

	int opcion;

	do{
		printf("\nQue deseas hacer?\n\n");
  		printf("1.- Agregar barco\n");
		printf("2.- Agregar tripulantes\n");
		printf("3.- Ver tripulantes y propietarios\n");
		printf("4.- Ver registros de los barcos\n");
		printf("0.- Salir\n");		

		scanf("%d", &opcion);

		if(opcion == 1){
			agregarBarco(e);
        	} else if(opcion == 2){ 
			agregarTripulante(e);
		} else if(opcion == 3){
			imprimitTripulantes(e, 0);
		} else if(opcion == 4){
			imprimitTripulantes(e, 1);
		} else if(opcion == 0){
                	printf("Adios\n");
        	} else{ 
                	printf("Opcion invalida");
        	}

	}while(opcion != 0);
	
}

void agregarBarco(embarcacion *e){
	
	int n, i;
	
	embarcacion *ePuntero = e;

	while(barcos > (ePuntero - e))
		ePuntero++;

	printf("\nDime el numero de embarcaciones a incorporar\n");
	scanf("%d", &n);		

	for(i = 0; i < n; ++i){
		embarcacion temp;
		printf("\nDime el nombre de la embarcacion\n");
		temp.nombre = (char *) malloc(L * sizeof(char *));
		scanf("%s", temp.nombre);
		printf("\nDime la longitud de la eslora\n");
		scanf("%d", &temp.eslora);
		printf("\nDime la longitud de la manga\n");
		scanf("%d", &temp.manga);
		printf("\nDime el numero maximo de tripulantes\n");		
		scanf("%d", &temp.max_tripulantes);
		printf("\nDime el nombre del propietario, separa nombre apellido con enter\n");
		temp.propietario.nombre = (char *) malloc(L * sizeof(char *));
		temp.propietario.apellido = (char *) malloc(L * sizeof(char *));
		scanf("%s", temp.propietario.nombre);
		scanf("%s", temp.propietario.apellido);
		printf("\nDime la edad del propietario\n");
		scanf("%d", &temp.propietario.edad);
		temp.propietario.rol = "Propietario";
		temp.personas = (persona *) malloc(temp.max_tripulantes * sizeof(persona));
		temp.tripulantes = 0;
		*ePuntero = temp;
		ePuntero++;
		barcos++;		
	}	
}

void agregarTripulante(embarcacion * e){
	
	int n, i, j, k;
	
	printf("\nDime cuantos tripulantes quieres agregar\n");
	scanf("%d", &n);

	for(i = 0; i < n; ++i){
		persona temp;
		printf("\nDime el nombre del tripulante, separa nombre apellido con enter\n");
		temp.nombre = (char *) malloc(L * sizeof(char));
		scanf("%s", temp.nombre);
		temp.apellido = (char *) malloc(L * sizeof(char));
		scanf("%s", temp.apellido);
		printf("\nDame la edad del tripulante\n");
		scanf("%d", &temp.edad);
		printf("\bDame el rol del tripulante\n");
		temp.rol = (char *) malloc(L * sizeof(char));	
		scanf("%s", temp.rol);

		printf("\nDame el nombre de la embarcacion a que quieres asignar el tripulante\n");
		imprimirEmbarcaciones(e);

		char *nombre = (char *) malloc(L * sizeof(char));
		
		int igual = 1;
		embarcacion * ePuntero;
	
		do{	
			scanf("%s", nombre);

			ePuntero = e;

			for(j = 0; j < barcos; ++j){
				if(strcmp((*ePuntero).nombre, nombre) == 0){
					
					if((*ePuntero).max_tripulantes > (*ePuntero).tripulantes){
						igual = 0;
						persona * pPuntero = (*ePuntero).personas;
					
						for(k = 0; k < (*ePuntero).tripulantes; ++k)				
							pPuntero++;
					
						*pPuntero = temp;
						(*ePuntero).tripulantes++;
						break;
					} else{
						printf("\nLa tripulacion que eligio ya esta en su cupo maximo, por favor elija otro\n");
						printf("\nDesea terminar con la transaccion? Elija 1 y el tripulante sera eliminado. 0 Para continuar y buscar otro\n");

						int opcion;
						scanf("%d", &opcion);

						if(opcion){
							igual = 0;
							break;
						}
					}
				}
				ePuntero++;
			}
		
			if(igual)
				printf("\nInserte otro nombre por favor\n");
			 
		}while(igual);		
	}
}

void imprimirEmbarcaciones(embarcacion * e){

	embarcacion * ePuntero = e;
	printf("\n\nEmbarcaciones\n\n");
	
	while(barcos > (ePuntero - e)){
		printf("Nombre: %s\nEslora: %d\nManga: %d\nTripulantes abordos: %d\nCapacidad maxima: %d\n\n",
		(*ePuntero).nombre, (*ePuntero).eslora, (*ePuntero).manga, (*ePuntero).tripulantes, (*ePuntero).max_tripulantes); 
		ePuntero++;
	}
}

void destructor(embarcacion *e){
	embarcacion *ePuntero = e;	

	while(barcos > (ePuntero - e)){
		free((*ePuntero).propietario.nombre);	
		free((*ePuntero).propietario.apellido);
		destructorPersonas((*ePuntero).personas, (*ePuntero).tripulantes);
		ePuntero++;		
	}

	free(e);	
}

void destructorPersonas(persona *p, int n){
	persona *pPuntero = p;
			
	while(n > (pPuntero - p)){
		free((*pPuntero).nombre);
		free((*pPuntero).apellido);
		free((*pPuntero).rol);
		pPuntero++;	
	}

	free(p);
}

void imprimitTripulantes(embarcacion * e, int o){
	embarcacion *ePuntero = e;

	while(barcos > (ePuntero - e)){
		if(o)
			 printf("Nombre: %s\nEslora: %d\nManga: %d\nTripulantes abordos: %d\nCapacidad maxima: %d",
                	(*ePuntero).nombre, (*ePuntero).eslora, (*ePuntero).manga, (*ePuntero).tripulantes, (*ePuntero).max_tripulantes);

		printf("\nPropietario: %s %s Embarcacion: %s\n", (*ePuntero).propietario.nombre, (*ePuntero).propietario.apellido,
		(*ePuntero).nombre);
		persona *pPuntero = (*ePuntero).personas;

		while((*ePuntero).tripulantes > (pPuntero - (*ePuntero).personas)){
			printf("Nombre: %s %s Rol: %s Embarcacion: %s\n", (*pPuntero).nombre, (*pPuntero).apellido, (*pPuntero).rol, (*ePuntero).nombre);
			pPuntero++;
		}
		printf("\n");	
		ePuntero++;
	}		
}
