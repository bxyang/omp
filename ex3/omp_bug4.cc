#include <omp.h>
#include <cstdlib>
#include <cstdio>

#define N 512

int main(int argc, char *argv[]) {
    int nthreads, tid, i, j;
    double a[N][N];

    #pragma omp parallel shared(nthreads) private(i, j, tid, a)
    {
        tid = omp_get_thread_num();
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }

        printf("Thread %d is starting...\n", tid);

        for (i = 0; i < N; i++) 
            for (j = 0; j < N; j++)
                a[i][j] = tid + i * j;

        printf("Thread %d is done. Last element = %f\n", tid, a[N-1][N-1]);
    }
}
