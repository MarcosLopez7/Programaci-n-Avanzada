#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int factoriza(int);

int main(int argc, const char * argv[])
{
    	int tuberia1[2];
	int tuberia2[2];
    	pid_t pid;
    
    	pipe(tuberia1);
	pipe(tuberia2);
    
    	pid = fork();
    
    	if (pid == -1)
    	{
        	printf("Error al crear el proceso hijo");
       	 	exit(-1);
    	}
    	else if (pid == 0)
    	{
        	/* Hijo */
        	close(tuberia1[1]);
        
		int numero;

        	read(tuberia1[0], &numero, sizeof(int));

		close(tuberia2[0]);

		int resultado = factoriza(numero);

		write(tuberia2[1], &resultado, sizeof(int));
    	}
    	else {
        	/* Padre */
        
        	close(tuberia1[0]);
        
		int numero, resultado;

		printf("Dame un numero a factorizar\n");
		scanf("%d", &numero);       
 
        	write(tuberia1[1], &numero, sizeof(int));

		close(tuberia2[1]);

		read(tuberia2[0], &resultado, sizeof(int));

		printf("El resultado es: %d\n", resultado);
    	}
    
    	return 0;
}

int factoriza(int n){

	int res = 1;
	int i;
	
	for(i = 1; i <= n; ++i){
		res *= i;
	}

	return res;
}
