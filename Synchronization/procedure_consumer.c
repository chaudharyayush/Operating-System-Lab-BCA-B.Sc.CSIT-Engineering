#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

// Initialize a semaphore to 1
sem_t mutex;
 
// Number of full slots as 0
int full = 0;
 
// Number of empty slots as size
// of buffer
int empty = 10, x = 0;
 
// Function to produce an item and
// add it to the buffer
void producer()
{
    // Wait on empty semaphore
    sem_wait(&empty);
 
    // Wait on mutex semaphore
    sem_wait(&mutex);
 
    // Increase the number of full
    // slots by 1
    ++full;
 
    // Decrease the number of empty
    // slots by 1
    --empty;
 
    // Item produced
    x++;
    printf("\nProducer produces"
           " item %d",
           x);
 
    // Signal mutex semaphore
    sem_post(&mutex);
}
 
// Function to consume an item and
// remove it from buffer
void consumer()
{
    // Wait on full semaphore
    sem_wait(&full);
 
    // Wait on mutex semaphore
    sem_wait(&mutex);
 
    // Decrease the number of full
    // slots by 1
    --full;

    if (x > 0) {
        printf("\nConsumer consumes "
               "item %d",
               x);
        x--;
    } else {
        printf("\nBuffer is empty!");
    }
 
    // Increase the number of empty
    // slots by 1
    ++empty;
 
    // Signal mutex semaphore
    sem_post(&mutex);
 
    // Signal empty semaphore
    sem_post(&empty);
}
 
// Driver Code
int main()
{
    int n, i;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    // Initialize mutex semaphore to 1
    sem_init(&mutex, 0, 1);

    // Initialize full semaphore to 0
    sem_init(&full, 0, 0);
 
    // Initialize empty semaphore to size of buffer
    sem_init(&empty, 0, 10);
 
    for (i = 1; i > 0; i++) {
 
        printf("\nEnter your choice:");
        scanf("%d", &n);
 
        // Switch Cases
        switch (n) {
        case 1:
 
            // If empty is non-zero, then it is
            // possible to produce
            if (empty != 0) {
                producer();
            }
 
            // Otherwise, print buffer
            // is full
            else {
                printf("Buffer is full!");
            }
            break;
 
        case 2:
 
            // If full is non-zero, then it is
            // possible to consume
            if (full != 0) {
                consumer();
            }
 
            // Otherwise, print Buffer
            // is empty
            else {
                printf("Buffer is empty!");
            }
            break;
 
        // Exit Condition
        case 3:
            sem_destroy(&mutex);
            sem_destroy(&full);
            sem_destroy(&empty);
            exit(0);
            break;
        }
    }
}