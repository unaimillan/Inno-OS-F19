#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void swapInt(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, char* argv[]) {

    int a, b;
    scanf("%d %d", &a, &b);

    swapInt(&a, &b);

    printf("%d %d\n", a, b);

    return 0;
}
