#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *ListInsertion_inBetween(struct node *head, int index)
{
    struct node *p = head;
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->data = 128;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    a->next = p->next;
    p->next = a;
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
    head->data = 16;
    head->next = second;

    second->data = 32;
    second->next = third;

    third->data = 64;
    third->next = fouth;

    fouth->data = 256;
    fouth->next = NULL;

    traversal(head);
    head = ListInsertion_inBetween(head, 3);
    traversal(head);
    return 0;
}