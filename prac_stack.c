#include <stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
int is_empty(struct stack* p)
{
    if(p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_full(struct stack* p)
{
    if(p->top == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack* q, int data)
{
    if(is_full(q))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        q->top++;
        q->arr[q->top] = data;
        printf("value:%d is pushed in the stack\n",data);
    }
}
void pop(struct stack* q)
{
    if(is_empty(q))
    {
        printf("cannot pop from an empty stack\n");
    }
    else
    {
        printf("%d poped from the stack\n",q->arr[q->top]);
        q->top = q->top-1;
    }
}
int peek(struct stack* t, int i)
{
    if(t -> top - i  < 0)
    {
        printf("cannot peek from the stack\n");

    }
    else
    {
        return t->arr[t -> top - i] ;
    }

}
int main() 
{
    struct stack *S =  (struct stack*)malloc(sizeof(struct stack));
    S->size = 100;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));
    push(S,10);
    push(S,20);
    push(S,30);
    push(S,40);
    push(S,50);
    pop(S);
    for(int j = 0; j <= S->top; j++)
    {
        printf("Value at index %d is : %d\n",j,peek(S,j) );
    }
    return 0;
}