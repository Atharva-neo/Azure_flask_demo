#include <stdio.h>
#include <stdlib.h>

#define SIZE 10   // Size of hash table

// Node structure for linked list (used in each hash bucket)
struct Node {
    int data;
    struct Node* next;
};

// Array of pointers to linked lists (hash table)
struct Node* hashTable[SIZE];

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hash function (simple modulo)
int hashFunction(int key) {
    return key % SIZE;
}

// Insert function
void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = createNode(key);

    // Insert at the beginning of the linked list
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search function
int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key)
            return 1; // Found
        temp = temp->next;
    }
    return 0; // Not found
}

// Delete function
void delete(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in hash table\n", key);
        return;
    }

    if (prev == NULL) {
        // Node to be deleted is at head
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("%d deleted successfully\n", key);
}

// Display function
void display() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = hashTable[i];
        printf("Bucket %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    // Initialize hash table with NULLs
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    insert(10);
    insert(20);
    insert(15);
    insert(7);
    insert(32);
    insert(42);

    printf("Hash Table:\n");
    display();

    printf("\nSearching for 15: %s\n", search(15) ? "Found" : "Not Found");
    printf("Searching for 99: %s\n", search(99) ? "Found" : "Not Found");

    printf("\nDeleting 20...\n");
    delete(20);

    printf("\nHash Table after deletion:\n");
    display();

    return 0;
}