/*
 Name-Varun Padia 241003003101
 Date-21/05/2025
 Program to convert a given infix operator to postfix opertor and solve the equation. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct fix{
    int top;
    int size;
    double *arr;
}fix;
void init(fix **f, int size);
int operator_precedence(char op);
bool isEmpty(fix *f);
bool isFull(fix *f);
void push(fix *f, double data);
double pop(fix *f);
double peak(fix *f);
void infix_to_postfix(char* in_fix, char* post_fix);
double evaluate_Postfix(char* post_fix);

int main()
{ 
    char in_fix[80];
    char post_fix[80];
    printf("Enter yours infix expression : ");
    fgets(in_fix, sizeof(in_fix), stdin);
    infix_to_postfix(in_fix, post_fix);
    double result = evaluate_Postfix(post_fix);
    printf("Evaluation of the expression : %lf\n\n",result);
    printf("Thanks! for using the infix to postfix evaluation expression.");
    return 0;
}

void init(fix **f,int size) {
    fix* temp=(fix*)calloc(1,sizeof(fix));
    temp->size=size;
    temp->top=-1;
    temp->arr=(double*)calloc(size,sizeof(double));
    *f=temp;
}
int operator_precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}
bool isEmpty(fix *f) {
    if(f->top==-1)
        return true;
    return false;
}
bool isFull(fix *f) {
    if(f->top==f->size-1)
        return true;
    return false;
}
void push(fix *f,double data) {
    f->arr[++(f->top)]=data;
}
double pop(fix *f) {
    return f->arr[(f->top)--];
}
double peak(fix *f) {
    return f->arr[f->top];
}
void infix_to_postfix(char* in_fix, char* post_fix) {
    fix *f;
    init(&f, strlen(in_fix));
    int i = 0, j = 0;
    while (in_fix[i] != '\0') {
        if (isspace(in_fix[i])) {    
            i++;
            continue;
        }
        if (isdigit(in_fix[i]) || in_fix[i] == '.') {    // to handles multiple digits and decimal numbers.
            while (isdigit(in_fix[i]) || in_fix[i] == '.') 
                post_fix[j++] = in_fix[i++];
            post_fix[j++] = ' ';
        }
        else if (in_fix[i] == '(') {     // Push '(' into fix structure
            push(f, in_fix[i]);
            i++;
        }
        else if (in_fix[i] == ')') {      // Pop until '('
            while (!isEmpty(f) && peak(f) != '(') {    
                post_fix[j++] = (char)pop(f);
                post_fix[j++] = ' ';
            }
            pop(f);
            i++;
        }
        else {                 // handles Operator
            while (!isEmpty(f) && operator_precedence(in_fix[i]) <= operator_precedence(peak(f))) {       
                post_fix[j++] = (char)pop(f);
                post_fix[j++] = ' ';
            }
            push(f, in_fix[i]);
            i++;
        }
    }
    while (!isEmpty(f)) {        // Pop remaining operators from fix
        post_fix[j++] = (char)pop(f);
        post_fix[j++] = ' ';
    }
    post_fix[j] = '\0';           

    free(f->arr);                // to free up the memory
    free(f);
}
double evaluate_Postfix(char* post_fix) {
    fix *f;
    init(&f, strlen(post_fix));
    int i = 0;
    while (post_fix[i] != '\0') {
        if (isspace(post_fix[i])) {    // to skip space 
            i++;
            continue;
        }
        if (isdigit(post_fix[i]) || post_fix[i] == '.') {       
            char num[32];
            int k = 0;
            while (isdigit(post_fix[i]) || post_fix[i] == '.') {
                num[k++] = post_fix[i++];
            }
            num[k] = '\0';
            push(f, atof(num));             
        } 
        else {                           
            double op2 = pop(f);
            double op1 = pop(f);
            switch (post_fix[i]) {
                case '+': push(f, op1 + op2); break;
                case '-': push(f, op1 - op2); break;
                case '*': push(f, op1 * op2); break;
                case '/': push(f, op1 / op2); break;
                case '^': push(f, pow(op1, op2)); break;
            }
            i++;
        }
    }
    double result = pop(f);        // to store the final result of the expression.

    free(f->arr);        // to free up the memory.
    free(f);
    return result;         //to return the final evaluated result of the expression.
}