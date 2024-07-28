#include <assert.h>
#include <stdlib.h>
#include <string.h>

void sub_merge_sort(int *array, int *sub_array, int size);

void merge_sort(int *array, int size) {
    int *sub_array = calloc(size / 2, sizeof(int));
    assert(sub_array);
    sub_merge_sort(array, sub_array, size);
    free(sub_array);
}

void sub_merge_sort(int *array, int *sub_array, int size) {
    if (size == 1UL) {
        return;
    }

    const int center = size / 2;
    sub_merge_sort(array, sub_array, center);
    sub_merge_sort(&array[center], sub_array, size - center);

    memcpy(sub_array, array, center * sizeof(int));

    int merge = 0;
    int front = 0;
    int back  = center;
    while (front < center && back < size) {
        if (sub_array[front] <= array[back]) {
            array[merge] = sub_array[front];
            front++;
        } else {
            array[merge] = array[back];
            back++;
        }
        merge++;
    }
    if (front < center) {
        memcpy(&array[merge], &sub_array[front], (size - merge) * sizeof(int));
    }
}
