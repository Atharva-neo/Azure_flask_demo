#include<stdio.h>
#include<stdlib.h>
struct Node
{
   struct Node * next;
   int data;
};
void display(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
struct Node *Addatstart(struct Node * Head,int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    if(Head == NULL)
    {
        Head = p;
    }
    else
    {
        p->next = Head;
        Head = p;
    }
    return Head;
};
struct Node *AddAtEnd(struct Node* Head, int data)
{
    struct Node *ptr1 =(struct Node *)malloc(sizeof(struct Node));
    struct Node *p = Head;
    ptr1 ->data = data;
    ptr1->next  = NULL;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr1;
    return Head;
};
struct Node* InsertBtw(struct Node * Head, int data, int index)
{
    struct Node *ptr2 = (struct Node *)malloc(sizeof(struct Node));
    ptr2->data = data;
    ptr2->next = NULL;
    struct Node *p = Head;
    int i = 0;
    while(i < index-1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    ptr2->next = p->next;
    p->next = ptr2;
    return Head;
};
struct Node * DelAtStart(struct Node*Head)
{
    struct Node *p = Head;
    if(Head == NULL)
    {
        printf("Nothing to Delete");
    }
    else
    {
        Head = Head->next;
        free(p);
    }
    return Head;
};
struct Node * DelAtEnd(struct Node*Head)
{
    struct Node *p = Head;
    struct Node *q = NULL;//prior
    if(Head == NULL)
    {
        printf("Nothing To Delete\n");
        return NULL;
    }
    if(Head ->next == NULL)
    {
        free(Head);
        return NULL;
    }
    
        while(p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;//WE BREAK
        free(p);

    return Head;
};
struct Node * DelAtAnyIndex(struct Node*Head, int index)
{
    struct Node * m = Head;
    struct Node * n = NULL;
    if(Head == NULL)
    {
        printf("No Value to delete\n");
    }
    int i = 0;
    while(i < index )
    {
        n = m;
        m = m->next;
        i++;
    }
    n->next = m ->next;
    m->next = NULL;
    free(m);
    return Head;
};
int main()
{
    struct Node * Head;
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = 10;
    p->next = NULL;
    Head = p;
    Head = Addatstart(Head, 100);
    Head = AddAtEnd(Head, 200);
    Head = InsertBtw(Head, 300, 1);
    display(Head);
    Head = DelAtStart(Head);
    display(Head);
    Head = DelAtEnd(Head);
    Head = Addatstart(Head, 100);
    Head = AddAtEnd(Head, 200);
    display(Head);
    Head = DelAtAnyIndex(Head, 2);
    display(Head);
    Head = AddAtEnd(Head, 900);
    Head = AddAtEnd(Head, 700);
    display(Head);
    Head = InsertBtw(Head, 34, 3);
    Head = DelAtAnyIndex(Head, 3);
    display(Head);
}