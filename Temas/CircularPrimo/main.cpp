#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 10000

char *toArray(int);
int evaluarCircularPrimo(int);
int toInt(char *);
int esPrimo(int);
int moverArray(int);

int main() {

    int *numeros = (int *) malloc(N * N * sizeof(int));
    int *resultados = (int *) malloc(N * N * sizeof(int));
    int i;

    srand((int) time(NULL));

#pragma omp parallel shared(numeros) private(i)
    {
#pragma omp for schedule(auto)
        for (i = 0; i < N; ++i) {
            *(numeros + i) = (rand() % N) + 1;
        }
    }

#pragma omp parallel shared(numeros, resultados) private(i)
    {
#pragma omp for schedule(auto)
        for (i = 0; i < N; ++i) {
            *(resultados + i) = evaluarCircularPrimo( *(numeros + i) );
        }
    }

    for (i = 0; i < N; ++i) {
        printf("numero: %d, primo circular %d\n", *(numeros + i), *(resultados + i));
    }

    free(numeros);
    free(resultados);
    return 0;
}

int evaluarCircularPrimo(int num) {

    int n = floor(log10(abs(num))) + 1;
    int i;

    for (i = 0; i < n; ++i) {
        if (esPrimo(num) == 0){
            return 0;
        } else {
            num = moverArray(num);
        }
    }

    return 1;
}

int esPrimo(int n) {

    int i;

    for (i = 2; i < n; ++i) {
        if ((n % i) == 0) {
            return 0;
        }
    }

    return 1;
}

int toInt(char *str) {

    int n;
    sscanf(str, "%d", &n);

    return n;
}

char *toArray(int number) {

    int n = floor(log10(abs(number))) + 1;
    int i;
    char *numberArray = (char *) calloc(n, sizeof(char));

    for ( i = 0; i < n; ++i, number /= 10 ) {
        numberArray[i] = number % 10;
    }

    return numberArray;

    //sprintf(yourCharArray,"%ld", number)
}

int moverArray(int n) {

    char *strNum = toArray(n);
    int i;
    int len = strlen(strNum);

    if (len > 1) {

        char temp = strNum[0];

        for (i = len - 2; i > -1; --i) {
            strNum[i] = strNum[i + 1];
        }
        strNum[len - 1] = temp;

        return toInt(strNum);
    }

    return n;
}