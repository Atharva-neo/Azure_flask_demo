#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct Stack* p)
{
    if(p -> top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct Stack* q)
{
    if(q -> top == q->size-1)
        return 1;
    else
        return 0;
}
//push operation
void push(struct Stack * ptr, int value)
{
    if(isFull(ptr))
    {
        printf("stack Overflow\n");
    }
    else
    {   ptr ->top ++;
        ptr->arr[ptr->top] = value;
        printf("Pushed %d to the stack\n",value);
    }
};
//pop operation
void pop(struct Stack * ptr1)
{
    if(isEmpty(ptr1))
    {
        printf("stack is empty\n  ");
    }
    else
    {   
        
        printf("Poped %d from the stack\n", ptr1->arr[ptr1->top]);
        ptr1->top = ptr1->top-1;
    }
};
int peek(struct Stack * sp, int i)
{
    if(sp->top - i + 1 < 0)
    {
        printf("Not a valid position\n");
        return - 1;
    }
    else
    {
        return sp->arr[sp->top- i +1];
    }
}
int StackTop(struct Stack * ptr2)
{
    return ptr2->arr[ptr2->top];
}
int StackBottom(struct Stack * ptr3)
{
    return ptr3->arr[0];
}
int main()
{
    struct Stack * S = (struct Stack *)malloc(sizeof(struct Stack));
    S->size = 100;
    S->top = -1;
    S->arr = (int*)malloc(S->size * sizeof(int));
    printf("%d\n",isFull(S));
    printf("%d\n",isEmpty(S));
    push(S, 30);
    push(S, 10);
    push(S, 12);
    push(S, 39);
    push(S, 44);
    push(S, 67);
    push(S, 20);
    printf("\n");
    pop(S);
    pop(S);
    pop(S);
    pop(S);
    peek(S,3);
    
    for(int j = 1; j <= S -> top + 1; j++)
    {
        printf("The value at index %d is %d\n",j,peek(S, j));
    }
    printf("Value at Top of Stack is %d\n",StackTop(S));
    printf("Value at Bottom of Stack is %d",StackBottom(S));
    
    return 0;
}
