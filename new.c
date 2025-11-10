//Elements : 12 23 1 56 33
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  


typedef struct {
    int data[MAX];
    int front, rear;
} Queue;


void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(Queue *q) {
    return q->front == -1;
}


int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}


void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue overflow! Cannot enqueue %d\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = value;
        printf("Enqueued %d into queue\n", value);
    }
}


void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow! Nothing to dequeue.\n");
    } else {
        int removed = q->data[q->front];
        if (q->front == q->rear) {
            
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("Dequeued %d from queue\n", removed);
    }
}


void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing at front.\n");
    } else {
        printf("Front element is: %d\n", q->data[q->front]);
    }
}


void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents (front to rear): ");
        int i = q->front;
        while (1) {
            printf("%d ", q->data[i]);
            if (i == q->rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}


int main() {
    Queue q;
    init(&q);

    int choice, val;

    do {
        printf("\n Queue Menu \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                display(&q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}