#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define C 10
#define S 3
#define T 3
#define U 50
#define P 150

pthread_mutex_t mutex_personas[C];
pthread_mutex_t mutex[C][S];
int personas[C];
int capacidad_salas[C][S];

void *fila(void *);
void capacidad(int, int, int);

int main() {

  pthread_t taquillas[C][T];
  int i, j;

  srand((int)time(NULL));

  for (i = 0; i < C; i++) {
    for (j = 0; j < T; j++) {
      int *arg = malloc(sizeof(*arg));
      *arg = i;
      pthread_create(&taquillas[i][j], NULL, fila, arg);
    }
  }

  for (i = 0; i < C; i++) {
    for (j = 0; j < T; j++) {
      pthread_join(taquillas[i][j], NULL);
    }
  }

  return 0;
}

void *fila(void *c) {

  int i = *((int *)c);

  while (P > personas[i]) {
    pthread_mutex_lock(&mutex_personas[i]);

    int p = (rand() % 10) + 1;

    int sala = rand() % 3;

    if (sala == 0) {
      capacidad(sala, p, i);
    } else if (sala == 1) {
      capacidad(sala, p, i);
    } else if (sala == 2) {
      capacidad(sala, p, i);
    } else {
      printf("Algo salio mal :S\n");
    }

    pthread_mutex_unlock(&mutex_personas[i]);
  }

  printf("Complejo %d lleno\n", i);

  free(c);
  pthread_exit(NULL);
}

void capacidad(int s, int p, int i) {
  pthread_mutex_lock(&mutex[i][s]);
  if (U >= (p + capacidad_salas[i][s])) {
    capacidad_salas[i][s] += p;
    personas[i] += p;
    printf("Entraron %d personas en la sala %d, en el complejo %d\n", p, s, i);
    printf("se encuentran ahora %d personas en la sala %d del complejo %d\n",
           capacidad_salas[i][s], s, i);
  } else {
    printf("Lo sentimos, capacidad llena en la sala %d del complejo %d, hay %d "
           "personas\n",
           s, i, capacidad_salas[i][s]);
  }
  pthread_mutex_unlock(&mutex[i][s]);
}
