#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int sharedResource = 0;
pthread_mutex_t mutex; // Mutex para controlar o acesso ao recurso compartilhado

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
        usleep(10);
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_t thread2;

    pthread_mutex_init(&mutex, NULL); // Inicializar o mutex para controlar o acesso ao recurso compartilhado

    pthread_create(&thread1, NULL, threadFunction, (void *)1); // Criar a primeira thread
    pthread_create(&thread2, NULL, threadFunction, (void *)2); // Criar a segunda thread

    pthread_join(thread1, NULL); // Aguardar a primeira thread terminar
    pthread_join(thread2, NULL); // Aguardar a segunda thread terminar

    pthread_mutex_destroy(&mutex); // Destruir o mutex após não ser mais necessário

    return 0;
}

