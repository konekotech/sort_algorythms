// Bubble sort algorithm implementation
void quick_sort(int *array, int size) {
    if (size < 2) {
        return;
    }
    int pivot = array[size / 2];
    int i, j;
    for (i = 0, j = size - 1; ; i++, j--) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    quick_sort(array, i);
    quick_sort(array + i, size - i);
}