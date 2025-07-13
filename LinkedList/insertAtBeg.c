#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertAtBeg(struct Node**head,int value){
    struct Node* newNode=createNode(value);
    newNode->next=*head;
    *head=newNode;
}

void printList(struct Node* head){
    struct Node*temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head=NULL;
    int n,val;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        insertAtBeg(&head,val);
    }
    printList(head);
}