#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

static Node* push_back(Node* head, int key) {
    Node* nd = (Node*)malloc(sizeof(Node));
    nd->key = key;
    nd->next = NULL;
    if (!head) return nd;
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = nd;
    return head;
}

static void print_forward(Node* head) {
    for (Node* p = head; p; p = p->next) {
        printf("%d ", p->key);
    }
    puts("");
}

static void print_reverse_rec(Node* p) {
    if (!p) return;
    print_reverse_rec(p->next);
    printf("%d ", p->key);
}

static void free_all(Node* head) {
    while (head) {
        Node* t = head; head = head->next; free(t);
    }
}

int main(void) {
    Node* head = NULL;
    int ch;
    puts("키를 누르면 값 저장, ESC로 종료 후 정순/역순 출력");
    while (1) {
        ch = getch();
        if (ch == 27) break; // ESC
        head = push_back(head, ch);
    }
    puts("정순:");
    print_forward(head);
    puts("역순:");
    print_reverse_rec(head);
    puts("");
    free_all(head);
    return 0;
}
