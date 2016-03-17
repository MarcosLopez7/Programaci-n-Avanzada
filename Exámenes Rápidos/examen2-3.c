#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

#define UG 100
#define UE 50

int *usuarios_general;
int *usuarios_empresarial;

pthread_mutex_t mutex_general;
pthread_mutex_t mutex_empresarial;
pthread_mutex_t mutex_turnog;
pthread_mutex_t mutex_turnoe;

void *rellena_fila_general(void *);
int turnog = -1;
void *rellena_fila_empresarial(void *);
int turnoe = -1;

void *cajero1(void *);
void *cajero2(void *);
void *cajero3(void *);
void *cajero4(void *);
void *cajero5(void *);
void *cajero6(void *);
void *cajero7(void *);
void *cajero8(void *);

int main() {

	usuarios_general = (int *) malloc(UG * sizeof(int));
	usuarios_empresarial = (int *) malloc(UE * sizeof(int));

	pthread_t cajero_1;
	pthread_t cajero_2;
	pthread_t cajero_3;
	pthread_t cajero_4;
	pthread_t cajero_5;
	pthread_t cajero_6;
	pthread_t cajero_7;
	pthread_t cajero_8;
	pthread_t fila_general;
	pthread_t fila_empresarial;

	srand((int) time(NULL));

	pthread_create(&fila_general, NULL, rellena_fila_general, NULL);
	pthread_create(&fila_empresarial, NULL, rellena_fila_empresarial, NULL);
	pthread_create(&cajero_1, NULL, cajero1, NULL);
	pthread_create(&cajero_2, NULL, cajero2, NULL);
	pthread_create(&cajero_3, NULL, cajero3, NULL);
	pthread_create(&cajero_4, NULL, cajero4, NULL);
	pthread_create(&cajero_5, NULL, cajero5, NULL);
	pthread_create(&cajero_6, NULL, cajero6, NULL);
	pthread_create(&cajero_7, NULL, cajero7, NULL);
	pthread_create(&cajero_8, NULL, cajero8, NULL);

	pthread_join(cajero_1, NULL);
	pthread_join(cajero_2, NULL);
	pthread_join(cajero_3, NULL);
	pthread_join(cajero_4, NULL);
	pthread_join(cajero_5, NULL);
	pthread_join(cajero_6, NULL);
	pthread_join(cajero_7, NULL);
	pthread_join(cajero_8, NULL);
	pthread_join(fila_general, NULL);
	pthread_join(fila_empresarial, NULL);

	free(usuarios_general);
	free(usuarios_empresarial);
	return 0;
}

void *rellena_fila_general(void *a) {
	int i;
	int *fgp = usuarios_general;

	for(i = 0; i < UG; ++i) {
		sleep((rand() % 6) + 2);
		pthread_mutex_lock(&mutex_general);
		*fgp = i + 1;
		pthread_mutex_unlock(&mutex_general);
		printf("El cliente con id %d llego hacer una operacion general\n", *fgp);
		fgp++;
	}

	pthread_exit(NULL);
}

void *rellena_fila_empresarial(void *a) {
	int i;
	int *fep = usuarios_empresarial;
	
	for(i = 0; i < UE; ++i) {
		sleep((rand() % 11) + 3);
        pthread_mutex_lock(&mutex_empresarial);
        *fep = i + 101;	
        pthread_mutex_unlock(&mutex_empresarial);
        printf("El cliente con id %d llego hacer una operacion empresarial\n", *fep);
		fep++;
	}

	pthread_exit(NULL);
}

