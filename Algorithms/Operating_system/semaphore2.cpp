#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5  // Number of readers
#define NUM_WRITERS 2  // Number of writers

int data = 0, read_count = 0;  // Shared resource and reader count
sem_t mutex, wrt;  // Semaphores for synchronization

// Reader function
void *reader(void *arg) {
    int id = *((int *)arg);
    while (1) {
        sem_wait(&mutex);  // Lock access to read_count
        read_count++;
        if (read_count == 1)  
            sem_wait(&wrt);  // First reader blocks writers
        sem_post(&mutex);  // Unlock access to read_count

        printf("Reader %d reads data: %d\n", id, data);

        sem_wait(&mutex);  // Lock access to read_count
        read_count--;
        if (read_count == 0)  
            sem_post(&wrt);  // Last reader allows writers
        sem_post(&mutex);  // Unlock access to read_count

        usleep(rand() % 100000);  // Simulate delay
    }
    return NULL;
}

// Writer function
void *writer(void *arg) {
    int id = *((int *)arg);
    while (1) {
        sem_wait(&wrt);  // Wait for exclusive access
        data++;  // Modify the shared resource
        printf("Writer %d writes data: %d\n", id, data);
        sem_post(&wrt);  // Release exclusive access

        usleep(rand() % 100000);  // Simulate delay
    }
    return NULL;
}

int main() {
    pthread_t r_threads[NUM_READERS], w_threads[NUM_WRITERS];
    int ids[NUM_READERS > NUM_WRITERS ? NUM_READERS : NUM_WRITERS];

    sem_init(&mutex, 0, 1);  // Initialize mutex semaphore
    sem_init(&wrt, 0, 1);  // Initialize writer semaphore

    for (int i = 0; i < NUM_READERS; i++) {
        ids[i] = i + 1;
        pthread_create(&r_threads[i], NULL, reader, &ids[i]);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        ids[i] = i + 1;
        pthread_create(&w_threads[i], NULL, writer, &ids[i]);
    }
    for (int i = 0; i < NUM_READERS; i++)
        pthread_join(r_threads[i], NULL);
    for (int i = 0; i < NUM_WRITERS; i++)
        pthread_join(w_threads[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}
