// Selection sort algorithm implementation
void selection_sort(int *array, int size) {
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}