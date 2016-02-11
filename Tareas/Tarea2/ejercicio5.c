#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, const char * argv[]) {

	int nflag = 0;
    	int pflag = 0;
	int aflag = 0;
	int n = 0;	
	char c;
	
	char *programa = NULL;
	char *argumentos = NULL;

	while ((c = getopt (argc, argv, "n:p:a:")) != -1)
        	switch (c)
    		{
        		case 'n':
            			nflag = 1;
            			n = atoi(optarg);
				break;
        		case 'p':
            			pflag = 1;
				programa = optarg;
            			break;
			case 'a':
				aflag = 1;
				argumentos = optarg;
				break;
        		default:
            			abort ();
    		}
	

	if(nflag != 1 || pflag != 1){
		printf("El programa necesita por lo menos dos argumentos -n y -p para comenzar\n");
		exit(0);
	} 

   	pid_t pid;
   	int estado, i;
    
	for(i = 0; i < n; i++)
	{
    		pid = fork();
    
    		if (pid == -1)
    		{
        		printf("Error al crear el proceso hijo \n");
    		}
    		else if (pid == 0)
    		{
			 
			if(aflag == 1){
				char *str = (char *) malloc(5 * sizeof(char));
				*str = '-';
				execlp(programa, programa, strcat(str, argumentos), NULL);
				free(str);
			}
			else{
				execlp(programa, programa, NULL);
        		}
			exit(0);
    		}
    		else {
        
        		if (waitpid(pid, &estado, 0) != -1)
        		{
            			if (WIFEXITED(estado)){}
        		}	
        
    		}
    

	}

	if(aflag == 0){
                printf("\nCon un argumento de -a espacio y el argumento del programa sin -, se activa el argumento del programa a ejecutar\n" \
                        "ejemplo, para activar ls -l, se pone ./a.out -n 2 -p ls -a l\n");
        }
    	return 0;
}
