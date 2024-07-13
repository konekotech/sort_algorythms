#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int capacity;
    int size;
    int index;
} bucket_t;

void enqueue_bucket(bucket_t *p_bucket, int value) {
    if (p_bucket->size == p_bucket->capacity) {
        p_bucket->array = realloc(p_bucket->array, sizeof(int) * (p_bucket->capacity *= 2U));
        assert(p_bucket->array);
    }
    p_bucket->array[p_bucket->size++] = value;
}

int dequeue_bucket(bucket_t *p_bucket) {
    return p_bucket->array[p_bucket->index++];
}

void show_bucket(bucket_t *p_bucket, int key) {
    printf("bucket[id=%d]", key);
    for (int i = p_bucket->index; i < p_bucket->size; i++) {
        printf(" %d", p_bucket->array[i]);
    }
    printf("\n");
    fflush(stdout);
}

// Radix sort algorithm implementation
void radix_sort(int *array, int size, int base) {
    // Initialize.
    bucket_t buckets[base];
    for (int b = 0; b < base; b++) {
        buckets[b].array = (int*) calloc(16U, sizeof(int));
        buckets[b].capacity = 16;
        buckets[b].size = 0;
        buckets[b].index = 0;
    }
    
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    
    for (int divisor = 1; divisor < max; divisor *= base) {
        int i;
        for (i = 0; i < size; i++) {
            int b = (array[i] / divisor) % base;
            enqueue_bucket(&buckets[b], array[i]);
        }
        
        i = 0;
        for (int b = 0; b < base; b++) {
            while (buckets[b].index < buckets[b].size) {
                array[i++] = dequeue_bucket(&buckets[b]);
            }
            buckets[b].size = 0;
            buckets[b].index = 0;
        }
    }
    
    for (int b = 0; b < base; b++) {
        free(buckets[b].array);
    }
}
