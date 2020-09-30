// Reverse a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
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
int count(struct Node *p) // Time->O(n), Space->O(1)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

// Reverse by elements -> O(n^2)
void Reverse1(struct Node *p)
{
    int *A, i = 0;

    A = (int *)malloc(sizeof(int) * count(p));

    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = A[i];
        p = p->next;
        i--;
    }
}
// Reverse by sliding pointers -> O(n)
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q; // to make the last node pointed by q as first node in reverse LL
}
// Reverse links by recursion -> O(n^2)
void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q; // Returns this after recursions to reverse the links
    }
    else
        first = q; // to make the last node pointed by q as first node in reverse LL, before reversing the links
}
int main()
{

    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    Reverse1(first);
    Display(first);

    return 0;
}