#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void display(struct Node* p)
{
    while(p != NULL)
    {
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("NULL\n");
}
struct Node *Add_at_start(struct Node* Head, int data)
{
    
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if(Head == NULL)
    {
        Head = ptr;
      
    }
    else{
            ptr->next= Head;
            Head = ptr;
        }
      return Head;
}
struct Node *Add_at_end(struct Node* Head, int data)
{
    struct Node* p = Head;
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if(p == NULL)
    {
        printf("Cannot add at end\n");
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    return Head;
    
}
struct Node*Add_at_any_index(struct Node* Head,int data, int index)
{
    struct Node* p = Head;
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    int i = 0;
    while(i < index - 1 && p != NULL)
    {
        p = p->next;
        i++;
    }
    ptr-> next = p->next;
    p->next = ptr;
    return Head;
}
struct Node* Del_at_start(struct Node* Head)
{
    struct Node*p = Head;
    if(Head == NULL)
    {
        printf("Cannot delete from empty list\n");
        return NULL;
    }
    Head = p->next;
    free(p);
    return Head;
}
struct Node* Del_at_end(struct Node* Head)
{
    struct Node* p = Head;
    struct Node*q = NULL;
    if(Head == NULL)
    {
        printf("Cannot delete from empty list\n");
        return NULL;
    }
    if(Head->next == NULL)
    {
        free(p);
        return NULL;
    }
    while(p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    return Head;
}
struct Node* Del_at_any_index(struct Node* Head,int index)
{
    struct Node* p = Head;
    struct Node* q = NULL;
    int i = 0;
    while(i < index)
    {
        q = p;
        p = p->next;
        i++;
    }
    q->next = p->next;
    p->next = NULL;
    free(p);
    return Head;

}
int main() 
{
    struct Node* Head = NULL;
    Head = Add_at_start(Head, 10);
    Head = Add_at_start(Head, 20);
    Head = Add_at_start(Head, 30);
    Head = Add_at_end(Head, 70);
    Head = Add_at_any_index(Head,100, 3);
    Head = Del_at_start(Head);
    display(Head);
    Head = Del_at_end(Head);
    display(Head);
    Head = Del_at_any_index(Head,2);
    display(Head);
    return 0;
}