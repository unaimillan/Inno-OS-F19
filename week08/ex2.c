#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <memory.h>

const int MEM_SIZE = 1.3*1024*1024*1024;

int main() {

    // The initial exercise could not affect much on my system,
    // so I've increased total allocated memory up to around 13GB,
    // so the 'swap' started to work

    for(int i = 0; i < 10; ++i){
        int* data = (int*)(malloc(MEM_SIZE));
        memset(data, 0, MEM_SIZE);
        sleep(1);
    }

    return (0);
}
