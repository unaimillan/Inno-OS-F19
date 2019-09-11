#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 5;

    /* After 3 forks we will have 8 almost similar processes
     * Because one `fork` call produces only one more new process, but because these
     * processes also use `fork` inside their amount doubles this each new iteration of `for`
     */

    for (int i = 0; i < n; ++i){
        fork();
        sleep(5);
    }

    return 0;
}
