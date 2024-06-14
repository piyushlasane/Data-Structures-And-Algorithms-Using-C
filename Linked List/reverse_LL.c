#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node* reverseLL(struct node* head)
{
    struct node *prev = NULL;
    struct node *nxt = NULL;
    struct node *curr = head;

    while (curr!=NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int main()
{
    // Allocates mamory in Linked list in heap
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fouth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    // liniking first and second
    first->data = 1;
    first->next = second;

    // liniking second and third
    second->data = 2;
    second->next = third;

    // liniking third and fouth
    third->data = 3;
    third->next = fouth;

    // liniking fouth and fifth
    fouth->data = 4;
    fouth->next = fifth;
    
    // liniking fifth and end
    fifth->data = 5;
    fifth->next = NULL;
    printf("\nBefore Reversal :  ");
    traversal(first);
    first=reverseLL(first);
    printf("\n\nAfter Reversal :   ");
    traversal(first);
    printf("\n\n");
    return 0;
}