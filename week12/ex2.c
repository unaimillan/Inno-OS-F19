#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned char append = 0;

    if(argc > 1 && strcmp(argv[1], "-a") == 0){
        append = 1;
    }

    const int filecount = argc - 1 - append;
    FILE* files[filecount];
    const char *fmode = (append ? "a" : "w");

    for(int i = 0; i < filecount; ++i){
        files[i] = fopen(argv[1+append+i], fmode);
        if(files[i] == NULL){
            fprintf(stderr, "Error while opening %s file\nExiting...\n", argv[1+append+i]);
            exit(1);
        }
    }

    int ch;
    while((ch = getchar()) != -1){
        putchar(ch);
        for(int i = 0; i < filecount; ++i){
            fputc(ch, files[i]);
        }
    }

    for(int i = 0; i < filecount; ++i){
        fclose(files[i]);
    }
    return (0);
}
