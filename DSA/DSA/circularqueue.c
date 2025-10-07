// this is a program to implement a circular queue in c using array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    

typedef struct circularqueue {
    int front, rear, size, count;
    int *arr;
}cqueue; 
void init(cqueue **q, int size);
bool isFull(cqueue *q);
bool isEmpty(cqueue *q);
void enqueue(cqueue *q, int data);
int dequeue(cqueue *q);
void display(cqueue *q); 

int main() {
    cqueue *s;
    int size, choice, data;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    init(&s, size);     
    do{
        printf("0. Exit\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice: ");  
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                if (isFull(s)) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter the data to be enqueued: ");
                    scanf("%d", &data);
                    enqueue(s, data);
                }
                break;
            case 2: 
                if (isEmpty(s)) {
                    printf("Queue is empty\n");
                } else {
                    data = dequeue(s);
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3: 
                if (isEmpty(s)) {
                    printf("Queue is empty\n");
                } else {
                    display(s);
                }
                break;  
            case 0: 
                printf("Thanks for using the stack operations");
                break;
            default: 
                printf("Invalid choice\n");
        }
    }while(choice != 0);
    return 0;
}

void init(cqueue **s, int size) {
    cqueue *temp = (cqueue *)calloc(1, sizeof(cqueue));
    temp->front = temp->rear = -1; // Initialize front and rear to -1
    temp->size = size;
    temp->count = 0; // Initialize count to 0
    temp->arr = (int *)calloc(size, sizeof(int)); // Allocate array of size
    *s = temp;
}

bool isFull(cqueue *q) { 
    return q->count == q->size; // Check if count equals size
}

bool isEmpty(cqueue *q) {
    return q->count == 0; // Check if count is 0
}

void enqueue(cqueue *q, int data) {
    q->rear = (q->rear + 1) % q->size; // Wrap around using size
    q->arr[q->rear] = data;
    q->count++; // Increment count
}

int dequeue(cqueue *q) {
    q->front = (q->front + 1) % q->size; // Wrap around using size
    q->count--; // Decrement count
    return q->arr[q->front];
}

void display(cqueue *q) {
    printf("Queue elements: ");
    for(int i = (q->front + 1) % q->size, printed = 0; printed < q->count; i = (i + 1) % q->size, printed++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}