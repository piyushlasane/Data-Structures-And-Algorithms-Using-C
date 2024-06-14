#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

int isFull(struct node *top)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if (n==NULL)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct node *top)
{
    if (top==NULL)
    {
        return 1;
    }
    return 0;
}
void push(struct node** ptr, int data)
{
    if (isFull(*ptr))
    {
        printf("Stack overflow\n");
        return;
    }
    else
    {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        if (n!=NULL)
        {
            n->data=data;
            n->next=*ptr;
            *ptr=n;
        }
    }
}
int main()
{
    struct node *top=NULL;
    push(&top, 58);
    printf("Empty: %d\n", isEmpty(top));
    printf("Full : %d\n", isFull(top));
    return 0;
}