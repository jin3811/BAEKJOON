#include <stdio.h>
#include <string.h>

typedef struct {
    int queue[10000];
    int len;
}Queue;

void push(Queue * q, int x) {
    q->queue[q->len++] = x;
}

int pop(Queue * q) {
    if (q->len) {
        int result = q->queue[0];
        for (int i = 0; i < q->len-1; i++) {
            q->queue[i] = q->queue[i + 1];
        }
        q->len--;
        return result;
    } else return -1;
}

int size (Queue * q) {
    return q->len;
}

int empty (Queue * q) {
    return q->len == 0;
}

int front(Queue * q) {
    if (q->len) return q->queue[0];
    else return -1;
}

int back (Queue * q) {
    if (q->len) return q->queue[q->len-1];
    else return -1;
}

int main () {
    Queue q = {{0}, 0};
    int t, x;
    char func[11];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", func);
        if (strcmp(func, "push") == 0) {
            scanf(" %d", &x);
            printf("%d", x);
            push(&q, x);
        } else if(strcmp(func, "pop") == 0) {
            printf("%d\n", pop(&q));
        } else if(strcmp(func, "size") == 0) {
            printf("%d\n", size(&q));
        } else if(strcmp(func, "empty") == 0) {
            printf("%d\n", empty(&q));
        } else if(strcmp(func, "front") == 0) {
            printf("%d\n", front(&q));
        } else if(strcmp(func, "back") == 0) {
            printf("%d\n", back(&q));
        }
    } 
    return 0;
}