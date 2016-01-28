#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int f;
	char * c;
	int e;
} es;

int main(){

	char * str = "hola";
	char * puntero;	
	
	es * pun = (es *) malloc(3 * sizeof(es));
	es temp;
	temp.f = 5;
	temp.c = "Hola";
	temp.e = 20;
	//*pun = temp;
	
	printf("str: %s\n", str);
	printf("str apuntador: %c\n", *str);

	puntero = str + (strlen(str) - 1);

	printf("que carajos %d\n", strlen(str));

	printf("str: %s\n", puntero);
        printf("str apuntador: %c\n", *puntero);

	pun++;
	printf("pum: %d\n", *pun);

	return 0;
}
