#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 1024

int main() {
    // ex3.c already fine with all the requirements
    // because `system` passes parameters to the executed program
    // and also runs the new process with `fork`
    char buffer[MAX_LEN] = {0};
    printf(">> ");
    fgets(buffer, MAX_LEN, stdin);

    while(strcmp(buffer, "exit\n") != 0){
        system(buffer);
        printf(">> ");
        fgets(buffer, MAX_LEN, stdin);
    }
    return 0;
}