#include <stdio.h>
#include <stdlib.h>

#define MAX_RAND_VAL 1024

void bubble_sort(int arr[], int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {

            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;

            }
        }
    }
}

void fill_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % MAX_RAND_VAL;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main() {
    srand(0); // Change to get differnt inputs

    int n = 5;
    int a[n];

    fill_array(a, n);
    print_array(a, n);
    bubble_sort(a, n);
    print_array(a, n);

    return 0;
}
