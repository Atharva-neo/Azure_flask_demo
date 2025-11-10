#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int top ;
    int back ;
    int size;
    int * arr;
};
int isEmpty(struct Queue *p)
{
    if(p->back == p->top)
    {
        return - 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Queue * ptr)
{
    if(ptr->back == ptr->size - 1)
    {
        return - 1;
    }
    else
    {
        return 0;
    }
}
void Enqueue(struct Queue *ptr2, int value)
{
    if(isFull(ptr2))
    {
        printf("Cannot Enqueue any value\n");
    }
    else{
        ptr2->back++;
        ptr2->arr[ptr2->back] = value;
        printf("Enqueued %d in the queue\n",value);
    }
}
void Dequeue(struct Queue *ptr3)
{   
    int a = -1;
    if(isEmpty(ptr3))
    {
        printf("Cannot Dequeue\n");
    }
    else{
        ptr3->top++;
        a = ptr3->arr[ptr3->top];
        if(a != -1)
        {printf("The Dequeued value is %d\n",a);}
        else
        {
            return a;
        }
    
    }
}
int main()
{

    struct Queue * Q;
    Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->size = 100;
    Q->top = -1;
    Q->back = -1;
    Q->arr = (int*)malloc(Q-> size *sizeof(int));
  
    Enqueue(Q,20);
    Enqueue(Q,12);
    Enqueue(Q,10);
    Enqueue(Q,87);
    Enqueue(Q,34);
    Enqueue(Q,76);
    Enqueue(Q,89);
    Enqueue(Q,90);

    Dequeue(Q);
     Dequeue(Q);
     Dequeue(Q);
    Dequeue(Q);
     Dequeue(Q);
     Dequeue(Q);
        Dequeue(Q);
     Dequeue(Q);
     Dequeue(Q);
         Dequeue(Q);
     Dequeue(Q);
     Dequeue(Q);
    return 0;
}