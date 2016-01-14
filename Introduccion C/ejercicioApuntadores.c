#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void ejercicio1(){
	char * str = (char *) malloc(6 * sizeof(char));
	char * strTemp = (char *) malloc(6 * sizeof(char));	

	fgets(str, 100, stdin);
	int i;

	for(i = strlen(str) - 1; i >= 0; i--){
		strTemp[strlen(str)-i-1] = str[i];
	}
	
	printf("voleado es: %s\n", strTemp);

	free(str);
	free(strTemp);
}

void ejercicio2(){

	char * str = (char *) malloc(100 * sizeof(char));	
	int i = 0;
	fgets(str, 100, stdin);

	while(str[i] != '\0'){
		i++;
	}

	printf("La longitud es de: %d\n", i-1);

	free(str);
}

void ejercicio3(){

	char * str = (char *) malloc(100 * sizeof(char));
	char * strTemp = (char *) malloc(100 * sizeof(char));	
	int i = 0;
	
	fgets(str, 100, stdin);
 
}

void ejercicio4(){

	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);	

	int ** y = (int **) malloc(n * sizeof(int *));

	int i, j;

	for(i = 0; i < n; i++){
		int * x = (int *) malloc(n * sizeof(int));
		for(j = 0; j < m; j++){
			scanf("%d", &x[j]);
		}
		y[i] = x;
		free(x);
	}

	for(i = 0; i < n; i++){
                for(j = 0; j < m; j++){
                        printf("%d ", y[i][j]);
                }
		printf("\n");
        }

	free(y);	

}
