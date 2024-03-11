#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Declare global variables i and j
int i, j;

// Define the thread function
void *thread_function(void *arg)
{
    printf("Inside Thread\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Thread Finished\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t a_thread; // Declare a thread variable

    // Create the thread
    pthread_create(&a_thread, NULL, thread_function, NULL);
    printf("Thread Created\n");

    // Wait for the thread to finish
    //pthread_join(a_thread, NULL);
    printf("Thread Joined\n");

    // Print a sequence of numbers from the main program
    printf("Inside Main Program\n");
    for (j = 20; j < 25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }

    return 0;
}
