#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[]){

	
	int n = atoi(argv[1]);
	int *pipes = (int *) malloc(n * 2 * sizeof(int ));
	int i;
	
	int *pP = pipes;

	for(i = 0; i < n * 2; ++i){
		int temp[2];
		temp[0] = *pP;
		pP++;
		temp[1] = *pP;
		pipe(temp);
		pP++;	
	}

	pP = pipes;	
	pid_t childpid;

	for(i = 0; i < n; ++i)
	{
		if((childpid = fork()) == -1)
        	{
                	perror("fork");
                	exit(1);
        	}

        	if(childpid == 0)
        	{

			if(i != 0){
				close(*pP);
				pP--;
				int res;
				read(*pP, &res, sizeof(int));
				printf("Soy el testigo %d\n", res);
				pP += 2;

			}
			
                	close(*pP);
	
			pP++;
			
			printf("%d\n", i);	
                	write(*pP, &i, sizeof(int));

			free(pipes);
			exit(0);
        	}
        	else
        	{
 			if((i + 1) == n){
				close(*pP);
                                pP--;
                                int res;
                                read(*pP, &res, sizeof(int));
                                printf("Soy el testigo %d\n", res);
                                pP += 2;
			
			}
	       	}
	}
	free(pipes);
	return 0;
}
