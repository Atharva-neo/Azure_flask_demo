#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int front;
    int back;
    int *arr;
    int size;
};

int is_empty(struct Queue *ptr1)
{
    if(ptr1->front == ptr1->back)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int is_full(struct Queue *ptr2)
{
    if((ptr2->back + 1)% (ptr2->size) == ptr2->front)
    {
        return -1;
    }
    else{
        return 0;
    }
}
int Enqueue(struct Queue* q,int value)
{
    if(is_full(q))
    {
        printf("Cannot Enqueue\n");
    }
    else{
        q->back = (q->back+1)%q->size;
        q->arr[q->back] = value;
        printf("Enqueued %d in circular queue\n",value);
    }
}
int main()
{
    struct Queue *Q;
    Q = (struct Queue*)malloc(sizeof (struct Queue));
    Q->size = 5;
    Q->front = -1;
    Q->back = -1;
    Q->arr = (int *)malloc(Q->size * sizeof(int));
    Enqueue(Q, 1);
}