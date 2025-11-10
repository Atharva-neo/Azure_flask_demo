#include <stdio.h>
#include<stdlib.h>
#define SIZE 10
//node creation
struct node
{
    int data;
    struct node* next;
};
// new node
struct node* createnode(int data)
{
    struct node* x = (struct node*)malloc(sizeof(struct node));
    x->data = data;
    x->next = NULL;
    return x;
}
//hash function
int hashFunction(int key)
{
    return key % SIZE;
}
//hash table array 
struct node* hash_table[SIZE];

// insert node
struct node* insertnode(int key)
{
    int ind = hashFunction(key);
    struct node * new_node = createnode(key);


    new_node->next = hash_table[ind];
    hash_table[ind] = new_node;
}
void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        struct node* temp = hash_table[i];
        printf("Position %d: ",i);
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void delete(int key)
{
    int index = hashFunction(key);

    struct node* current  = hash_table[index];
    struct node* prv = NULL;
    while(current != NULL)
    {
        if(current->data == key)
        {
           if(prv == NULL)
           {
                hash_table[index] = current->next;
           }
           else
           {
                prv->next = current->next;
           }
           free(current);
           return;
        }
        prv = current;
        current = current->next;
    }
}

int main() 
{
        insertnode(10);
        insertnode(19);
        insertnode(20);
        display();
        delete(10);
        display();
        delete(20);
        display();
        return 0;
}