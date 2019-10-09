#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <memory.h>
#include <sys/resource.h>

const int MEM_SIZE = 10*1024*1024;

int main() {

    // The unsupported fields are set to '0' by kernel

    for(int i = 0; i < 10; ++i){
        int* data = (int*)(malloc(MEM_SIZE));
        memset(data, 0, MEM_SIZE);
        struct rusage temp;
        getrusage(RUSAGE_SELF, &temp);
        printf("ru_maxrss: %ld, ru_ixrss: %ld, ", temp.ru_maxrss, temp.ru_ixrss);
        printf("ru_idrss: %ld, ru_isrss: %ld\n", temp.ru_idrss, temp.ru_isrss);
        sleep(1);
    }

    return (0);
}
