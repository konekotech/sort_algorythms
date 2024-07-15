#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// add item to heap
void up_heap(int *heap, int index) {
    for (; (index != 0) && (heap[index] > heap[(index - 1) / 2]); index = (index - 1) / 2) {
        swap(&heap[index], &heap[(index - 1) / 2]);
    }
}

// remove root item from heap
void down_heap(int *heap, int index) {
    swap(&heap[0], &heap[index]);
    
    int cur = 0, next = 1;
    while (next < index) {
        if ((next + 1 != index) && heap[next] < heap[next + 1]) {
            next++;
        }

        if (heap[cur] >= heap[next]) {
            break;
        }
        swap(&heap[cur], &heap[next]);

        cur = next;
        next = cur * 2 + 1;
    }
}

// Heap sort algorithm implementation
void heap_sort(int *array, int size) {
    int i = 0;
    while (++i < size) {
        up_heap(array, i);
    }
    while (--i) {
        down_heap(array, i);
    }
}
