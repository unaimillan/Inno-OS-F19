#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
    int N = 0;

    printf("Please, enter the 'N' value: ");
    scanf("%d", &N);

    int *arr = (int *) malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }

    printf("Array:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    free(arr);
    arr = NULL;

    return 0;
}