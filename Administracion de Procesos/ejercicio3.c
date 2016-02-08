//
//  main.c
//  creando_procesos
//
//  Created by Vicente Cubells Nonell on 31/08/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#define T 10

int main(int argc, const char * argv[]) {

   	pid_t pid;
   	int estado, i, n;
   	
	printf("Cuantos procesos te ejecutamos?\n");
	scanf("%d", &n);

	printf("Estes el papa de todos con PID = %d y su padre es PPID = %d \n", \
                   getpid(), getppid());

	srand((int) time(NULL));

	for(i = 0; i < n; i++){
	 
    		pid = fork();
    
    		/* De aquí en adelante lo ejecutan los dos procesos */
	    	if (pid == -1)
    		{
        		printf("Error al crear el proceso hijo \n");
    		}
    		else if (pid == 0)
    		{
        		// Estamos en el hijo
			printf("Comienza el proceso hijo con PID = %d y su padre es PPID = %d \n", \
                		getpid(), getppid());	
			sleep(rand() % T);
        		exit(0);
    		}
    		else {
        		// Poner al padre a esperar que el hijo termine
        		if (waitpid(pid, &estado, 0) != -1)
        		{
            			if (WIFEXITED(estado))
                			printf("Ya terminó el hijo con PID %d con valor de retorno %d \n", pid, WEXITSTATUS(estado));
        		}	
        
    		}
    
	}

    	return 0;
}

