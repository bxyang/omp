
#include <omp.h>
#include <cstdio>
#include <cstdlib>

#define N 50

int main(int argc, char *argv[]) {
    int nthreads, i, tid, section;
    float a[N], b[N], c[N];
    void print_results(float array[N], int tid, int section);    

    for (i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;

    #pragma omp parallel private(tid, i)
    {
        tid = omp_get_thread_num();
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }

        printf("Thread %d is starting...\n", tid);
        #pragma omp barrier

        #pragma omp for reduction(+:total) schedule(dynamic, 10)
        for (i = 0; i < 1000; i++)
            total = total + i * 1.0;

        printf("Thread %d is done! Total = %e\n", tid, total);
    }
}
