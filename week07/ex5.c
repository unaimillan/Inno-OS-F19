#include <stdio.h>
#include <malloc.h>

int main() {
    // Allocate one element of array of strings (char*)
    char **s = (char**)malloc(1* sizeof(char*));
    char foo[] = "Hello World";

    // Assign address of 'foo' to first element of 's'
    *s = foo;
    printf("*s is %s\n", *s);

    // the same but with different notation
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);

    // Free our array of one string
    free(s);

    return (0);
}
