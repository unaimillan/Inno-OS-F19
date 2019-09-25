#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_LEN 2048

void INT_callback(int signum){
    printf("Interrupt signal received.\nIgnoring...\n");
}

int main(){
    signal(SIGINT, INT_callback);

    while(1){
        sleep(10);
    }

    return 0;
}
