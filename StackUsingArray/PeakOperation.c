#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size, top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("\nElement %d can't pushed to stack\n", data);
        printf("\nStack overflow!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
        printf("Element %d is pushed to stack\n", data);
    }
}
void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\ncan't pop  stack is empty\n");
        printf("\nStack underflow!\n");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        printf("Element %d popped from the stack\n", val);
    }
}
int peek(struct stack *ptr, int i)
{
    if ((ptr->top - i + 1) < 0)
    {
        printf("Invalid Position\n");
        return 0;
    }
    else
        return ptr->arr[ptr->top - i + 1];
}
int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr){
    return ptr->arr[0];
}
int main()
{
    struct stack *s;
    s = malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = malloc(s->size * sizeof(int));
    printf("\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    int pos;
    printf("Enter position number to peek: ");
    scanf("%d", &pos);
    printf("Element %d is present at position %d\n", peek(s, pos), pos);
    printf("Element %d is present at top of the stack\n", stackTop(s));
    printf("Element %d is present at bottom of the stack\n", stackbottom(s));
    return 0;
}