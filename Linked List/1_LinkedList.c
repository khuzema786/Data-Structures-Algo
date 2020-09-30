// Display a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL; // *first is the head pointer to the node set to null initially which can be accessed globally

void create(int A[], int n)
{
    int i;                                              // To iterate over the array
    struct Node *t, *last;                              // *t is temp pointer to iterate over nodes, *last points to the last node to add a new node
    first = (struct Node *)malloc(sizeof(struct Node)); // Dynamically allocate node
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) // Iterate from A[1] to A[7]
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL) // or while(p)
    {
        printf(" %d ->", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next);
        printf(" %d -> ", p->data);
    }
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);

    Display(first); // Prints from A[0] to A[7]
    printf("\n");
    RDisplay(first); // Prints from A[7] to A[0]

    return 0;
}