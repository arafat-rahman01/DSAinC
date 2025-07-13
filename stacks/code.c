#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct IntNode{
    int data;
    struct IntNode* Next;
};

struct CharNode{
    int data;
    struct CharNode* Next;
};


struct CharNode* opTop=NULL;
struct IntNode* valTop=NULL;

void pushChar(char val){
    struct CharNode* newNode=(struct CharNode*)malloc(sizeof(struct CharNode));
    newNode->data=val;
    newNode->Next=opTop;
    opTop=newNode;
}

char popChar(){
    if(opTop==NULL) return '\0';
    struct CharNode* temp=opTop;
    char val=temp->data;
    opTop=opTop->Next;

    free(temp);
    return val;
}

char peekChar(){
    if(opTop==NULL) return '\0';
    return opTop->data;
}

int isEmptyChar(){
    return opTop=='\0';
}

void pushInt(int val){
    struct IntNode* newNode=(struct IntNode*)malloc(sizeof(struct IntNode));
    newNode->data=val;
    newNode->Next=valTop;
    valTop=newNode;
}

int popInt(){
    if(valTop==NULL) return 0;
    struct IntNode* temp=valTop;
    int val=temp->Next;
    valTop=valTop->Next;
    free(temp);
    return val;
}

int isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int precendence(char op){
    if(op=='^') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}
