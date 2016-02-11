#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invertir(char *);

int main(int argc, char **argv) {
    char * cadena;
    int longitud;
    
    printf("Dame la longitud máxima: ");
    scanf("%d", &longitud);
    
    cadena = (char *) malloc(sizeof(char) * longitud);
    
    printf("Entre una cadena: ");
    scanf("%s", cadena);
    //fgets(cadena, longitud * sizeof(char), stdin);
    
    
    // Invertir una cadena
    invertir(cadena);
    
    printf("Cadena invertida = %s \n", cadena);
    
    free(cadena);
    
    return 0;
}

void invertir(char * cadena)
{
    char l, *p, *d;
    long int c = strlen(cadena);
    p = cadena;
    d = p + (c - 1);
    while (p < d)
    {
	printf("inicio d: %s, p: %s\n", d, p);
        l = *d;
        *d = *p;
        *p = l;
        ++p;
        --d;
	printf("fin d: %s, p: %s\n", d, p); 
   }
    
}
