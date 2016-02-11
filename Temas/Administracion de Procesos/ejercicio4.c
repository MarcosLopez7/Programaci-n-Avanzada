#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define S 6

void procesar(int, int, int);

int main(int argc, const char * argv[]) {

	if(argc != 3){
		exit(0);
	}

	printf("%d\n", \
        	getpid());

	procrear(atoi(argv[1]), 0, atoi(argv[2]));

    	return 0;
}


void procrear(int n, int p, int h){

	if(p == h){}
	else {

   		pid_t pid;
   		int estado, i;
 
		for(i = 0; i < n; ++i)
		{
   
    			pid = fork();
    
    			/* De aquí en adelante lo ejecutan los dos procesos */
    			if (pid == -1)
    			{
        			printf("Error al crear el proceso hijo \n");
    			}
    			else if (pid == 0)
    			{
        			// Estamos en el hijo
				int i;

				for(i = 0; i < ((p * S) + S); i++){	
					printf("-");
				}

        			printf("%d\n", \
               				getpid());
				
				procrear(n, p + 1, h);

        			exit(0);
    			}
    			else {
        
        			if (waitpid(pid, &estado, 0) != -1)
        			{
            				if (WIFEXITED(estado)){}
        			}	
        
        
    			}
    
		}
	}

}

