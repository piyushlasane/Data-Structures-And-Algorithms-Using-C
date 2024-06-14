#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *ListDeletion_Last(struct node *head)
{
    struct node *p = head;
    struct node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (q->next != p)
    {
        q = q->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fouth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fouth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fouth;

    fouth->data = 4;
    fouth->next = NULL;
    int data = 5;
    traversal(head);
    head = ListDeletion_Last(head);
    traversal(head);
    return 0;
}