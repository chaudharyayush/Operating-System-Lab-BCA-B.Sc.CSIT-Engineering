#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
//void *fun1();
//void *fun2();
int shared=1; //shared variable

void *fun1()
{
    int x;
    x=shared;//thread one reads value of shared variable
    printf("Thread1 reads the value of shared variable as %d\n",x);
    x++;  //thread one increments its value
    printf("Local updation by Thread1: %d\n",x);
    sleep(1);  //thread one is preempted by thread 2
    shared=x; //thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n",shared);
}
void *fun2()
 {
     int y;
     y=shared;//thread two reads value of shared variable
     printf("Thread2 reads the value as %d\n",y);
     y--;  //thread two increments its value
     printf("Local updation by Thread2: %d\n",y);
     sleep(1); //thread two is preempted by thread 1
     shared=y; //thread one updates the value of shared variable
     printf("Value of shared variable updated by Thread2 is: %d\n",shared);
 }

 int main()
 {
 pthread_t thread1, thread2;
 pthread_create(&thread1, NULL, fun1, NULL);
 //&thread1: The address of the thread1 variable is passed. pthread_create will store the thread ID of the newly created thread in thread1.
 //NULL: Default thread attributes are used. No specific attributes are set for the new thread.
 //fun1: The fun1 function will be executed by the new thread.
 //NULL: No argument is passed to fun1.
 pthread_create(&thread2, NULL, fun2, NULL);
 pthread_join(thread1, NULL);// NULL -This is a pointer to a location where the exit status of the thread will be stored. If you do not need the exit status, you can pass NULL.
 pthread_join(thread2,NULL);
 printf("Final value of shared is %d\n",shared); //prints the last updated value of shared variable
 }