#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* nthNodeFromEnd(struct Node* head, int n) {
    struct Node* slow = head;
    struct Node* fast = head;

    for (int i = 0; i < n; i++) {
        if (fast == NULL) return NULL;
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void printLL(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int a, val;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &val);
        insertAtEnd(&head, val);
    }

    int n;
    scanf("%d", &n); // শেষ থেকে n তম উপাদান দেখতে চাইলে

    struct Node* result = nthNodeFromEnd(head, n);
    if (result != NULL) {
        printf("Nth node from end: %d\n", result->data);
    } else {
        printf("Node does not exist.\n");
    }

    return 0;
}
