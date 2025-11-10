#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define SIZE 10
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* x = (struct Node*)malloc(sizeof(struct Node));
    x->data = data;
    x->next = NULL;
    return x;
}
int hash_function(int key)
{
    return key % SIZE;
}
struct Node* hash_table[SIZE];

void insert(int data)
{
    struct Node* new_node = createNode(data);
    int index = hash_function(data);

    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}
void display()
{
    struct Node* p ;
        for(int i = 0; i < SIZE; i++)
        {
            p = hash_table[i];
            printf("Position %d:",i);
            while(p != NULL)
            {
                printf(" %d -> ",p->data);
                p = p->next;
            }
            printf("NULL\n");
        }
}
void search(int data)
{
    struct Node* p;
    int index = hash_function(data);
    p = hash_table[index];
    while(p != NULL)
    {
        if( p->data == data)
        {
            printf("Element Found\n");
            return;
        }
        p = p->next;
        
    }
    printf("Element not present\n");
    
}
void delete(int data)
{
    struct Node* p;
    struct Node * prv = NULL;
    int index = hash_function(data);
    p = hash_table[index];
    while(p != NULL)
    {
        if(p->data == data)
        {
            if(prv == NULL)
            {
                hash_table[index] = p->next;
            }
            else
            {
                prv->next = p->next;
            }
            free(p);
            return;
        }
        prv = p;
        p = p->next;

    }

}

int main() 
{
    insert(2);
    insert(3);
    display();
    search(10);
    delete(3);
    display();
    return 0;
}