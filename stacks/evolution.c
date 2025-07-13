#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Node structure for char stack (operators)
struct CharNode {
    char data;
    struct CharNode* next;
};

// Node structure for int stack (values)
struct IntNode {
    int data;
    struct IntNode* next;
};

// Stack top pointers
struct CharNode* opTop = NULL;
struct IntNode* valTop = NULL;

// Stack operations for char stack (operators)
void pushChar(char val) {
    struct CharNode* newNode = (struct CharNode*)malloc(sizeof(struct CharNode));
    newNode->data = val;
    newNode->next = opTop;
    opTop = newNode;
}
char popChar() {
    if (opTop == NULL) return '\0';
    struct CharNode* temp = opTop;
    char val = temp->data;
    opTop = opTop->next;
    free(temp);
    return val;
}
char peekChar() {
    if (opTop == NULL) return '\0';
    return opTop->data;
}
int isEmptyChar() {
    return opTop == NULL;
}

// Stack operations for int stack (values)
void pushInt(int val) {
    struct IntNode* newNode = (struct IntNode*)malloc(sizeof(struct IntNode));
    newNode->data = val;
    newNode->next = valTop;
    valTop = newNode;
}
int popInt() {
    if (valTop == NULL) return 0;
    struct IntNode* temp = valTop;
    int val = temp->data;
    valTop = valTop->next;
    free(temp);
    return val;
}

// Operator helper functions
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            pushChar(ch);
        }
        else if (ch == ')') {
            while (!isEmptyChar() && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            popChar(); // discard '('
        }
        else if (isOperator(ch)) {
            while (!isEmptyChar() && precedence(peekChar()) >= precedence(ch)) {
                postfix[j++] = popChar();
            }
            pushChar(ch);
        }
    }
    while (!isEmptyChar()) {
        postfix[j++] = popChar();
    }
    postfix[j] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char* postfix) {
    int i = 0;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            pushInt(ch - '0');
        } else {
            int op2 = popInt();
            int op1 = popInt();
            switch (ch) {
                case '+': pushInt(op1 + op2); break;
                case '-': pushInt(op1 - op2); break;
                case '*': pushInt(op1 * op2); break;
                case '/': pushInt(op1 / op2); break;
                case '^': pushInt((int)pow(op1, op2)); break;
            }
        }
    }
    return popInt();
}

// Main function
int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression (single-digit numbers only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
