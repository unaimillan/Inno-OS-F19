#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_LEN 2048

void TERM_callback(int signum){
    printf("\nChild: Oohh, NOOO!\n");
    printf("Child: Somebody terminates mee!...\n");
    printf("Child: I can't live in such a cruel world!\n");
    printf("Child: Bye...\n");
    exit(0);
}

int main() {

    pid_t pid = fork();

    if (pid != 0) {
        sleep(10);
        printf("Parent: I'll terminate YOU!!!\n");
        kill(pid, SIGTERM);
    } else {
        signal(SIGTERM, TERM_callback);
        while (1) {
            printf("Child: I'm alive!\n");
            sleep(1);
        }
    }

    return 0;
}
