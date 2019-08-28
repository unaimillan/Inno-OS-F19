#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void drawChar(int cnt, char ch){
    for(int i = 0; i < cnt; ++i)
        putchar(ch);
}

void drawLine(int amount, int length){
    int spaces = (length - amount)/2;
    spaces = spaces > 0 ? spaces : 0;

    drawChar(spaces, ' ');
    drawChar(amount, '*');
    putchar('\n');
}

void print_tower(int height, int length){
    if(height == 0){
        return;
    }else{
        print_tower(height - 1, length);
        drawLine(2*height-1, length);
    }
}

int main(int argc, char* argv[]) {
    printf("%s\n", argv[0]);
    if(argc != 2){
        printf("Usage: ex3 height\n  \"height\" is a height of tower\n");
        return 1;
    }

    int height = 0;
    sscanf(argv[1], "%d", &height);

    print_tower(height, 2*height-1);

    return 0;
}
