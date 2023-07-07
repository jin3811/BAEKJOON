// 왜 되는거지?
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    char name[101];
}User;

int compare(const void * a, const void * b) {
    User * u1 = (User *)a;
    User * u2 = (User *)b;

    return u1->age > u2->age;
}

int main () {
    int n;
    scanf("%d", &n);
    User * arr = (User *)malloc(sizeof(User) * n);

    for (int i = 0; i < n; i++)
        scanf(" %d %s", &arr[i].age, arr[i].name);

    qsort(arr, n, sizeof(User), compare);

    for (int i = 0; i < n; i++)
        printf("%d %s\n", arr[i].age, arr[i].name);
}