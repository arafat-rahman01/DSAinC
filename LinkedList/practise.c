#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void insertAtBeg(struct Node**head,int val){
    struct Node* newNode=createNode(val);
    newNode->next=*head;
    *head=newNode;
}

void insertAtLast(struct Node**head,int val){
    struct Node* newNode=createNode(val);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printList(struct Node*head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node*head=NULL;
    int n;
    scanf("%d",&n);
    int val;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        insertAtBeg(&head,val);
    }
    printList(head);
}