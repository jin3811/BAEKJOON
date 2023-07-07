#include <stdio.h>
#include <string.h>

typedef struct {
    int stack[10000];
    int len;
}Stack;

int getElement(Stack * st) {return st->stack[(st->len)-1];}

void push(Stack * st, int x) { st->stack[st->len++] = x; }

int pop(Stack * st) {
    if (st->len) {
        int ret = getElement(st);
        st->stack[(st->len--)-1] = 0;
        return ret;
    } else {
        return -1;
    }
}
int size(Stack * st) {return st->len;}

int empty (Stack * st) { return st->len == 0;}

int top(Stack * st) {
    if (st->len) {
        return getElement(st);
    } else {
        return -1;
    }
}

int main () {
    Stack st = {{0}, 0};
    int t, x;
    char func[6];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", func);
        if (strcmp(func, "push") == 0) {
            scanf("%d", &x);
            push(&st, x);
        } else if(strcmp(func, "pop") == 0) {
            printf("%d\n", pop(&st));
        } else if(strcmp(func, "size") == 0) {
            printf("%d\n", size(&st));
        } else if(strcmp(func, "empty") == 0) {
            printf("%d\n", empty(&st));
        } else if(strcmp(func, "top") == 0) {
            printf("%d\n", top(&st));
        }
    } 
}