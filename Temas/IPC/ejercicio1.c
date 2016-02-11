#include <stdio.h>
#include <unistd.h>

void leer(int fd);
void escribir(int fd, int);

int main(int argc, const char * argv[])
{

	if(argc != 2)
		exit(0);

    	int tuberia[2];
    	pid_t pid;

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
        
        	leer(tuberia[0]);
    	}
    	else {
        	/* Padre */
        
        	close(tuberia[0]);
        
        	escribir(tuberia[1], atoi(argv[1]));
    	}
    
    	return 0;
}

void leer(int fd)
{
    	FILE * file;
    	int c, i;
	int res = 1;    

    	file = fdopen(fd, "r");

	c = fgetc(file) - '0';
    	
	for(i = 1; i <= c; ++i)			
		res *= i;

        printf("\n%d\n", res);
    
    	fclose(file);
}

void escribir(int fd, int n)
{
    	FILE * file;
    	file = fdopen(fd, "w");
   
    	fprintf(file, "%d\n", n);
    
    	fclose(file);
}

