#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

void push(Node** head_ref, int new_data);
void deleteNode(Node** head_ref, int key);
void printList(Node* head);

int main() {
    Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("\nCreated Linked list is:\n");
    printList(head);

    deleteNode(&head, 1);

    printf("\nLinked List after Deletion of 1:\n");
    printList(head);

    return 0;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    Node* tnode = head;
    while (tnode != NULL) {
        printf("%d ", tnode->data);
        tnode = tnode->next;
    }
    printf("\n");
}
