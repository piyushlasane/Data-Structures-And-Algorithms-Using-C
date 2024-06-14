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
        printf("\n%c pushed to stack", data);
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
        printf("\n%c is popped", val);
        return val;
    }
}

int ismatching(char a, char b)
{
    if (a=='{' && b=='}' || a=='[' && b==']' || a=='(' && b==')')
    {
        return 1;
    }
    return 0;
}

int parenthesis_matching(struct stack *p, char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(p, exp[i]);
        }
        if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
        {
            if (isEmpty(p))
            {
                printf("\nStack is empty, can't pop");
                return 0;
            }
            else
            {
                char poppedElement=pop(p);
                if (!ismatching(poppedElement, exp[i]))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    p->size = 20;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));
    char *expression = "{(a+b-[(c*d)]{(k+z))}))";
    parenthesis_matching(p, expression);
    if (isEmpty(p))
    {
        printf("\nParenthesis Are Matching.");
    }
    else
    {
        printf("\nParenthesis Are Not Matching.");
    }
    return 0;
}