#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ejercicio1();

int main(){

	ejercicio1();
	
	return 0;
}

void ejercicio1(){
	
	char * palabra = (char *) malloc(10 * sizeof(char));

	char * p = palabra;

	fgets(palabra, 10, stdin);

	char * matriz = (char *) malloc(10 * sizeof(char) * 3);
	char * m = matriz;
	*m = '\0';

	int * f = (int *) malloc(10 * sizeof(int));


	while(*p != '\0'){
		 while(1){
			if(*m == *p){
				f[m - matriz]++;
				m = matriz;
				break;
			}
			else if(*m == '\0'){
				*m = *p;
				f[m - matriz]++;
                                m = matriz;	
				break;
			}

			m++;	
		}	
		p++;
	}

	m = matriz;
	
	printf("Letras  Frecuencia%c\n", *m);
	int i;

	while(*m != '\0'){
		printf("%c	%d", *m, *f);
		for(i = 0; i < *f; i++){
			printf(" * ");
		}	
		printf("\n");
		m++;
		f++;
	}

	free(f);
	free(palabra);
	free(matriz);
}
