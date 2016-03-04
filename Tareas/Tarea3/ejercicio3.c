#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

struct sigaction handler;

void handler_alarma1(int);
void handler_alarma2(int);

char mensaje[30] = "Dato";

int main(int argc, const char *argv[]){

	if(argc == 2){
		
		int n = atoi(argv[1]);

		if(10 > n && n > 4){
			
			handler.sa_handler = SIG_IGN;
            handler.sa_flags = SA_RESTART;
			sigaction(SIGINT, &handler, 0);

			int *numeros = (int *) malloc(n * sizeof(int));
			int i;
					
			int *nP = numeros;

            signal(SIGALRM, handler_alarma1);

			alarm(3);

			for(i = 0; i < n; ++i){
				printf("%s %d:", mensaje, i);
				scanf("%d", nP);
				nP++;
			}

			nP = numeros;

			printf("El resultado es: \n");

			for(i = 0; i < n; ++i){
				printf("%d\n", *nP);
				nP++;
			}

			free(numeros);
		} else {
			printf("El valor que tiene que insertar tiene que estar entre 5 y 9\n");
			exit(0);
		}

	} else {
		printf("Inserte solo un argumento para el programa\n");
		exit(0);
	}
	
	
	return 0;
}

void handler_alarma1(int senial){
	strcpy(mensaje, "Dese prisa. Dato");	
}

