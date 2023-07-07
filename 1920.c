#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;      
    
    return 0;
}

int myBsearch (int arr[], int start, int end, int target) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    if (arr[mid] > target) return myBsearch(arr, start, mid-1, target);
    else if (arr[mid] < target) return myBsearch(arr, mid+1, end, target);
    else return mid;
}

int main () {
    int len;
    int n;
    int temp;
    int * arr;
    
    scanf("%d", &len);
    arr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; ++i) scanf("%d", &arr[i]);
    qsort(arr, len, sizeof(int), compare);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        if (myBsearch(arr, 0, len, temp) != -1) printf("1\n");
        else printf("0\n");
    }
}