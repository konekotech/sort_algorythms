// Bubble sort algorithm implementation
void bubble_sort(int *array, int size) {
    int i, j, tmp;
    for (i = 0; i < size - 1; i++) {
        for (j = size - 1; j > i; j--) {
            if (array[j - 1] > array[j]) {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
    }
}