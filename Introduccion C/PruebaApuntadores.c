#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char * str = "hola";
	char * puntero;	

	printf("str: %s\n", str);
	printf("str apuntador: %c\n", *str);

	puntero = str + (strlen(str) - 1);

	printf("que carajos %d\n", strlen(str));

	printf("str: %s\n", puntero);
        printf("str apuntador: %c\n", *puntero);

	return 0;
}
