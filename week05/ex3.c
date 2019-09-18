#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define bool char
#define true 1
#define false 0

// use `sleep` and `wakeup` routines
// and so called `condition variables`
const int MAX_BUFF = 1000;
bool full = false, empty = true;
int buffer = 0;

// when `full` is false can produce
// when `empty` is `false` can consume
void wait(bool* var){
    while (*var != false){
        ;//usleep(10000);
    }
}

void signal(bool* var, bool val){
    *var = val;
}

void* produce_work(){
    while(true){
        //usleep(100);
        if(buffer == 500){
            printf("Producer reached 500\n");
        }
        if(buffer < MAX_BUFF){
            buffer++;
            if(buffer == 1){
                signal(&empty, false);
            }
        }else{
            wait(&full);
        }
    }
    pthread_exit(NULL);
}

void* consume_work(){
    while(1){
        //usleep(1000);
        if(buffer > 0){
            buffer--;
            if(buffer < MAX_BUFF){
                signal(&full, false);
            }
        } else{
            wait(&empty);
        }

    }
    pthread_exit(NULL);
}

int main(){
    srand(0);

    pthread_t producer, consumer;

    pthread_create(&producer, NULL, produce_work, NULL);
    pthread_create(&consumer, NULL, consume_work(), NULL);

    pthread_exit(NULL);
}