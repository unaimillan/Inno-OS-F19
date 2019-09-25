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
    char lineOne[MAX_LEN] = "Hello world!";
    char lineTwo[MAX_LEN] = "";

    printLines(lineOne, lineTwo);

    printf("Creating pipe.\n");
    int pipefd[2];
    if(pipe(pipefd) != 0){
        printf("Failed to create pipe!\nExiting...");
        return  -1;
    }
    printf("Pipe was successfully created.\n");

    write(pipefd[1], lineOne, MAX_LEN);
    read(pipefd[0], lineTwo, MAX_LEN);

    printf("Data transfer accomplished.\n\n");
    printLines(lineOne, lineTwo);

    return 0;
}