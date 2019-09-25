#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

#define MAX_LEN 2048

void TERM_callback(int signum){
    printf("Child 2: Received 'SIGTERM'\n");
    printf("Child 2: Bye..\n");
    exit(0);
}

int main() {
    int pipefd[2];

    if(pipe(pipefd) != 0){
        printf("Parent: Failed to create pipe!\nExiting...\n");
        exit(1);
    }

    pid_t firstChild = fork();

    if(firstChild != 0){
        pid_t secondChild = fork();
        if(secondChild != 0){
            // Inside parent
            printf("Parent: Hello! - %u\n", getpid());

            // send to firstChild pid of `secondChild`
            write(pipefd[1], &secondChild, sizeof(int));
            printf("Parent: PID successfully sent to first child!\n");

            // wait change of state of the second child
            printf("Parent: Waiting for second child - %u\n", secondChild);
            waitpid(secondChild, NULL, 0);

            printf("Parent: Second child have been terminated\n");
            printf("Parent: Saad...\n");
        }else{
            // Inside second child
            printf("Child 2: Hello! - %u\n", getpid());

            signal(SIGTERM, TERM_callback);
            while(1){
                sleep(10);
            }
        }
    } else{
        // Inside first child
        printf("Child 1: Hello! - %u\n", getpid());

        int pid = 0;
        printf("Child 1: Reading from pipe\n");
        read(pipefd[0], &pid, sizeof(int));
        printf("Child 1: Got PID of first child %u\n", pid);

        sleep(3);
        printf("Child 1: Ready to stop that dammit second child\n");

        kill(pid, SIGTERM);
        printf("Child 1: Sent 'SIGTERM' to second child\n");
        //kill(pid, SIGCONT);

    }

    return 0;
}
