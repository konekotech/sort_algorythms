#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/// バケツを表す構造体．
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

/// バケツの中身を表示する関数．
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
    // 初期化．
    bucket_t buckets[base];
    for (int b = 0; b < base; b++) {
        buckets[b].array = (int*) calloc(16U, sizeof(int));
        buckets[b].capacity = 16;
        buckets[b].size = 0;
        buckets[b].index = 0;
    }
    
    // 最大値を調べ，計算回数に上限を設ける．
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    
    // ソート本体．
    for (int divisor = 1; divisor < max; divisor *= base) {
        int i;
        // バケツへの割り振り．
        for (i = 0; i < size; i++) {
            int b = (array[i] / divisor) % base;
            enqueue_bucket(&buckets[b], array[i]);
        }
        
        // バケツから配列に戻す．
        i = 0;
        for (int b = 0; b < base; b++) {
            show_bucket(&buckets[b], b);
            while (buckets[b].index < buckets[b].size) {
                array[i++] = dequeue_bucket(&buckets[b]);
            }
            // 次の周のためにバケツを初期化．
            buckets[b].size = 0;
            buckets[b].index = 0;
        }
    }
    
    // 後処理．
    for (int b = 0; b < base; b++) {
        free(buckets[b].array);
    }
}
