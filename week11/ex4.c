#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(){
    char infilename[] = "ex1.txt";
    char outfilename[] = "ex1.memcpy.txt";
    int infd = open(infilename, O_RDONLY);
    int outfd = open(outfilename
            , O_RDWR | O_CREAT // flags to open the file
            , S_IRUSR + S_IWUSR + S_IRGRP + S_IWGRP + S_IROTH); // permissions for newly created file

    if(infd == -1){
        printf("Failed to open '%s' file\nExiting...\n", infilename);
        exit(-1);
    }

    if(outfd == -1){
        printf("Failed to open '%s' file\nExiting...\n", outfilename);
        exit(-1);
    }

    struct stat statbuff;
    if(fstat(infd, &statbuff) == -1){
        printf("Failed to get stats of the 'ex1.txt' file\nExiting...\n");
        exit(-1);
    }

    size_t filesize = statbuff.st_size;
    //printf("%lu\n\n", filesize); // debug

    ftruncate(outfd, filesize);

    void *inmap = mmap(NULL, filesize, PROT_READ, MAP_SHARED_VALIDATE, infd, 0);
    void *outmap = mmap(NULL, filesize, PROT_WRITE, MAP_SHARED_VALIDATE, outfd, 0);

    // printf("Hello\nin: %p\nout: %p\nerrno: %u\n", inmap, outmap, errno); // debug

    // copy content of memory from one file to another
    memcpy(outmap, inmap, filesize);

    // sync outmap with second file
    msync(outmap, filesize, MS_SYNC);

    munmap(inmap, filesize);
    munmap(outmap, filesize);
    return 0;
}