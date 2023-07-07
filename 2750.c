#include <stdio.h>
#include <stdlib.h>

void quick_sort (int * arr, int start, int end) {
    int pivot = arr[(start + end) / 2]; /* 오름차순 */
    int i = start, j = end;
    int temp;
    do {
        while (arr[i] < pivot) i++;
        while (pivot < arr[j]) j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (start < j) quick_sort(arr, start, j);
    if (i < end) quick_sort(arr, i, end);
}

int main () {
    int *arr = NULL;
    int len, i;

    scanf("%d", &len);
    arr = (int *)malloc(len * sizeof(int));
    
    for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, len - 1);
    for (i = 0; i < len; i++) {
        printf("%d \n", arr[i]);
    }
    free(arr);
    return 0;
}