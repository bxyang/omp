
#include <omp.h>
#include <cstdlib>
#include <cstdio>


// g++ -fopenmp omp_hello.cc


int main(int argc, char *argv[]) {
    int nthreads, tid;
    #pragma omp parallel private(nthreads, tid) 
    {
        tid = omp_get_thread_num();
        printf("hello world from thead = %d\n", tid);
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
    }
}

