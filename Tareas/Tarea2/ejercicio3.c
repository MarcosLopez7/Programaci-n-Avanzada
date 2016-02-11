#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#define T 20

int main(int argc, const char * argv[]) {

   	pid_t pid;
   	int estado, i, n;   	
	
	printf("Cuantos procesos te ejecutamos?\n");
	scanf("%d", &n);

	int *ids = (int *) malloc(n * sizeof(int));
	int *idP = ids;
	printf("Estes el papa de todos con PID = %d y su padre es PPID = %d \n", \
                   getpid(), getppid());

	srand((int) time(NULL));

	for(i = 0; i < n; i++){
	 
    		*idP = fork();
    
    		/* De aquí en adelante lo ejecutan los dos procesos */
	    	if (*idP == -1)
    		{
        		printf("Error al crear el proceso hijo \n");
    		}
    		else if (*idP == 0)
    		{
        		// Estamos en el hijo
			printf("Comienza el proceso hijo con PID = %d y su padre es PPID = %d \n", \
                		getpid(), getppid());
	
			srand((int) time(NULL)^(getpid()<<1));	
			sleep(rand() % T);
			free(ids);	
			return 0;
    		}

		idP++;
    
	}

	idP = ids;

	pid_t pt;
  
  	while ((pt = wait(NULL)) > 0)
    		printf("El hijo con PID %d, ha terminado\n", pt);

	free(ids);
    	return 0;
}

