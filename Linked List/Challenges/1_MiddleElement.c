// Middle Node Of LL

#include <stdio.h>  // For printf, scanf functions
#include <stdlib.h> // For Malloc
#include <math.h>   // For ceil

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

double Length(struct Node *p) // Time->O(n), Space->O(1)
{
    double l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// Method One is to find mid Node on doing length/2 -> O(n^2)
int Middle1(struct Node *p)
{
    int midNode = ceil(Length(p) / 2);
    for (int i = 0; i < midNode - 1; i++)
    {
        p = p->next;
    }
    return p->data;
}

// Method Two is by taking 2 pointers -> O(n)
int Middle2(struct Node *p)
{
    struct Node *q = first;

    // *p moves one steps, *q moves two steps
    while (q)
    {
        q = q->next; // 1st step for q
        if (q)
            p = p->next; // 1st step for p
        if (q)
            q = q->next; // 2nd step for q
    }
    return p->data;
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32};
    create(A, 7);

    Display(first); // Prints from A[0] to A[7]
    printf("\nMiddle Node Data Method 1: %d \n", Middle1(first));

    printf("Middle Node Data Method 2: %d \n", Middle2(first));

    return 0;
}