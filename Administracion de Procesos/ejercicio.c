#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int factorial(int);

int main(){

	pid_t pid;
	int numero;

	while(numero != 0){
		printf("Entre un numero: \n");
		scanf("%d", &numero);
		
		pid = fork();
	
		if(pid == -1){
			printf("Error\n");
		} else if(pid == 0){
			printf("El facto es: %d\n", factorial(numero));	
		
		} else{
			printf("Soy tu padre  y no hago nada, soy huevon\n");
		}
		
	}

	return 0;
}

int factorial(int n){

	int res = 1;
	int i = 0;
	for(i = 1; i <= n; i++)
		res *= i;

	return res;
}
