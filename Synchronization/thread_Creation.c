#include <stdio.h>// Includes the Standard Input Output header, which allows the use of functions like printf and scanf.
#include <stdlib.h>//Includes the Standard Library header, which provides functions like malloc, free, exit, and others.
#include <unistd.h>//Includes the Unix standard header, which provides access to the POSIX operating system API, including the sleep function.
#include <pthread.h>//Includes the POSIX Threads library header, which allows the use of functions like pthread_create, pthread_join

// Declare global variables i and j
int i, j;

// Define the thread function
void *thread_function()
{
    printf("Inside Thread\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Thread Finished\n");
    pthread_exit(NULL);//// Exit the thread cleanly
}

int main()
{
    pthread_t a_thread; // Declare a thread variable

    // Create the thread
    pthread_create(&a_thread, NULL, thread_function, NULL);
    //&a_thread: The address of the a_thread variable is passed. pthread_create will store the thread ID of the newly created thread in a_thread.
    // NULL: Default thread attributes are used. No specific attributes are set for the new thread.
    // thread_function: The thread_function function will be executed by the new thread.
    // NULL: No argument is passed to thread_function.
    printf("Thread Created\n");

    // Wait for the thread to finish
    pthread_join(a_thread, NULL); //Waits for the thread1 to complete execution. The main function will block until thread1 finishes.
    // NULL -This is a pointer to a location where the exit status of the thread will be stored. If you do not need the exit status, you can pass NULL.
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
