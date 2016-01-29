#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 100

typedef struct{
	char *nombre;
	int edad;
	int *respuesta;
} persona;

void agregar(persona *, int);
void destructor(persona *, int);
void histograma(persona *, int);

char **preguntas;

int main(){

	int n;
		
	printf("\nCuantas personas van hacer la encuesta?\n");
	scanf("%d", &n);

	persona *personas = (persona *) malloc(n * N * sizeof(persona));
	preguntas = (char **) malloc(10 * N * sizeof(char *));
	*(preguntas + 0) = "Pregunta 1";
        *(preguntas + 1) = "Pregunta 2";
        *(preguntas + 2) = "Pregunta 3";
        *(preguntas + 3) = "Pregunta 4";
        *(preguntas + 4) = "Pregunta 5";
        *(preguntas + 5) = "Pregunta 6";
        *(preguntas + 6) = "Pregunta 7";
        *(preguntas + 7) = "Pregunta 8";
        *(preguntas + 8) = "Pregunta 9";
        *(preguntas + 9) = "Pregunta 10";
	srand((int) time(NULL));

	agregar(personas, n);
	histograma(personas, n);
	destructor(personas, n);
	free(preguntas);
	return 0;
}

void agregar(persona *p, int n){
	persona *pPuntero = p;
	int i, j;

	char ** c = preguntas;

	for(i = 0; i < n; ++i){
		persona temp;
		printf("\nDame nombre\n");
		temp.nombre = (char *) malloc(N * sizeof(char));
		scanf("%s", temp.nombre);
		printf("Dame edad\n");
		do{
			scanf("%d", &temp.edad);
			if(120 < temp.edad || temp.edad < 18)
				printf("\nTu edad no sirve para esta encuesta, pero te dejamos hacer trampa, pon otra edad falsa ;)\n");

		}while(120 < temp.edad || temp.edad < 18);
		
		temp.respuesta = (int *)malloc(10 * sizeof(int));
		int *r = temp.respuesta;
		c = preguntas;		

		for(j = 0; j < 10; ++j){
			printf("%s ", *c);
			*r = (rand() % 6) + 1;
			printf("respuesta: %d\n", *r);
			r++;
			c++;		
		}
		*pPuntero = temp;
		pPuntero++;	
	}

}

void histograma(persona *p, int n){
	int i, j, k;
	persona *pPuntero = p;
 
	printf("\nRango de 18 a 25\n");
		
	int r1[10][6] = { 
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};

	for(i = 0; i < n; ++i){
		int (*r)[6] = r1;
		if(25 >= (*pPuntero).edad && (*pPuntero).edad >= 18){
			int * res = (*pPuntero).respuesta;
			for(j = 0; j < 10; ++j){
				(*((*r) + (*res - 1)))++;
				res++;
				r++;
			}
		}
		pPuntero++;	
	}
		
	char **c = preguntas;
	int (*rd1)[6] = r1;
	for(i = 0; i < 10; ++i){
		printf("\n%s\n", *c);
		printf("No	Respuesta	Frecuencia\n");		

		for(j = 0; j < 6; ++j){
			printf("%d	%d		", j + 1, *((*rd1) + j));
			for(k = 0; k < *((*rd1) + j); ++k)
				printf("*");
			printf("\n");		
		}
		rd1++;
		c++;	
	}
	printf("\nRango de 26 a 35\n");
		
	pPuntero = p;

	int r2[10][6] = { 
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};	

	for(i = 0; i < n; ++i){
		int (*r)[6] = r2;
		if(35 >= (*pPuntero).edad && (*pPuntero).edad >= 26){
			int * res = (*pPuntero).respuesta;
			for(j = 0; j < 10; ++j){
				(*((*r) + (*res - 1)))++;
				res++;
				r++;
			}
		}
		pPuntero++;	
	}
		
	c = preguntas;
	int (*rd2)[6] = r2;
	for(i = 0; i < 10; ++i){
		printf("\n%s\n", *c);
		printf("No	Respuesta	Frecuencia\n");		

		for(j = 0; j < 6; ++j){
			printf("%d	%d		", j + 1, *((*rd2) + j));
			for(k = 0; k < *((*rd2) + j); ++k)
				printf("*");
			printf("\n");		
		}
		rd2++;
		c++;	
	}

	printf("\nRango de 36 a 45\n");
	
	pPuntero = p;
	
	int r3[10][6] = { 
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};	

	for(i = 0; i < n; ++i){
		int (*r)[6] = r3;
		if(45 >= (*pPuntero).edad && (*pPuntero).edad >= 36){
			int * res = (*pPuntero).respuesta;
			for(j = 0; j < 10; ++j){
				(*((*r) + (*res - 1)))++;
				res++;
				r++;
			}
		}
		pPuntero++;
	}
		
	c = preguntas;
	int (*rd3)[6] = r3;
	for(i = 0; i < 10; ++i){
		printf("\n%s\n", *c);
		printf("No	Respuesta	Frecuencia\n");		

		for(j = 0; j < 6; ++j){
			printf("%d	%d		", j + 1, *((*rd3) + j));
			for(k = 0; k < *((*rd3) + j); ++k)
				printf("*");
			printf("\n");		
		}
		rd3++;
		c++;	
	}

	printf("\nRango de 46 a 65\n");
	
	pPuntero = p;
	
	int r4[10][6] = { 
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};	

	for(i = 0; i < n; ++i){
		int (*r)[6] = r4;
		if(65 >= (*pPuntero).edad && (*pPuntero).edad >= 46){
			int * res = (*pPuntero).respuesta;
			for(j = 0; j < 10; ++j){
				(*((*r) + (*res - 1)))++;
				res++;
				r++;
			}
		}
		pPuntero++;	
	}
		
	c = preguntas;
	int (*rd4)[6] = r4;
	for(i = 0; i < 10; ++i){
		printf("\n%s\n", *c);
		printf("No	Respuesta	Frecuencia\n");		

		for(j = 0; j < 6; ++j){
			printf("%d	%d		", j + 1, *((*rd4) + j));
			for(k = 0; k < *((*rd4) + j); ++k)
				printf("*");
			printf("\n");		
		}
		rd4++;
		c++;	
	}

	printf("\nRango de 66 a 120\n");

	pPuntero = p;	

	int r5[10][6] = { 
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};	

	for(i = 0; i < n; ++i){
		int (*r)[6] = r5;
		if(120 >= (*pPuntero).edad && (*pPuntero).edad >= 66){
			int * res = (*pPuntero).respuesta;
			for(j = 0; j < 10; ++j){
				(*((*r) + (*res - 1)))++;
				res++;
				r++;
			}
		}
		pPuntero++;	
	}
		
	c = preguntas;
	int (*rd5)[6] = r5;
	for(i = 0; i < 10; ++i){
		printf("\n%s\n", *c);
		printf("No	Respuesta	Frecuencia\n");		

		for(j = 0; j < 6; ++j){
			printf("%d	%d		", j + 1, *((*rd5) + j));
			for(k = 0; k < *((*rd5) + j); ++k)
				printf("*");
			printf("\n");		
		}
		rd5++;
		c++;	
	}

}

void destructor(persona *p, int n){
	
	int i;
	persona *pPuntero = p;

	for(i = 0; i < n; ++i){
		free((*pPuntero).nombre);
		free((*pPuntero).respuesta);
		pPuntero++;
	}

	free(p);
}
