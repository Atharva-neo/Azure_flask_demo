#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Enqueue operation (Insert at rear)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow (Memory not allocated)\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // First element
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d to the queue\n", value);
}

// Dequeue operation (Remove from front)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow (Empty queue)\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Dequeued %d from the queue\n", q->front->data);
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Peek front element
int peekFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Peek rear element
int peekRear(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->rear->data;
}

// Display queue elements
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("\n");
    display(q);

    printf("\nFront element: %d\n", peekFront(q));
    printf("Rear element: %d\n\n", peekRear(q));

    dequeue(q);
    dequeue(q);

    printf("\nAfter two dequeues:\n");
    display(q);

    printf("\nFront element: %d\n", peekFront(q));
    printf("Rear element: %d\n", peekRear(q));

    return 0;
}
