#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define N 5000

typedef struct Dato{
    float x;
    float y;
    int c;
};

typedef struct Punto {
    float x;
    float y;
};

int main() {

    Dato tabla[N];
    int i;

    Punto c1;
    Punto c2;

    c1.x = (float)(rand() % 1000) / 1000;
    c1.y = (float)(rand() % 1000) / 1000;
    c2.x = (float)(rand() % 1000) / 1000;
    c2.y = (float)(rand() % 1000) / 1000;

    srand((int) time(NULL));

#pragma omp parallel shared(tabla) private(i)
    {
#pragma omp for schedule(auto)
        for (i = 0; i < N; ++i){
            tabla[i].x = (float)(rand() % 1000) / 1000;
            tabla[i].y = (float)(rand() % 1000) / 1000;
            tabla[i].c = (rand() % 2) + 1;
        }
    }

#pragma omp parallel shared(tabla) private(i)
    {
#pragma omp for schedule(auto)
        for (i = 0; i < N; ++i){
            tabla[i].x = (float)(rand() % 1000) / 1000;
            tabla[i].y = (float)(rand() % 1000) / 1000;
            tabla[i].c = (rand() % 2) + 1;
        }
    }

    return 0;
}