#include "lib.h"
#include "radix_sort.h"

// Sort an array
void sort(int *array, int size) {
    // 基数を10としてソート．
    radix_sort(array, size, 10);
}
