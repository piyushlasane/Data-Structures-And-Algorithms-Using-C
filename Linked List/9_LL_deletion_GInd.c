#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *Listdeletion_givenIndex(struct node *given)
{   
    struct node *p = given->next;
    given->next = p->next;
    free(p);
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
    struct node *fifth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fouth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fouth;

    fouth->data = 4;
    fouth->next = fifth;

    fifth->data = 5;
    fifth->next = NULL;
    traversal(head);
    Listdeletion_givenIndex(head);
    traversal(head);
    return 0;
}