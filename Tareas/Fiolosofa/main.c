#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define NF 5

pthread_mutex_t palillos_mutex[NF];

void *filosofo(void *);
int palillos[NF];

int main() {

  int i;

  srand((int)time(NULL));

  for (i = 0; i < NF; ++i) {
    palillos[i] = 1;
  }

  pthread_t filosofar[NF];

  for (i = 0; i < NF; ++i) {
    int *arg = malloc(sizeof(*arg) * 2);

    if (i == 0) {
      *arg = 5;
    } else {
      *arg = i - 1;
    }
    arg++;
    *arg = i;
    arg--;

    pthread_create(&filosofar[i], NULL, filosofo, (void *)arg);
  }

  for (i = 0; i < NF; ++i) {
    pthread_join(filosofar[i], NULL);
  }

  return 0;
}

void *filosofo(void *p) {
  int *palos = (int *)p;

  while (1) {

    pthread_mutex_lock(&palillos_mutex[*palos]);
    pthread_mutex_lock(&palillos_mutex[*(palos + 1)]);

    if (palillos[*palos] && palillos[*(palos + 1)]) {
      palillos[*palos] = 0;
      palillos[*(palos + 1)] = 0;

      pthread_mutex_unlock(&palillos_mutex[*palos]);
      pthread_mutex_unlock(&palillos_mutex[*(palos + 1)]);

      printf("Filosofo %d: voy a comer\n", *(palos + 1));
      sleep(5);

      pthread_mutex_lock(&palillos_mutex[*palos]);
      pthread_mutex_lock(&palillos_mutex[*(palos + 1)]);

      palillos[*palos] = 1;
      palillos[*(palos + 1)] = 1;

      pthread_mutex_unlock(&palillos_mutex[*palos]);
      pthread_mutex_unlock(&palillos_mutex[*(palos + 1)]);

      printf("Filosofo %d: voy a pensar\n", *(palos + 1));

      sleep((rand() % 10) + 10);

      printf("Filosofo %d: voy a comer, necesito, pensar\n", *(palos + 1));
    } else {
      pthread_mutex_unlock(&palillos_mutex[*palos]);
      pthread_mutex_unlock(&palillos_mutex[*(palos + 1)]);
      sleep(1);
    }
  }

  free(p);
  pthread_exit(NULL);
}
