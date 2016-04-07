#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define S 3

pthread_mutex_t tabaco;
pthread_mutex_t papel;
pthread_mutex_t lanzaLLamas;
pthread_mutex_t ocupado0;
pthread_mutex_t ocupado1;
pthread_mutex_t ocupado2;

int hay_tabaco;
int hay_papel;
int hay_lanzaLLamas;
int esta_ocupado0;
int esta_ocupado1;
int esta_ocupado2;

void *agente(void *);
void *fumador(void *);
void fumar(int);

int main() {

  pthread_t agente_cancerigeno;
  pthread_t fumadores[S];

  int *arg0, *arg1, *arg2;
  arg0 = (int *)malloc(sizeof(*arg0));
  arg1 = (int *)malloc(sizeof(*arg1));
  arg2 = (int *)malloc(sizeof(*arg2));
  *arg0 = 0;
  *arg1 = 1;
  *arg2 = 2;

  pthread_create(&agente_cancerigeno, NULL, agente, NULL);
  pthread_create(&fumadores[0], NULL, fumador, arg0);
  pthread_create(&fumadores[1], NULL, fumador, arg1);
  pthread_create(&fumadores[2], NULL, fumador, arg2);

  pthread_join(agente, NULL);
  pthread_join(fumadores[0], NULL);
  pthread_join(fumadores[1], NULL);
  pthread_join(fumadores[2], NULL);

  return 0;
}

void *agente(void *arg) {

  while (1) {
    pthread_mutex_lock(&tabaco);
    if (hay_tabaco) {
      pthread_mutex_unlock(&tabaco);
    } else {
      pthread_mutex_lock(&ocupado0);
      if (esta_ocupado0) {
        printf("Apurate maldito fumador con el tabaco\n");
        pthread_mutex_unlock(&ocupado0);
        pthread_mutex_unlock(&tabaco);
      } else {
        printf("Gracias por el tabaco\n");
        hay_tabaco = 1;
        pthread_mutex_unlock(&ocupado0);
        pthread_mutex_unlock(&tabaco);
        sleep(15);
      }
    }

    if (hay_papel) {
      pthread_mutex_unlock(&papel);
    } else {
      pthread_mutex_lock(&ocupado1);
      if (esta_ocupado1) {
        printf("Apurate maldito fumador con el papel\n");
        pthread_mutex_unlock(&ocupado1);
        pthread_mutex_unlock(&papel);
      } else {
        printf("Gracias por el papel\n");
        hay_papel = 1;
        pthread_mutex_unlock(&ocupado1);
        pthread_mutex_unlock(&papel);
        sleep(15);
      }
    }

    if (hay_lanzaLLamas) {
      pthread_mutex_unlock(&lanzaLLamas);
    } else {
      pthread_mutex_lock(&ocupado2);
      if (esta_ocupado2) {
        printf("Apurate maldito fumador con el fuego\n");
        pthread_mutex_unlock(&ocupado2);
        pthread_mutex_unlock(&lanzaLLamas);
      } else {
        printf("Gracias por el fuego\n");
        hay_lanzaLLamas = 1;
        pthread_mutex_unlock(&ocupado2);
        pthread_mutex_unlock(&lanzaLLamas);
        sleep(15);
      }
    }
  }
}

void *fumador(void *arg) {

  int m = *((int *)arg);

  while (1) {
    if (m == 0) {
      fumar(0);
    } else if (m == 1) {
      fumar(1);
    } else if (m == 2) {
      fumar(2);
    } else {
      printf("Algo salio pero muy mal!!!\n");
    }
  }
}

void fumar(int m) {
  pthread_mutex_lock(&tabaco);
  pthread_mutex_lock(&papel);
  pthread_mutex_lock(&lanzaLLamas);

  if (hay_lanzaLLamas && hay_papel && hay_tabaco) {

    printf("Me voy a echar un rico cigarro\n");
    hay_lanzaLLamas = 0;
    hay_papel = 0;
    hay_tabaco = 0;

    pthread_mutex_unlock(&tabaco);
    pthread_mutex_unlock(&papel);
    pthread_mutex_unlock(&lanzaLLamas);

    if (m == 0) {
      pthread_mutex_lock(&ocupado0);
      esta_ocupado0 = 1;
      pthread_mutex_unlock(&ocupado0);
    } else if (m == 1) {
      pthread_mutex_lock(&ocupado1);
      esta_ocupado1 = 1;
      pthread_mutex_unlock(&ocupado1);
    } else if (m == 2) {
      pthread_mutex_lock(&ocupado2);
      esta_ocupado2 = 1;
      pthread_mutex_unlock(&ocupado2);
    } else {
      printf("Algo salio pero muy mal!!!\n");
    }

    sleep(10);
    printf("Listo, voy a esperarme o me va dar cancer\n");

    if (m == 0) {
      pthread_mutex_lock(&ocupado0);
      esta_ocupado0 = 0;
      pthread_mutex_unlock(&ocupado0);
    } else if (m == 1) {
      pthread_mutex_lock(&ocupado1);
      esta_ocupado1 = 0;
      pthread_mutex_unlock(&ocupado1);
    } else if (m == 2) {
      pthread_mutex_lock(&ocupado2);
      esta_ocupado2 = 0;
      pthread_mutex_unlock(&ocupado2);
    } else {
      printf("Algo salio pero muy mal!!!\n");
    }

    sleep(20);
    printf("Ya puedo fumar\n");

  } else {
    // printf("Ya apurensennn con los ingredientes que quiero un cigarro\n");
    pthread_mutex_unlock(&tabaco);
    pthread_mutex_unlock(&papel);
    pthread_mutex_unlock(&lanzaLLamas);
  }
}
