#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 255


void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();

int main(){

	//ejercicio1();	
	//ejercicio2();	
	//ejercicio3();	
	ejercicio4();
	return 0;
}

void ejercicio4(){

	int n, m, i, j;
	scanf("%d", &n);
	scanf("%d", &m);

	int ** matriz = (int **) malloc(n * sizeof(int *));
	int ** p = &matriz[0][0];

	for(i = 0; i < n; i++){
		int * temp = (int *) malloc(m * sizeof(int));
		for(j = 0; j < m; j++){
			scanf("%d", &temp[j]);
		}
		matriz[i] = temp;
		free(temp);
	}

	while(&matriz[0][0] > (p - (n * m))){
		
	}
		
}

void ejercicio3(){
	char * palabra = (char *) malloc(N * sizeof(char));
        char * copia = (char *) malloc(N * sizeof(char));
	char * p = palabra;	
	char * c = copia;

	fgets(palabra, N * sizeof(char), stdin);
	

	while(*p != '\0'){
		*c = *p;
		c++;
		p++;
	}

	printf("copia que pasa?: %s\n", copia);

	free(palabra);
}

void ejercicio2(){

	char * palabra = (char *) malloc(N * sizeof(char));
	fgets(palabra, N * sizeof(char), stdin);

	char * p = palabra;
	int i = 0;

	while(*p != '\0'){
		i++;
		p++;	
	}	

	printf("length: %d\n", i);
	printf("length 2: %d\n", strlen(palabra));

	free(palabra);

}

void ejercicio1(){
	
	char * palabra = (char *) malloc(N * sizeof(char));
	char * volteado, * last;
	fgets(palabra, N * sizeof(char), stdin);
	
	volteado = &palabra[strlen(palabra) - 2];
	last = &palabra[strlen(palabra) - 1];
	int length = strlen(palabra);

	while (length > strlen(volteado)){
		printf("%s\n", (--volteado));

		volteado--;
		volteado = last;
		volteado++;
		volteado = volteado - 1;
		volteado--;
	}

	printf("%s\n", volteado);

	
	free(palabra);
}
