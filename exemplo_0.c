#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void hello(void); // Função que será chamada dentro de cada Thread

int main(int argc, char* argv[]) {
    int threads_count = strtol(argv[1], NULL, 10);

    #pragma omp parallel num_threads(threads_count)
    hello();

    return 0;
}


void hello(void) {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    printf("Hello from the thread %d of %d.\n", my_rank, thread_count);
}
