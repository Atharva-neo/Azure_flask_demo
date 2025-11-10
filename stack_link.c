#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Check if stack is empty
int isEmpty(struct Node* top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

// Push operation
struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow (Memory not allocated)\n");
        return top;
    } else {
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        printf("Pushed %d to the stack\n", value);
        return top;
    }
}

// Pop operation
struct Node* pop(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack Underflow (Empty stack)\n");
    } else {
        struct Node* temp = top;
        printf("Popped %d from the stack\n", top->data);
        top = top->next;
        free(temp);
    }
    return top;
}

// Peek operation
int peek(struct Node* top, int position) {
    struct Node* ptr = top;
    for (int i = 1; i < position && ptr != NULL; i++) {
        ptr = ptr->next;
    }
    if (ptr != NULL)
        return ptr->data;
    else
        return -1;  // Invalid position
}

// Stack top
int stackTop(struct Node* top) {
    if (!isEmpty(top))
        return top->data;
    return -1;
}

// Stack bottom
int stackBottom(struct Node* top) {
    struct Node* ptr = top;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr->data;
}

// Display stack
void display(struct Node* top) {
    struct Node* ptr = top;
    int i = 1;
    while (ptr != NULL) {
        printf("Value at position %d is %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

// Main function
int main() {
    struct Node* top = NULL;  // Empty stack initially

    // Push elements
    top = push(top, 30);
    top = push(top, 10);
    top = push(top, 12);
    top = push(top, 39);
    top = push(top, 44);
    top = push(top, 67);
    top = push(top, 20);

    printf("\n");

    // Pop elements
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);

    printf("\n");
    display(top);

    printf("\nTop element: %d\n", stackTop(top));
    printf("Bottom element: %d\n", stackBottom(top));

    return 0;
}
