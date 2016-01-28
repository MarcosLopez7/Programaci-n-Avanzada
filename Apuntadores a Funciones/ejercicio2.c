#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Tipos de funciones */

typedef int (*t_compare)(void *, void *);

typedef void (*t_swap)(void * , void * );

typedef void (*t_sort)(void *, size_t, size_t, t_compare, t_swap );

/* Funciones genéricas */

void sort(t_sort, void *, size_t , size_t, t_compare, t_swap );

void quicksort(void * vector, size_t count, size_t size, t_compare compare, t_swap swap );

int main(){



	return 0;
}

void insertionSort(void * vector, size_t count, size_t size, t_compare compare, t_swap swap )
{
    void * j;
    void * start = vector;
    void * aux = start;
    void * last = start + (count * size);
    
    for (; aux < last ; aux+=size)
    {
        j = aux - size;
        while (j >= start && (*compare)(j, j+size) )
        {
            (*swap)(j+size, j);
            j-=size;
        }
    }
}

void quicksort( int p, int u, bool menor(T, T), bool mayor(T, T))^M
{

        int izquierdo = p;
        int derecho = u;
        void * temp;

        void * pivote = arreglo[p];

        if (p < u)
        {

                while (izquierdo < derecho)
                {
                        while ((izquierdo < derecho) && (menor(arreglo[izquierdo], pivote))) izquierdo++;
                        while (mayor(arreglo[derecho], pivote)) derecho--;
                        if (izquierdo < derecho)
                        {
                                temp = arreglo[derecho];
                                arreglo[derecho] = arreglo[izquierdo];
                                arreglo[izquierdo] = temp;
                        }
                }


                temp = arreglo[derecho];
                arreglo[derecho] = arreglo[p];
                arreglo[p] = temp;


                quicksort(p, derecho - 1, menor, mayor);
                quicksort(izquierdo, u, menor, mayor);
        }
}
