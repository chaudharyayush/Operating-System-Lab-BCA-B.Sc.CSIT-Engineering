#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int x = 1;
    pid = fork();  // create a new process
    
    if (pid == 0) { // child process
        printf("Child process: x = %d\n", ++x);
    } else if (pid > 0) { // parent process
        printf("Parent process: x = %d\n", --x);
    } else { // error
        printf("Error creating child process.\n");
    }
    
    printf("x = %d\n", x);
    return 0;
}
