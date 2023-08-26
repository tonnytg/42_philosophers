#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunction(void *arg) {
	for (int i = 0; i < 5; i++) {
		// Bloquear o mutex antes de acessar o recurso compartilhado
		pthread_mutex_lock(&mutex);

		// Acessar e modificar o recurso compartilhado
		sharedResource++;
		printf("Thread %ld: Incremented sharedResource to %d\n", (long)arg, sharedResource);

		// Desbloquear o mutex após terminar de acessar o recurso
		pthread_mutex_unlock(&mutex);

		// Simular algum processamento na thread
		usleep(100000);
	}

	return NULL;
}

int main(void)
{
	pthread_mutex_t	mutex; // Mutex para controlar o acesso ao recurso compartilhado
	pthread_t		thread1;
	pthread_t		thread2;
	int				sharedResource; // Recurso compartilhado entre as threads

	pthread_mutex_init(&mutex, NULL); // Mutex para controlar o acesso ao recurso compartilhado
	sharedResource = 0;

	pthread_create(&thread1, NULL, threadFunction, (void *)1); // Criar as threads
	pthread_create(&thread2, NULL, threadFunction, (void *)2); // Criar as threads

	pthread_join(thread1, NULL); // Aguardar as threads terminarem
	pthread_join(thread2, NULL); // Aguardar as threads terminarem

	pthread_mutex_destroy(&mutex); // Destruir o mutex após não ser mais necessário

	printf("Hello World\n");
	printf("Start Philosofers\n");
	printf("Eat\n");
	printf("Think\n");
	printf("Sleep\n");
	return 0;
}
