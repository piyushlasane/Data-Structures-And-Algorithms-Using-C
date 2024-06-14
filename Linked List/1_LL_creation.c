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
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    // Allocates mamory in Linked list in heap
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fouth = (struct node *)malloc(sizeof(struct node));

    // liniking first and second
    first->data = 9;
    first->next = second;

    // liniking second and third
    second->data = 12;
    second->next = third;

    // liniking third and fouth
    third->data = 20;
    third->next = fouth;

    // liniking fouth and end
    fouth->data = 66;
    fouth->next = NULL;
    traversal(first);
    return 0;
}