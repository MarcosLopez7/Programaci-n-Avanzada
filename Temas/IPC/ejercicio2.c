#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define N 100

void leer(int fd);
void escribir(int fd, int *);

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
        
        	printf(" Soy el hijo y estoy leyendo ... \n");
        
        	leer(tuberia[0]);
    	}
    	else {
        	/* Padre */
        
        	close(tuberia[0]);
        
        	printf(" Soy el padre y estoy escribiendo ... \n");
       	
		int n;
		int *np = numeros;
		do{

			scanf("%d", &n);
			*np = n;
			np++;		

		} while(n != 0);
 
        	escribir(tuberia[1], numeros);
    	}
 
	free(numeros);
   
    	return 0;
}

void leer(int fd)
{
    	FILE * file;
    	int c;
    	int res = 0;

    	file = fdopen(fd, "r");
    
    	while ( (c = fgetc(file)) != EOF )
    	{
		c -= '0';
		res += c;
    	}

	printf("Res es: %d\n", res);
    
    	fclose(file);
}

void escribir(int fd, int *nums)
{
    	FILE * file;
    	file = fdopen(fd, "w");

    	int *n = nums;
    	while (*n != 0) {
        	fprintf(file, "%d", *n);
		n++;
    	}

	fprintf(file, "\n");
    
    	fclose(file);
}

