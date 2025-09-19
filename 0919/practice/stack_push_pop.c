#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

static void init(Stack* s) { s->top = NULL; }
static int  empty(Stack* s) { return s->top == NULL; }

static void push(Stack* s, int v) {
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->data = v;
    nd->next = s->top;
    s->top = nd;
}

static int pop(Stack* s, int* out) {
    if (empty(s)) return 0;
    Node* nd = s->top;
    *out = nd->data;
    s->top = nd->next;
    free(nd);
    return 1;
}

static void destroy(Stack* s) {
    int tmp;
    while (pop(s, &tmp));
}

int main(void) {
    Stack s; init(&s);
    for (int i = 1; i <= 5; ++i) push(&s, i*10);
    int v;
    while (pop(&s, &v)) {
        printf("pop: %d\n", v);
    }
    destroy(&s);
    return 0;
}
