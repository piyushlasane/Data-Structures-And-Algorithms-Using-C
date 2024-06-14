#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, int data)
{
    if (isFull(s))
    {
        printf("\nStack overflow! Can't Push %d", data);
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
        printf("\n%d pushed to stack", s->arr[s->top]);
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack underflow! Can't pop");
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        printf("\n%d popped",val);
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 12);
    push(s, 21);
    push(s, 43);
    push(s, 56);
    push(s, 27); // stack overflow can't push
    printf("\nEmpty: %d", isEmpty(s));
    printf("\nFull : %d", isFull(s));
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s); // stack underflow can't pop
    printf("\nEmpty: %d", isEmpty(s));
    printf("\nFull : %d", isFull(s));
    return 0;
}