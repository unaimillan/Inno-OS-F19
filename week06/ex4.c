#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_LEN 2048

void KILL_callback(int signum){
    printf("Received 'SIGKILL' signal.\nIgnoring...\n");
}

void STOP_callback(int signum){
    printf("Received 'SIGSTOP' signal.\nIgnoring...\n");
}
void USR1_callback(int signum){
    printf("Received 'SIGUSR1' signal.\nIgnoring...\n");
}

int main(){
    // Signals 'SIGKILL' and 'SIGSTOP' cannot be caught by the process, so trying to catch them is useless
    // Signal 'SIGUSR1' works fine and we see it's output on the screen
    signal(SIGKILL, KILL_callback);
    signal(SIGSTOP, STOP_callback);
    signal(SIGUSR1, USR1_callback);

    while(1){
        sleep(10);
    }

    return 0;
}
