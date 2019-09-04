#include <stdio.h>
#include <stdlib.h>

#define MAX_RAND_VAL 1024


void fill_array(int arr[], int n);

void print_array(int arr[], int n);

// Implementation of quicksort algorithm
// of the array of integers on the open interval [l; r)
void quicksort(int l, int r, int arr[]) {
    if (l + 1 >= r) {
        return;
    } else {

        int pivot = arr[l];    // pivot
        int small = l+1;  // Index of smaller element

        for (int cur = l+1; cur < r; cur++)
        {
            // If current element is smaller than the pivot
            if (arr[cur] < pivot)
            {
                int temp = arr[small];
                arr[small] = arr[cur];
                arr[cur] = temp;

                small++;    // increment index of smaller element
            }
        }

        int temp = arr[small];
        arr[small] = arr[l];
        arr[l] = temp;
        int m = small;

        quicksort(l, m, arr);
        quicksort(m, r, arr);
    }
}

int main() {
    srand(0);
    int n = 10;
    int arr[n];


    fill_array(arr, n);
    print_array(arr, n);

    quicksort(0, n, arr);

    print_array(arr, n);

    return 0;
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
