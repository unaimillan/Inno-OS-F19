#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 3

pthread_t threads[N];

void* perform_work(int index){
    printf("I'm thread with id %lu and index %d!\n",
            (unsigned int) pthread_self(), index);
    printf("Hello world from index-%d\n", index);
    pthread_exit(NULL);
}

int main(){
    for(int i = 0; i < N; ++i){
        int rc = pthread_create(&threads[i], NULL, perform_work, (void*)i);

        if(rc){
            printf("\n ERROR: return code from pthread_create is %d \n", rc);
            exit(1);
        }

        printf("\n From thread %lu. Created new thread (%d) with index %d...\n",
               (unsigned int) pthread_self(), (int) threads[i], i);

        pthread_join(threads[i], NULL);
        /*if(i % 5 == 0){
            sleep(1);
        }*/
    }

    pthread_exit(NULL);
    return 0;
}