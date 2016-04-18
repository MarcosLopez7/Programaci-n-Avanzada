#include <stdio.h>
#include <omp.h>

#define N 1000000

int main(int argc, const char * argv[]) {
    
    int tid;
    int i;
    int suma = 0;
    double inicio, fin;
    
    inicio = omp_get_wtime();
#pragma omp parallel private(i, tid) reduction(+:suma)
    {
       // tid = omp_get_thread_num();
        
#pragma omp for schedule(guided,1000)
        for (i = 0; i < N; ++i) {
            suma += i;
        }
        
      //  printf("Soy el hilo %d y mi Suma = %d \n", tid, suma);
    }
    
    fin = omp_get_wtime();
    
   printf("Tiempo  = %f \n", fin-inicio);
    
    
    return 0;
}
