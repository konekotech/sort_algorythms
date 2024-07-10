#include <stdio.h>
#include "lib.h"

// Print the elements of an array
void print_array(int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int size = sizeof(array) / sizeof(array[0]);
    sort(array, size);
    print_array(array, size);
    return 0;
}



