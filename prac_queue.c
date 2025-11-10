#include <stdio.h>
#include<stdlib.h>
struct Queue
{
    int top;
    int back;
    int* arr;
    int size;
};
int is_empty(struct Queue* p)
{
    if(p->top == -1 && p->back == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_full(struct Queue* p)
{
    if(p->back == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct Queue* q, int value)
{
    if(is_full(q))
    {
        printf("Cannot Enqueue Further\n");
    }
    else
    {
        if(is_empty(q))
        {
            q->top = 0;
        }
        q->back++;
        q->arr[q->back] = value;
        printf("value %d Enqueued in the Queue\n",value);
    }
}
void dequeue(struct Queue* q)
{
    if(is_empty(q))
    {
        printf("cannot Dequeue from empty Queue\n");
    }
    
     if(q->top == 0 && q->back == 0)
    {
        printf("Dequeued %d from the Queue\n",q->arr[0]);
        q->top = q->back = -1;
    }
    else
    {
         printf("Dequeued %d from the Queue\n",q->arr[q->top]);
       q->top++;
    }
    
}
int peek(struct Queue *r, int index)
{
    if(r->top + index < 0)
    {
        printf("cannot peek in\n");
    }
    else
    {
        return r->arr[r->top + index];
    }
}
int main() 
{
    struct Queue* Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->size = 100;
    Q->top = -1;
    Q->back = -1;
    Q->arr = (int *)malloc(Q-> size * sizeof(int));

    enqueue(Q,10);
    enqueue(Q,20);
    enqueue(Q,30);
    enqueue(Q,40);
    enqueue(Q,50);
    dequeue(Q);
    dequeue(Q);
    dequeue(Q);
    enqueue(Q,45);
     dequeue(Q);

    for(int k = 0; k <= Q->back - Q->top; k++)
    {
        printf("Value at index %d is %d\n",k,peek(Q,k));
    }
    return 0;
}