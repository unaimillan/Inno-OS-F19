#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    int n = 322;

    /*
     * Processes are started in pseudo-parallel way. We can't predict the output order
     * Also, the process ID is incremented by 1 for every new process
     */

    if(fork() > 0){
        pid = getpid();
        printf("Hello from parent [%d - %d]\n", pid, n);
    }else{
        pid = getpid();
        printf("Hello from child [%d - %d]\n", pid, n);
    }
    return 0;
}
