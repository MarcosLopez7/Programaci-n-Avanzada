#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define N 100

int suma(int *);

int main(int argc, const char * argv[])
{
    	int tuberia[2];
    	pid_t pid;
 
	int *numeros = (int *) malloc(N * sizeof(int));
   
    	pipe(tuberia);
    
    	pid = fork();
    
    	if (pid == -1)
    	{
        	printf("Error al crear el proceso hijo");
       	 	exit(-1);
    	}
    	else if (pid == 0)
    	{
        	/* Hijo */
        	close(tuberia[1]);
		int *nums = (int *) malloc(N * sizeof(int));
       
        	read(tuberia[0], nums, N * sizeof(int));
		printf("El resultado es: %d\n", suma(nums));
		free(nums);
    	}
    	else {
        	/* Padre */
        
        	close(tuberia[0]);
        
        	printf("Escribe numeros a sumar, para salir le das 0\n");
       	
		int n;
		int *np = numeros;
		do{

			scanf("%d", &n);
			*np = n;
			np++;		

		} while(n != 0);
 
        	write(tuberia[1], numeros, N * sizeof(int));
    	}
 
	free(numeros);
   
    	return 0;
}

int suma(int *v){

	int res = 0;
		
	int *vP = v;

	while(*vP != 0){
		res += *vP;
		vP++;
	}	

	return res;

}
