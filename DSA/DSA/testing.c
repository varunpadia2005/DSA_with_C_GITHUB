#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// Char stack for operator handling (infix-postfix)
typedef struct char_stack {
    int top;
    int size;
    char *arr;
} char_stack;

// Double stack for evaluation
typedef struct double_stack {
    int top;
    int size;
    double *arr;
} double_stack;

// Precedence lookup table
const int PRECEDENCE[128] = {
    ['^'] = 3,
    ['*'] = 2, ['/'] = 2,
    ['+'] = 1, ['-'] = 1
};

// Function declarations
void init_char_stack(char_stack **s, int size);
void init_double_stack(double_stack **s, int size);
void infixToPostfix(char* infix, char* postfix);
double evaluatePostfix(char* postfix);

int main() { 
    char infix[100];
    char postfix[100];
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';
    
    infixToPostfix(infix, postfix);
    double result = evaluatePostfix(postfix);
    printf("Result: %lf\n", result);
    return 0;
}

// Char stack operations
void init_char_stack(char_stack **s, int size) {
    *s = malloc(sizeof(char_stack));
    (*s)->size = size;
    (*s)->top = -1;
    (*s)->arr = malloc(size * sizeof(char));
}

void push_char(char_stack *s, char data) {
    s->arr[++s->top] = data;
}

char pop_char(char_stack *s) {
    return s->arr[s->top--];
}

char peek_char(char_stack *s) {
    return s->arr[s->top];
}

// Double stack operations
void init_double_stack(double_stack **s, int size) {
    *s = malloc(sizeof(double_stack));
    (*s)->size = size;
    (*s)->top = -1;
    (*s)->arr = malloc(size * sizeof(double));
}

void push_double(double_stack *s, double data) {
    s->arr[++s->top] = data;
}

double pop_double(double_stack *s) {
    return s->arr[s->top--];
}

// Optimized conversion function
void infixToPostfix(char* infix, char* postfix) {
    char_stack *ops;
    int len = strlen(infix);
    init_char_stack(&ops, len);
    
    int i = 0, j = 0;
    while (infix[i]) {
        if (isspace(infix[i])) {
            i++;
            continue;
        }
        
        if (isdigit(infix[i]) || infix[i] == '.') {
            // Directly copy numbers without spaces (handled in evaluation)
            while (isdigit(infix[i]) || infix[i] == '.') 
                postfix[j++] = infix[i++];
            postfix[j++] = ' ';
        }
        else if (infix[i] == '(') {
            push_char(ops, '(');
            i++;
        }
        else if (infix[i] == ')') {
            while (ops->top != -1 && peek_char(ops) != '(') {
                postfix[j++] = pop_char(ops);
                postfix[j++] = ' ';
            }
            pop_char(ops); // Remove '('
            i++;
        }
        else {
            while (ops->top != -1 && 
                   PRECEDENCE[(int)peek_char(ops)] >= PRECEDENCE[(int)infix[i]]) {
                postfix[j++] = pop_char(ops);
                postfix[j++] = ' ';
            }
            push_char(ops, infix[i++]);
        }
    }
    
    // Add remaining operators
    while (ops->top != -1) {
        postfix[j++] = pop_char(ops);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    
    free(ops->arr);
    free(ops);
}

// Optimized evaluation function
double evaluatePostfix(char* postfix) {
    double_stack *nums;
    init_double_stack(&nums, strlen(postfix));
    
    char buffer[32];
    int buf_idx = 0;
    
    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i]) || postfix[i] == '.') {
            buffer[buf_idx++] = postfix[i];
        }
        else if (postfix[i] == ' ') {
            if (buf_idx > 0) {
                buffer[buf_idx] = '\0';
                push_double(nums, atof(buffer));
                buf_idx = 0;
            }
        }
        else {
            double b = pop_double(nums);
            double a = pop_double(nums);
            switch (postfix[i]) {
                case '+': push_double(nums, a + b); break;
                case '-': push_double(nums, a - b); break;
                case '*': push_double(nums, a * b); break;
                case '/': push_double(nums, a / b); break;
                case '^': push_double(nums, pow(a, b)); break;
            }
        }
    }
    
    double result = pop_double(nums);
    free(nums->arr);
    free(nums);
    return result;
}