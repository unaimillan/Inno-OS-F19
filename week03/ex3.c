#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void free_node(Node **node) {
    free(*node);
    *node = NULL;
}

void insert_node(int data, Node **prev) {
    Node *temp = create_node(data);
    temp->next = *prev;
    *prev = temp;
}

void delete_node(int elem, Node **head) {
    if (*head == NULL) { // -- case of empty list
        return;
    }

    if ((*head) != NULL && (*head)->data == elem) { // -- case of match of one node
        Node* temp = (*head)->next;
        free_node(head);
        *head = temp;
        return;
    }

    // case of two and more nodes
    for (Node *cur = *head; cur->next != NULL; cur = cur->next) {
        if (cur->next->data == elem) {
            Node *temp = cur->next->next;
            free_node(&(cur->next));
            cur->next = temp;
            return;
        }
    }
}

void print_list(Node *current) {
    printf("List: ");
    for (; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    putchar('\n');
}

void foo(int a) {
    a = 99;
    printf("%d\n", a);
}

int main() {
    Node *head = NULL;

    insert_node(1, &head);
    insert_node(2, &head);
    insert_node(3, &head);
    insert_node(4, &head);
    insert_node(5, &head);
    print_list(head);

    delete_node(3, &head);
    print_list(head);

    delete_node(2, &head);
    delete_node(5, &head);
    print_list(head);

    delete_node(1, &head);
    delete_node(4, &head);
    print_list(head);

    insert_node(99, &head);
    insert_node(-99, &(head->next));
    print_list(head);

    return 0;
}
