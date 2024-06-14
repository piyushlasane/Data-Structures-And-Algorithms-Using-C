#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f, r, size;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r==q->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r==q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int item)
{
    if (isFull(q))
    {
        printf("**Queue is Full**\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=item;
        printf("%d is inserted in queue\n", item);
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("**Queue is Empty**\n");
    }
    else
    {
        int a=-1;
        q->f++;
        printf("%d is deleted from queue\n", q->arr[q->f]);
        return q->arr[q->f];
    }
}

void traversal(struct queue *q)
{
    for (int i = q->f+1; i < q->r; i++)
    {
        printf("%d ", q->arr[q->f]);
    }   
}

int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 4;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    printf("\n");
    printf("isFull: %d\n", isFull(q));
    printf("isEmpty: %d\n", isEmpty(q));
    printf("\n");
    enqueue(q,18);
    enqueue(q,24);
    enqueue(q,48);
    enqueue(q,32);
    printf("\n");
    printf("isFull: %d\n", isFull(q));
    printf("isEmpty: %d\n", isEmpty(q));
    printf("\n");
    dequeue(q);
    dequeue(q);
    printf("\n");
    printf("isFull: %d\n", isFull(q));
    printf("isEmpty: %d\n", isEmpty(q));
    printf("\n");
    traversal(q);
    return 0;
}