


#include <omp.h>
#include <cstdlib>
#include <cstdio>


#define CHUNKSIZE 10
#define N 40

int main(int argc, char *argv[]) {
    int nthreads, chunk;
    float a[N], b[N], c[N];

    for (int i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;

    chunk = CHUNKSIZE;

    //#pragma omp parallel shared(a, b, c, nthreads, chunk) private(i, tid)
    #pragma omp parallel shared(a, b, c, nthreads, chunk)
    {
        
        int tid = omp_get_thread_num();
        int i = 0;
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
      
        printf("Thread %d starting ... \n", tid);
        
        #pragma omp for schedule (static, chunk)
        for (i = 0; i < N; i++) {
            c[i] = a[i] + b[i];
            printf("Thread %d: c[%d] = %f\n", tid, i, c[i]);
        }
    }
}
