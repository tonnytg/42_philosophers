#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread(void *arg) {
	int thread_num = *(int *)arg;
	printf("Hello from thread %d\n", thread_num);
	return NULL;
}

int main(void) {
	int i;
	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS];

	i = 0;
	while (i < NUM_THREADS) {
		thread_args[i] = i;
		pthread_create(&threads[i], NULL, thread, &thread_args[i]);
		i++;
	}

	i = 0;
	while (i < NUM_THREADS) {
		pthread_join(threads[i], NULL);
		i++;
	}

	return 0;
}
