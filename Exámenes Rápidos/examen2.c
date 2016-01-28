#include <stdlib.h>
#include <stdio.h>
#define N 5

struct Libro{
	char *titulo;
	int paginas;
};


typedef void (*t_int) ( void *);

void interator(t_int, void *);

void fordwar(void *);
void bidirectional(void *);
void reverse(void *);

int main(){

	int *a = (int *) malloc(N * sizeof(int));
 	
	*a = 1;
	*(a + 1) = 2;
	*(a + 2) = 3;
	*(a + 3) = 4;	
	*(a + 4) = 5;

	struct Libro *libros = (struct Libro *) malloc(N * sizeof(struct Libro));
		
	(*libros).titulo = "Libro 1";
	(*libros).paginas = 20;
	(*(libros + 1)).titulo = "Libro 2"; 
	(*(libros + 1)).paginas = 40;
	(*(libros + 2)).titulo = "Libro 3";
        (*(libros + 2)).paginas = 60;
	(*(libros + 3)).titulo = "Libro 4";
        (*(libros + 3)).paginas = 45;
	(*(libros + 4)).titulo = "Libro 5";
        (*(libros + 4)).paginas = 100;


	interator( &fordwar, a);
	interator( &bidirectional, libros);

	free(a);
	free(libros);
	return 0;
}

void interator(t_int inte, void *vector){
	(*inte)(vector);
}

void fordwar(void *vector){
	
	void *v = vector;
	int i = 0;

	while(N > i){
		printf("%d ", *((int *) v));
		v++;
		i++;
	}
	
	printf("\n");
}

void bidirectional(void *vector){

	struct Libro *v1 = (struct Libro *) vector;
	struct Libro *v2 = (struct Libro *) (vector + N);


	while(v2 > v1){
		printf("%s ", (*v1).titulo);
		printf("%s ", (*v2).titulo);
		v1++;
		v2--;
	}

	printf("\n");

}

void reverse(void * vector){
	void *v = (vector + N);

	while(v > vector){
		v--;
	}
	
} 
