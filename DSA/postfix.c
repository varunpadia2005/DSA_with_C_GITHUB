#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<math.h>
typedef struct stack {
    int size;
    int top;
    char *arr;
} stack;
void insertstack(stack **s, int size);
int isEmpty(stack *ptr);
int isFull(stack *ptr);
void push(stack *ptr, char data);
char pop(stack *ptr);
char peak(stack *ptr);
void infixToPostfix(char *infix, stack *s, char *postfix);
double evaluatePostfix(char *postfix);
int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
int main() {
    int var;
    printf("Enter the no.of variable in the expression");
    scanf("%d",&var);
    char* infix;
    char* postfix;
    infix=(char *)calloc(sizeof(char),(2*var)-1);
    postfix=(char *)calloc(sizeof(char),(2*var)-1);
    stack *s = NULL;
    printf("Enter the infix expression:  ");
    scanf("%s", infix);
    insertstack(&s, strlen(infix));
    
    infixToPostfix(infix, s, postfix);
    printf("Postfix expression: %s\n", postfix);

    double answer=evaluatePostfix(postfix);
    printf("Postfix evaluation: %d\n", answer);
    return 0;
}
// Fuction to convert Infix to Postfix expression.
void infixToPostfix(char *infix, stack *s, char *postfix) {
    int j = 0;
    for(int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if(isalnum(c)) {
            postfix[j++] = c;
        }
        else if(c == '(') {
            push(s, c);
        }
        else if(c == ')') {
            while(!isEmpty(s) && peak(s) != '(') {
                postfix[j++] = pop(s);
            }
            if(isEmpty(s)) {
                printf("Mismatched parentheses\n");
                exit(1);
            }
            pop(s);
        }
        else {
            while(!isEmpty(s) && precedence(peak(s)) >= precedence(c))
                postfix[j++] = pop(s);
            push(s, c);
        }
    }
    while(!isEmpty(s)) {
        if(peak(s) == '(') {
            printf("Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
}

// Postfix evaluation with exponentiation support
double evaluatePostfix(char *postfix) {
    double evalStack[100];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        
        if(isdigit(c)) {
            evalStack[++top] = c - '0';  // Convert char to number
        }
        else {
            double b = evalStack[top--];
            double a = evalStack[top--];
            
            switch(c) {
                case '+': evalStack[++top] = a + b; break;
                case '-': evalStack[++top] = a - b; break;
                case '*': evalStack[++top] = a * b; break;
                case '/': evalStack[++top] = a / b; break;
                case '^': evalStack[++top] = pow(a, b); break;
                default : printf("Invalid operator: %c\n", c);
                exit(1);
            }
        }
    }
    return evalStack[top];
}
void insertstack(stack **s, int size) {
    stack *temp = (stack *)calloc(sizeof(stack),1);
    temp->size = size;
    temp->top = -1;
    temp->arr = (char *)calloc(size, sizeof(char));
    *s = temp;
}
int isEmpty(stack *ptr) {
    return ptr->top == -1;
}
int isFull(stack *ptr) {
    return ptr->top == ptr->size - 1;
}
void push(stack *ptr, char data) {
    if(isFull(ptr))
        printf("Stack Overflow\n");
    else 
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
char pop(stack *ptr) {
    if(isEmpty(ptr)) {
        printf("Stack Underflow\n");
        return '\0';
    } 
    else 
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
char peak(stack *ptr) {
    if(isEmpty(ptr))
        return '\0';
    else
        return ptr->arr[ptr->top];
}