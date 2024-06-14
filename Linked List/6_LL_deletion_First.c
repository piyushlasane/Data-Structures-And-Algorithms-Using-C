#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *ListDeletion_first(struct node *head)
{
    struct node *p = head;
    head = head->next;
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
    traversal(head);
    head = ListDeletion_first(head);
    traversal(head);
    return 0;
}