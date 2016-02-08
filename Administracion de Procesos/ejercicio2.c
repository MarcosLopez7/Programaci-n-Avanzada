#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 5

int *numeros;
void fillArray(int *);
int sum(int *, int, int);

int main(){

	int pid;
        int r1, r2, estado;
	r1 = 0;

	numeros = (int *) malloc(N * sizeof(int));
	srand((int) time(NULL));

	fillArray(numeros);

        pid = fork();

        if (pid == -1){
            	printf("Error\n");
       	} else if (pid == 0){
		r1 = sum(numeros, 0, N/2);		


        } else {
       		if (waitpid(pid, &estado, 0) != -1)
        	{
        		
				r2 = sum(numeros, N/2, N);
				printf("El resultado de la suma es: %d con r1: %d y r2: %d\n", r1 + r2, r1, r2);
					
		}
        }
	
	
	free(numeros);
	return 0;
}

void fillArray(int *n){
	
	int i;	
	int *ptr = n; 

	for (i = 0; i < N; i++)
	{
		printf("que pedo?\n");
		n[i] = rand() % 10;
		printf("%d ", n[i]);
	}		

}

int sum(int *n, int p1, int p2){
	
	int res = 0;
	int i;

	for(i = p1; p1 < p2; ++i){
		res += *n;
		n++;
	}
}
