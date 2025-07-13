#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Append node at the end
void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at specific position (1-based index)
void insertAtPosition(struct Node** head, int pos, int value) {
    struct Node* newNode = createNode(value);

    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node by value
void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;     // Store next
        current->next = prev;     // Reverse current
        prev = current;           // Move prev
        current = next;           // Move current
    }

    *head = prev;
}

// Print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }

    printf("\nOriginal List: ");
    printList(head);

    // Insert at position
    int pos, newValue;
    printf("\nInsert value and position: ");
    scanf("%d %d", &newValue, &pos);
    insertAtPosition(&head, pos, newValue);
    printf("After Insertion: ");
    printList(head);

    // Delete a node
    printf("\nEnter value to delete: ");
    scanf("%d", &value);
    deleteByValue(&head, value);
    printf("After Deletion: ");
    printList(head);

    // Reverse the list
    reverseList(&head);
    printf("\nReversed List: ");
    printList(head);

    return 0;
}