void *cajero1(void *a) {

	int i = 0;

	while(turnog < (UG - 1)) {
		pthread_mutex_lock(&mutex_turnog);
		if(usuarios_general[turnog + 1] >= 1){
			turnog++;
			pthread_mutex_unlock(&mutex_turnog);
			printf("El cajero 1, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);		
			sleep((rand() % 3) + 3);
			i++;
			if(i == 5){
				printf("El cajero 1 fue a hacerte el tonto por un momento\n");
				sleep(3);
				i = 0;
			}
	
		} else {
			pthread_mutex_unlock(&mutex_turnog);
		}		
	}
	
	pthread_exit(NULL);	
}

void *cajero2(void *a) {
	int i = 0;

	while(turnog < (UG - 1)) {			
		pthread_mutex_lock(&mutex_turnog);
		if(usuarios_general[turnog + 1] >= 1){
			turnog++;
			pthread_mutex_unlock(&mutex_turnog);
			printf("El cajero 2, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);		
			sleep((rand() % 3) + 3);
		i++;
			if(i == 5){
				printf("El cajero 1 fue a hacerte el tonto por un momento\n");
				sleep(3);
				i = 0;
			}	
		} else {
			pthread_mutex_unlock(&mutex_turnog);
		}
	}

	pthread_exit(NULL);
}

void *cajero3(void *a) {
	int i = 0;

	while(turnog < (UG - 1)) { 	
		pthread_mutex_lock(&mutex_turnog);
		if(usuarios_general[turnog + 1] >= 1) {
			turnog++;
			pthread_mutex_unlock(&mutex_turnog);
			printf("El cajero 3, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);		
			sleep((rand() % 3) + 3);		
		i++;
			if(i == 5){
				printf("El cajero 1 fue a hacerte el tonto por un momento\n");
				sleep(3);
				i = 0;
			}	
		} else {
			pthread_mutex_unlock(&mutex_turnog);
		}
	}

	pthread_exit(NULL);
}

void *cajero4(void *a) {
	int i = 0;

	while(turnog < (UG - 1)) {  
		pthread_mutex_lock(&mutex_turnog);
		if(usuarios_general[turnog + 1] >= 1) {
			turnog++;
			pthread_mutex_unlock(&mutex_turnog);
			printf("El cajero 4, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);		
			sleep((rand() % 3) + 3);		
		i++;
			if(i == 5){
				printf("El cajero 1 fue a hacerte el tonto por un momento\n");
				sleep(3);
				i = 0;
			}	
		} else {
			pthread_mutex_unlock(&mutex_turnog);
		}
	}
	
	pthread_exit(NULL);
}

void *cajero5(void *a) {
	int i = 0;

	while(turnog < (UG - 1)) {  
		pthread_mutex_lock(&mutex_turnog);
		if(usuarios_general[turnog + 1] >= 1) {
			turnog++;
			pthread_mutex_unlock(&mutex_turnog);
			printf("El cajero 5, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);		
			sleep((rand() % 3) + 3);		
		i++;
			if(i == 5){
				printf("El cajero 1 fue a hacerte el tonto por un momento\n");
				sleep(3);
				i = 0;
			}	
		} else {
			pthread_mutex_unlock(&mutex_turnog);
		}
	}

	pthread_exit(NULL);
}

void *cajero6(void *a) {
	int i = 0;

	while(turnog < (UG - 1) || turnoe < (UE - 1)) {
		pthread_mutex_lock(&mutex_turnoe);
		if(usuarios_empresarial[turnoe + 1] >= 1) {
			turnoe++;
			pthread_mutex_unlock(&mutex_turnoe);
			printf("El cajero 6, esta atendiendo al usuario con id %d en una operacion empresarial\n", usuarios_empresarial[turnoe]);
			sleep((rand() % 3) + 3);
			i++;						
		} else {
			pthread_mutex_unlock(&mutex_turnoe);
			pthread_mutex_lock(&mutex_turnog);
			if(usuarios_general[turnog + 1] >= 1) {
	            turnog++;
	             pthread_mutex_unlock(&mutex_turnog);
	             printf("El cajero 6, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);
	             sleep((rand() % 3) + 3);
		         i++;
        	} else {
             	pthread_mutex_unlock(&mutex_turnog);
         	}
				
				
		}
	
		if(i == 5){
	        printf("El cajero 6 fue a hacerte el tonto por un momento\n");
            sleep(3);
            i = 0;
        }

	}
	


	pthread_exit(NULL);
}

void *cajero7(void *a) {
	int i = 0;

	while(turnog < (UG - 1) || turnoe < (UE - 1)) {
		pthread_mutex_lock(&mutex_turnoe);
		if(usuarios_empresarial[turnoe + 1] >= 1) {
			turnoe++;
			pthread_mutex_unlock(&mutex_turnoe);
			printf("El cajero 7, esta atendiendo al usuario con id %d en una operacion empresarial\n", usuarios_empresarial[turnoe]);
			sleep((rand() % 3) + 3);
			i++;						
		} else {
			pthread_mutex_unlock(&mutex_turnoe);
			pthread_mutex_lock(&mutex_turnog);
			if(usuarios_general[turnog + 1] >= 1) {
	            turnog++;
	             pthread_mutex_unlock(&mutex_turnog);
	             printf("El cajero 7, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);
	             sleep((rand() % 3) + 3);
		         i++;
        	} else {
             	pthread_mutex_unlock(&mutex_turnog);
         	}
				
				
		}
	
		if(i == 5){
	        printf("El cajero 7 fue a hacerte el tonto por un momento\n");
            sleep(3);
            i = 0;
        }

	}

	pthread_exit(NULL);
}

void *cajero8(void *a) {
	int i = 0;

	while(turnog < (UG - 1) || turnoe < (UE - 1)) {
		pthread_mutex_lock(&mutex_turnoe);
		if(usuarios_empresarial[turnoe + 1] >= 1) {
			turnoe++;
			pthread_mutex_unlock(&mutex_turnoe);
			printf("El cajero 8, esta atendiendo al usuario con id %d en una operacion empresarial\n", usuarios_empresarial[turnoe]);
			sleep((rand() % 3) + 3);
			i++;						
		} else {
			pthread_mutex_unlock(&mutex_turnoe);
			pthread_mutex_lock(&mutex_turnog);
			if(usuarios_general[turnog + 1] >= 1) {
	            turnog++;
	             pthread_mutex_unlock(&mutex_turnog);
	             printf("El cajero 8, esta atendiendo al usuario con id %d en una operacion general\n", usuarios_general[turnog]);
	             sleep((rand() % 3) + 3);
		         i++;
        	} else {
             	pthread_mutex_unlock(&mutex_turnog);
         	}
				
				
		}
	
		if(i == 5){
	        printf("El cajero 8 fue a hacerte el tonto por un momento\n");
            sleep(3);
            i = 0;
        }

	}
	
	pthread_exit(NULL);
}
