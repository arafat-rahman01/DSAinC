#include <stdio.h>
#include <stdlib.h>

// নোডের স্ট্রাকচার
struct Node {
    int data;
    struct Node* next;
};

// টপ পয়েন্টার
struct Node* top = NULL;

// পুশ ফাংশন (ডাটা স্ট্যাকের টপে ঢোকানো)
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = value;//newNode  নতুন Node তৈরি হয়েছে,তার data মেম্বার ভেরিয়েবলে value নামের ভেরিয়েবলের মান বসানো হয়েছে।
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// পপ ফাংশন (স্ট্যাকের টপ থেকে ডাটা বাদ দেওয়া)
void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

// টপ ফাংশন (স্ট্যাকের টপের ডাটা দেখা)
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// স্ট্যাক প্রিন্ট ফাংশন
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// মেইন ফাংশন
int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
