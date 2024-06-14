#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *ListInsertion_atFirst(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = 8;
    ptr->next = head;
    return ptr;
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

    fouth->data = 128;
    fouth->next = NULL;

    traversal(head);
    head = ListInsertion_atFirst(head);
    traversal(head);
    return 0;
}