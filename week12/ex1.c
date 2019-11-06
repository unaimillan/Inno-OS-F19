#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 20

int main(int argc, char *argv[])
{
    int inputFd;
    unsigned char buf[BUF_SIZE];

    inputFd = open("/dev/random", O_RDONLY);
    if (inputFd == -1) {
        fprintf(stderr, "Error while opening file\nExiting...\n");
        exit(1);
    }

    if(read(inputFd, buf, BUF_SIZE) < 0){
        fprintf(stderr, "Error while reading\nExiting...\n");
        exit(1);
    }

    for(size_t i = 0; i < BUF_SIZE; ++i){
        putchar(32+buf[i]%60);
    }

    close(inputFd);
    return (0);
}
