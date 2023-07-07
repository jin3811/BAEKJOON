#include <stdio.h>
#include <string.h>

typedef struct {
    int deque[10000];
    int start;
    int end;
}Deque;

void push_back(Deque * dq, int x) {
    dq->deque[dq->end++] = x;
}

void push_front(Deque * dq, int x) {
    if(dq->start) {
        
    }
}

int pop_back(Deque * dq) {
    int result = dq->deque[--(dq->end)];
    return result;
}

int pop_front(Deque * dq) {
    
}

int size (Deque * dq) {
    return dq->end;
}

int empty (Deque * dq) {
    return dq->end == 0;
}

int front(Deque * dq) {
    return dq->deque[0];
}

int back (Deque * dq) {
    return dq->deque[dq->end-1];
}

int main () {
    Deque dq = {{0}, 0, 0};
    int t, x;
    char func[11];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", func);
        if (strcmp(func, "push_back") == 0) {
            scanf(" %d", &x);
            push_back(&dq, x);
        } else if (strcmp(func, "push_front") == 0) {
            scanf(" %d", &x);
            push_front(&dq, x);
        } else if (strcmp(func, "pop_back") == 0) {
            printf("%d\n", pop_back(&dq));
        } else if (strcmp(func, "pop_front") == 0) {
            printf("%d\n", pop_front(&dq));           
        } else if (strcmp(func, "size") == 0) {
            printf("%d\n", size(&dq));
        } else if (strcmp(func, "empty") == 0) {
            printf("%d\n", empty(&dq));
        } else if (strcmp(func, "front") == 0) {
            printf("%d\n", front(&dq));
        } else if (strcmp(func, "back") == 0) {
            printf("%d\n", back(&dq));
        }
    } 
    return 0;
}