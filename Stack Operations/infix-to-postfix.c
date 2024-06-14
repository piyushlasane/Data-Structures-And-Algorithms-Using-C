#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *s, char data)
{
    if (isFull(s))
    {
        printf("\nStack overflow! Can't Push %c", data);
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
        printf("\n%c pushed to stack", s->arr[s->top]);
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack underflow! Can't pop");
    }
    else
    {
        char val = s->arr[s->top];
        s->top--;
        printf("\n%c popped", val);
        return val;
    }
}

int stackTop(struct stack * sp)
{
    return sp->arr[sp->top];
}

int isoperand(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    return 0;
}

int precedance(char a)
{
    if (a=='+'||a=='-')
    {
        return 1;
    }
    else if (a=='*'||a=='/')
    {
        return 2;
    }
    else return 0;
}

char *infixToPosfix(char *exp, struct stack *sp)
{
    char *postfixed_exp = (char *)malloc(sp->size * sizeof(char));
    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        if (!isoperand(exp[i]))
        {
            postfixed_exp[j] = exp[i];
            i++;
            j++;
        }
        else
        {
            if (precedance(exp[i])>precedance(stackTop(sp)))
            {
                push(sp, exp[i]);
                i++;
            }
            else
            {
                postfixed_exp[j]=pop(sp);
                j++;
            }
            
        }
    }
    while (!isEmpty(sp))
    {
        postfixed_exp[j]=pop(sp);
        j++;
    }
    postfixed_exp[j]='\0';
    return postfixed_exp;
}

int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    sp->top = -1;
    char *exp = "a+b*c-d/e+f/g";
    char *o = infixToPosfix(exp, sp);
    printf("\nPost fixed expression : %s", o);
    return 0;
}