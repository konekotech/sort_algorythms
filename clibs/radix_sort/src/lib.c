#include "lib.h"
#include "radix_sort.h"

// Sort an array
void sort(int *array, int size) {
    radix_sort(array, size, 10);
}
