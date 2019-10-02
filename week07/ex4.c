#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

// My realloc function that takes:
//
// void *input - pointer to memory which should be reallocated
// size_t oldsize - size of memory of ptr
// size_t newsize - size of the new allocated memory
//
// and it returns:
// void* - pointer to newly allocated memory
void* myalloc(void *source, size_t oldsize, size_t newsize){
    void* dest = malloc(newsize);
    if(source == NULL){
        return dest;
    }
    if(newsize == 0){
        free(source);
        return NULL;
    }

    // Minimum memory size to copy
    size_t cpysize = oldsize < newsize ? oldsize : newsize;
    memcpy(dest, source, cpysize);

    free(source);

    return dest;
}

void main_ex3(){

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size: ");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 ints
    int *a1 = (int*)malloc(n1* sizeof(int));
    int i;
    for (i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        a1[i]=100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = myalloc(a1, n1*sizeof(int), n2* sizeof(int));

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if(n1 <  n2){
        for(int i = n1; i < n2; ++i){
            a1[i] = 0;
        }
    }


    for (i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D
}

int main(){

    // Let's test our 'myalloc' with 3-rd exercise
    main_ex3();

    return 0;
}