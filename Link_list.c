#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next; //self replacing structure 
};
//traverse
void linkedlistTraversal(struct Node* ptr)
{
    while(ptr != NULL)
    {   printf("%d -> ",ptr -> data);
        ptr = ptr->next;
    }
    printf("NULL\n"); 
    
}
// //insert at first
// struct Node* insertatFirst(struct Node *Head, int data)
// {
//     struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
//     ptr1->next = Head;
//     ptr1->data = data;
//     Head = ptr1;
// };
//insert at end
struct Node* insertatend(struct Node *Head, int data)
{
    struct Node *ptr3 = (struct Node *)malloc(sizeof(struct Node));
    ptr3->data = data;
    ptr3 ->next = NULL;
    if(Head == NULL)
    {
       return ptr3;
    }
    struct Node * p = Head;

    while(p -> next != NULL)
    {
        p = p ->next;
    }
    p ->next = ptr3;
    return Head;
 
};
//Insrt at any point
struct Node* insteratany(struct Node *Head, int data, int index)
{
    struct Node *ptr2 = (struct Node *) malloc(sizeof(struct Node));
    struct Node *p = Head;
    
    ptr2 -> data = data;
    for(int i = 0; i < index - 1 ; i++)
    {
        p = p -> next ;
    }
    ptr2 ->next = p -> next;
    p -> next = ptr2;
    return Head;
    
};

//Insert after a node
struct Node* AfteraNode(struct Node *Head, struct Node *prvNode, int data)
{
    struct Node *ptr4 = (struct Node*) malloc(sizeof(struct Node));
    ptr4->data = data;
    ptr4->next = prvNode->next;
    prvNode->next = ptr4;
    return Head;
};

//Del at First
struct Node *Delfi(struct Node * Head)
{
    struct Node *p = Head;
    if(Head != NULL)
    {
        Head = Head->next;
        free(p);
    }
    else
    {
        printf("Cannot Remove");
    }
    return Head;
};

int main()
{
    struct Node* Head;
    struct Node* Second;
    struct Node* Third;
    struct Node* Temp;
    struct Node* Temp1;
    struct Node* Temp2;


    //memory allocation in Heap
    Head = (struct Node *) malloc(sizeof(struct Node));
    Second = (struct Node *) malloc(sizeof(struct Node));
    Third = (struct Node *) malloc(sizeof(struct Node));
    Temp = (struct Node *) malloc(sizeof(struct Node)); 
    Temp1 = (struct Node*) malloc(sizeof(struct Node));
    Temp2 = (struct Node *) malloc(sizeof(struct Node));
       
    //Link first and Second Node
    Head->data = 10;
    Head->next = Second;

    //Link second and Third Node
    Second->data = 20;
    Second->next = Third;

    //Link Third and Null Node
    Third->data = 30;
    Third->next = NULL;

 

    //temp1
    Temp1->data = 200;
    Temp1->next = NULL;
    Third->next = Temp1;

    //temp2
    Temp2 -> data = 500;
    Second->next = Temp2;
    Temp2 ->next = Third;

    //call
    // linkedlistTraversal(Head);
    // Head = insertatFirst(Head, 100);
    linkedlistTraversal(Head);
    insteratany(Head, 800, 4);
    linkedlistTraversal(Head);
    insertatend(Head, 2000);
    linkedlistTraversal(Head);
    AfteraNode(Head, Third, 3000);
    linkedlistTraversal(Head);
    Delfi(Head);
    linkedlistTraversal(Head);
    return 0;
}