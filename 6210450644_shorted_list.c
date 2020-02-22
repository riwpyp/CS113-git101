//Student ID: 6210450644 Name:Poonyaporn Rukrudeekul
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct Node {
    int x;
    struct Node *n2;
};

struct Node *newNode(int n) {
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));

    node->x = n;
    node->n2 = NULL;

    return node;
}

void com(struct Node **hr, struct Node *node) {
    struct Node *current;
    if (*hr == NULL || (*hr)->x >= node->x) {
        node->n2 = *hr;
        *hr = node;
    } else {
        current = *hr;
        while (current->n2 != NULL &&
               current->n2->x < node->x) {
            current = current->n2;
        }
        node->n2 = current->n2;
        current->n2 = node;
    }
}

int main() {
    struct Node *node = NULL;
    struct Node *head = NULL;
    
    int n;

    while (scanf("%d", &n),n != -1) {
        node = newNode(n);
        com(&head, node);
    }
    for(;head; head = head->n2){
        printf("%d\n", head->x);
    }
    
    
}