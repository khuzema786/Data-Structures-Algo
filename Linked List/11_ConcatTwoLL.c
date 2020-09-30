// Merge two Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Create LL using *first as head pointer
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Create LL using *second as head pointer
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Concat(struct Node *p) // O(n)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = second;
    second = NULL; // Since second pointer is not needed after concatenation of two LL
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    // Check for the smallest among first and second node so that you can point *third & *last on that node
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data) // If p < q, last to point on p
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    // For remaining LL in either of LL, make last point to that LL
    if (p)
        last->next = p;
    if (q)
        last->next = q;

    // Null the pointers
    first = NULL;
    second = NULL;
}
int main()
{

    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};

    create(A, 5);
    create2(B, 5);

    // Concat(first);
    // Display(first);

    Merge(first, second); // Merges two LL in sorted order
    Display(third);

    return 0;
}