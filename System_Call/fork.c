#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int x = 1;

    pid = fork(); // create a new process
    // Return value of the fork system call= It returns the process ID of the child to the parent and 0 to the child.
    if (pid < 0)
    { // error
        printf("Error creating child process.\n");
    }
    else if (pid == 0)
    { // child process
        printf("Child process (PID %d): x = %d\n", getpid(), ++x);
    }
    else
    { // parent process
        printf("Parent process (PID %d): x = %d\n", getpid(), --x);
    }

    return 0;
}
