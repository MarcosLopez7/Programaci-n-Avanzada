#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define N 5000

typedef struct Dato{
    float x;
    float y;
    Dato *c;
};

int main() {

    Dato tabla[N];
    int i;

    srand((int) time(NULL));

#pragma omp parallel shared(tabla) private(i)
    {
#pragma omp for schedule(auto)
        for (i = 0; i < N; ++i){
            tabla[i].x = (rand() % 100) / 100;
            tabla[i].y = (rand() % 100) / 100;
        }
    }


    return 0;
}