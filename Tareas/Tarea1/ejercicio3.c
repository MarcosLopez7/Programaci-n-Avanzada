#include <stdlib.h>
#include <stdio.h>
#define N 5
#define L 25

typedef struct{
	char *nombre;
	char *apellido;
	int edad;
	int telefono;
	int cama;
} paciente;

void menu(paciente *, int *);
void incorporarPaciente(paciente *, int *);
void disponibilidad(paciente *, int *);
void quitar(paciente *, int *);
void mostrar(paciente *, int *);
void destructor(paciente *, int *);

int ocupado;
int cama_size;

int main(){

	int *camas = (int *) malloc(100 * sizeof(int));
	paciente *pacientes = (paciente *) malloc(N * L * L * L * sizeof(paciente));
	ocupado = 0;
	cama_size = N;	

	menu(pacientes, camas);

	//destructor(pacientes, camas);
	free(camas);	
	return 0;
}

void menu(paciente * p, int * c){

	int opcion;

	do{

		printf("\n\nElija una de las siguientes opciones\n\n");
		printf("1.- Incorporar paciente\n");
		printf("2.- Ver disponibilidad de una cama\n");
		printf("3.- Dar de alta a paciente\n");
		printf("4.- Mostrar pacientes\n");
		printf("5.- Ver numero de camas disponibles y ocupadas\n");
		printf("0.- Salir\n");

		scanf("%d", &opcion);
		
		if(opcion == 1)
			incorporarPaciente(p, c);
		else if(opcion == 2)
			disponibilidad(p, c);
		else if(opcion == 3)
			quitar(p, c);
		else if(opcion == 4)
			mostrar(p, c);
		else if(opcion == 5)
			printf("\nCamas ocupadas: %d disponible: %d", ocupado, cama_size - ocupado);					
		else if(opcion == 0)
			printf("Adios\n");
		else
			printf("\nOpcion Invalida\n");

	} while(opcion != 0);
	
}

void incorporarPaciente(paciente *p, int *c){
	
	int n, i;
	
	printf("\nCuantos pacientes desea incorporar?\n");
	scanf("%d", &n);

	paciente *pPuntero = p;
	int *cPuntero = c;

	if(ocupado + n > cama_size){
		cama_size += N;
		printf("\nSobre cupo de pacientes, incorpotando 5 camas mas\n");
		//c = (int *) realloc(c, 100 * sizeof(int));			
	} 


	for(i = 0; i < n; ++i){
		
		while(ocupado > (pPuntero - p) && *cPuntero){
                	pPuntero++;
                	cPuntero++;
        	}

		printf("\nDame el nombre del paciente, separar por nombre y apellido con enter entre ellos\n");
		
		paciente temp;

		temp.nombre = (char *) malloc(L * sizeof(char));
		temp.apellido = (char *) malloc(L * sizeof(char));	

		scanf("%s", temp.nombre);
		scanf("%s", temp.apellido);
		
		printf("\nDame la edad\n");
		scanf("%d", &temp.edad);
	
		printf("\nDame el telefono\n");
		scanf("%d", &temp.telefono);
	
		if(ocupado == (pPuntero - p)){
			ocupado++;
			temp.cama = ocupado;
		} else{
			ocupado++;		
			temp.cama = cPuntero - c + 1; 
		}
		*cPuntero = 1;
		*pPuntero = temp;		

		if(ocupado == cama_size)
			break;
		else{
			pPuntero++;
			cPuntero++;
		}
	}
	

}

void disponibilidad(paciente *p, int *c){

	int n;
	printf("\nDame el numero de cama, eleige un numero a partir del 1\n");
	
	do{

		scanf("%d", &n);

		if(cama_size >= n && n >= 1){
			if(*(c + n - 1)){
				printf("\nEsta el paciente: %s %s\n", (*(p + n - 1)).nombre, (*(p + n - 1)).apellido);
			} else{
				printf("\nLa cama esta disponible\n");
			}
		} else{
			printf("\nEl numero de cama no existe, por favor elija otro numero\n");
		}
	

	}while(cama_size < n || n < 1);

}

void quitar(paciente *p, int *c){
	int n;
	
        printf("\nDame el numero de cama para dar de alta paciente, eleige un numero a partir del 1\n");

        do{
                scanf("%d", &n);

                if(cama_size >= n && n >= 1){
                        if(*(c + n - 1)){
                                printf("\nEl paciente: %s %s fue dado de alta\n", (*(p + n - 1)).nombre, (*(p + n - 1)).apellido);
				(*(c + n - 1)) = 0;
				ocupado--;
				free((*(p + n - 1)).nombre);
				free((*(p + n - 1)).apellido);
                        } else{
                                printf("\nLa cama no tiene ningun paciente\n");
                        }
                } else{
                        printf("\nEl numero de cama no existe, por favor elija otro numero\n");
                }


        }while(cama_size < n || n < 1);

}

void mostrar(paciente *p, int *c){

	int i;
	paciente *pPuntero = p;
	int *cPuntero = c;

	
	for(i = 0; i < cama_size; ++i){
		if(*cPuntero)
			printf("Paciente %s %s en cama %d\n", (*pPuntero).nombre, (*pPuntero).apellido, (*pPuntero).cama);
		
		pPuntero++;
		cPuntero++;
	}
}

void destructor(paciente * p, int *c){
	paciente *pPuntero = p;
	int *cPuntero = c;
	
	while(cama_size > (cPuntero - c)){
		if(*cPuntero){
			free((*pPuntero).nombre);
			free((*pPuntero).apellido);
		}
		
		pPuntero++;
		cPuntero++;
	}

	free(p);	
}	
