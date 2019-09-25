#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 2048

void printLines(char first[], char second[]){
    if(first == NULL || second == NULL){
        printf("Invalid lines to print!\n");
        exit(1);
    }

    printf("First line content: %s\nSecond line content: %s\n\n", first, second);
}

int main(){
    char output[MAX_LEN] = "Hello world!";
    printf("Initial string: %s\n\n", output);

    printf("Creating pipe.\n");

    int pipefd[2];
    if(pipe(pipefd) != 0){
        printf("Failed to create pipe!\nExiting...");
        return  -1;
    }

    printf("Pipe was successfully created.\n");

    write(pipefd[1], output, MAX_LEN);
    printf("Data were sent.\n\n");

    if(fork() == 0){
        printf("From child - %u\n", getpid());
        char buffer[MAX_LEN] = "";
        read(pipefd[0], buffer, MAX_LEN);
        printf("Data were received.\n");

        printf("Received string: %s\n", buffer);
    }else{
        printf("From parent - %u\n", getpid());
    }


    return 0;
}