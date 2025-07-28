/*
 Name-Varun Padia
 Roll No-241003003101
 Date-21/05/2025
 Program to check whether an expression contains properly matched parentheses.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stacks{
    int top;
    int size;
    int *array;
}Stacks;

void init(Stacks **s, int size);
bool isEmpty(Stacks *s);
bool isFull(Stacks *s);
void push(Stacks *s, int data);
int pop(Stacks *s);
int peak(Stacks *s);
bool parenthsis_check(const char* cha);

int main() 
{
    int max=100;
    char expression[max];
    printf("Enter an expression with parentheses: ");
    fgets(expression, max, stdin);          // to input the string from the user.
    if (parenthsis_check(expression))
        printf("The expression have balanced parentheses.\n");
    else
        printf("The expression does not have balanced parentheses.\n");
    return 0;
}
void init(Stacks **s, int size) 
{
    Stacks *temp = (Stacks *)calloc(1, sizeof(Stacks));
    temp->size = size;
    temp->top = -1;
    temp->array = (int *)calloc(size, sizeof(int));
    *s = temp;
}
bool isEmpty(Stacks *s) 
{
    return s->top == -1; 
}
bool isFull(Stacks *s) 
{
    return s->top == s->size - 1; 
}
void push(Stacks *s, int data) 
{
    s->array[++(s->top)] = data;
}
int pop(Stacks *s) 
{
    return s->array[(s->top)--];
}
int peak(Stacks *s) 
{
    return s->array[s->top];
}
bool parenthsis_check(const char *cha)          //to check the parenthesis.
{               
    Stacks *s;
    init(&s, strlen(cha));

    for (int i = 0; i < strlen(cha); i++) {
        char ch = cha[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(s, ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(s)) {
                free(s->array);
                free(s);
                return false;
            }
            char top = pop(s);
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                free(s->array);
                free(s);
                return false;
            }
        }
    }
    free(s->array);
    free(s);
    return true;
}