#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(){
    char new_text[] = "This is a nice day";
    char fl_name[] = "ex1.txt";

    int my_fd = open(fl_name, O_RDWR);
    if(my_fd == -1){
        printf("Failed to open 'ex1.txt' file\nExiting...\n");
        exit(-1);
    }

    struct stat statbuff;
    if(fstat(my_fd, &statbuff) == -1){
        printf("Failed to get stats of the 'ex1.txt' file\nExiting...\n");
        exit(-1);
    }

    size_t fl_size = statbuff.st_size;
    void *addr = mmap(NULL, fl_size, PROT_READ | PROT_WRITE, MAP_SHARED_VALIDATE, my_fd, 0);

    // add -1 to size to
    // avoid '\0' character at the end!
    ftruncate(my_fd, sizeof(new_text)-1);
    memcpy(addr, new_text, sizeof(new_text));

    msync(addr, fl_size, MS_SYNC);
    munmap(addr, fl_size);
    return 0;
}