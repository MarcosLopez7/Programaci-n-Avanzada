#include <omp.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

  int nthreads, tid;

#pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();

    printf("Prueba\n");
    if (tid == 0) {
      nthreads = omp_get_num_threads();
      printf("NT: %d\n", nthreads);
    }
  }

  return 0;
}
