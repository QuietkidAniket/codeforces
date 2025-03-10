#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Size of the shared buffer
#define NUM_ITEMS 10   // Number of items to be produced/consumed

int buffer[BUFFER_SIZE];  // Circular buffer
int in = 0, out = 0;      // Indices for producer and consumer

sem_t empty, full;        // Semaphores to track empty and full slots
pthread_mutex_t mutex;    // Mutex to ensure mutual exclusion

// Producer function
void *producer(void *arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&empty);  // Wait if buffer is full
        pthread_mutex_lock(&mutex);  // Lock the buffer access

        buffer[in] = i;  // Insert item into the buffer
        printf("Produced: %d\n", i);
        in = (in + 1) % BUFFER_SIZE;  // Move to the next index

        pthread_mutex_unlock(&mutex);  // Unlock buffer access
        sem_post(&full);  // Signal that a new item is available

        usleep(rand() % 100000);  // Simulate processing delay
    }
    return NULL;
}

// Consumer function
void *consumer(void *arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);  // Wait if buffer is empty
        pthread_mutex_lock(&mutex);  // Lock buffer access

        int item = buffer[out];  // Remove item from the buffer
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;  // Move to the next index

        pthread_mutex_unlock(&mutex);  // Unlock buffer access
        sem_post(&empty);  // Signal that an empty slot is available

        usleep(rand() % 100000);  // Simulate processing delay
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;
    sem_init(&empty, 0, BUFFER_SIZE);  // Initialize semaphore with buffer size
    sem_init(&full, 0, 0);  // Initialize semaphore with zero full slots
    pthread_mutex_init(&mutex, NULL);  // Initialize mutex

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
