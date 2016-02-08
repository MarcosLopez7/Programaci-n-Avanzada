#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {

   	pid_t pid;
   	int estado, i, n;
 
	if(argc != 2)
	{
		printf("Se necesitan un argumento numerico para que el programa funcione\n");
		exit(0);
	}
 
	n = atoi(argv[1]);

	for(i = 0; i < n; i++)
	{

    		pid = fork();
    
    		if (pid == -1)
    		{
        		printf("Error al crear el proceso hijo \n");
			printf("Solo se crearon %d procesos\n", i);
			exit(0);
    		}
    		else if (pid == 0)
    		{
			float promedio = (getppid() + getpid()) / ((double) 2);
        		printf("Estes el hijo con PID = %d, el promedio de entre este PID y el de su padre es = %.3f \n", \
               		getpid(), promedio);
        		exit(0);
    		}
    		else {
        		if (waitpid(pid, &estado, 0) != -1){}	        
    		}
    
	}

	printf("Estamos en el proceso padre con PID = %d, se han creado los %d procesos hijos de manera satisfactoria\n", \
                   getpid(), n);

    	return 0;
}

