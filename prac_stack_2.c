#include <stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
int is_empty(struct Stack* p)
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
int is_full(struct Stack *p)
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
void push(struct Stack *q,int value)
{
    if(is_full(q))
    {
        printf("Stack overloded\n");
    }
    else
    {
        q->top++;
        q->arr[q->top] = value;
        printf("Value: %d is pushed in the stack\n",value);

    }
}
void pop(struct Stack* q)
{
    if(is_empty(q))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("value: %d is poped from the stack\n",q->arr[q->top]);
        q->top = q->top - 1;
    }
}
void first(struct Stack* a)
{
    printf("Value at top is:%d\n",a->arr[a->top]);
}
void last(struct Stack* a)
{
    printf("Value at bottom is:%d\n",a->arr[0]);
}
int peek(struct Stack* m, int index)
{
    if(m->top - index < 0)
    {
        printf("cannot peek from the stack\n");
    }
    else
    {
        return m->arr[m->top - index];
    }
}
int main() 
{
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
    S->size = 100;
    S->top = -1;
    S->arr = (int *)malloc(S->size *sizeof(int));
    push(S, 10);
    push(S, 20);
    push(S, 30);
    push(S, 40);
    push(S, 50);
    push(S, 69);
    pop(S);
    for(int j = 0; j <= S->top; j++)
    {
        printf("value at index:%d is %d\n",j,peek(S,j));
    }
    first(S);
    last(S);
    return 0;
}