#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#define N 50
#define PROCESADORES 5

void *central(void *);
void *procesar(void *);
void handler(int);
int soluciona(int, int, int, int **);

int main() {

    int **tablero = (int **) malloc(N * N * sizeof(int *));
    int *arreglo = (int *) malloc(N * N * sizeof(int));
    int i, j;

    srand((int) time(NULL));

    for (i = 0; i < N; ++i) {
        int *temp = (int *) malloc(N * sizeof(int));
        for (j = 0; j < N; ++j) {

            int numero = 0;
            numero = (rand() % 10) + 1;
            if (10 > numero)
                temp[j] = 0;
            else if (((i + 1) == PROCESADORES && (j + 1) == PROCESADORES) ||
                    ((i + 1) == (PROCESADORES + 1) && (j + 1) == (PROCESADORES + 1)))
                temp[j] = 0;
            else
                temp[j] = 1;
        }
        tablero[i] = temp;
    }

    int k = 0;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            arreglo[k] = tablero[i][j];
            k++;
        }
    }

    pthread_t centro;

    pthread_create(&centro, NULL, central, (void *)arreglo);

    pthread_join(centro, NULL);

    free(tablero);
    free(arreglo);
    return 0;
}

void *central(void *a){
    int *arreglo = (int *) a;
    int i, j, k;

    pthread_t procesos[N/PROCESADORES];

    for (i = 0; i < N; i += PROCESADORES) {
        int *temp = (int *) malloc(PROCESADORES * PROCESADORES * sizeof(int));

        int l = 0;
        for (j = 0; j < PROCESADORES; ++j) {
            for (k = 0; k < PROCESADORES; ++k) {
                temp[l] = arreglo[(((j + i) * N)) + (k + i)];
                l++;
            }
        }
        pthread_create(&procesos[i / PROCESADORES], NULL, procesar, (void *)temp);
    }


    for (i = 0; i < N; i += PROCESADORES) {
        pthread_join(procesos[i / PROCESADORES], NULL);
    }

    pthread_exit(NULL);
}

void *procesar(void *m){
    int *matriz = (int *)m;
    int i = 0;
    int j = 0;

    int **miniTabla = (int **) malloc(PROCESADORES * PROCESADORES * sizeof(int *));

    for (i = 0; i < PROCESADORES; ++i) {
        int *temp = (int *) malloc(PROCESADORES * sizeof(int));
        for (j = 0; j < PROCESADORES; ++j) {
            temp[j] = matriz[(i * PROCESADORES) + j];
        }
        miniTabla[i] = temp;
    }

    int pasos = soluciona(0, 0, 0, miniTabla);

    printf("Numero de pasos ejecutados en este thread %d\n", pasos);

    free(miniTabla);
    pthread_exit(NULL);
}

int soluciona(int i, int j, int pasos, int **m){

    if ((i + 1) == PROCESADORES && (j + 1) == PROCESADORES){
        return pasos + 1;
    } else if((i + 1) < PROCESADORES && (j + 1) < PROCESADORES && m[i + 1][j + 1] == 0) {
        if (signal(SIGUSR1,handler) == SIG_ERR)
            printf("La senal no sirve\n");
        soluciona(i + 1, j + 1, pasos + 1, m);
    } else if ((i + 1) < PROCESADORES && (j + 1) < PROCESADORES && m[i + 1][j] == 0){
        soluciona(i + 1, j + 1, pasos + 2, m);
    } else if ((i + 1) < PROCESADORES && (j + 1) < PROCESADORES && m[i][j + 1] == 0){
        soluciona(i, j + 1, pasos + 1, m);
    } else if((i + 1) < PROCESADORES && (j + 1) < PROCESADORES && m[i - 1][j] == 0){
        soluciona((i + 1) < PROCESADORES && (j + 1) < PROCESADORES && i - 1, j, pasos + 1, m);
    } else if((i + 1) < PROCESADORES && (j + 1) < PROCESADORES && m[i - 1][j + 1] == 0){
        soluciona(i - 1, j + 1, pasos + 1, m);
    }

}

void handler(int sen) {
    printf("llevamos %d \n", sen);
    sleep(2);
}