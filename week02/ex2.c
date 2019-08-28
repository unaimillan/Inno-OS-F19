#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 65536

void reverse(){
    int curChar = getchar();
    if(curChar == '\n' || curChar == EOF){
        return;
    }else{
        reverse();
        putchar(curChar);
    }
}

int main() {

    printf("Please, prompt the line: ");

    reverse();

    putchar('\n');
    return 1;
}
