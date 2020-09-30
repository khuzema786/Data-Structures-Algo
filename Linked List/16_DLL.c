// Reverse a Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
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
    printf("\n");
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
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

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p)) // Error
        return;

    t = (struct Node *)malloc(sizeof(struct Node)); // temp pointer
    t->data = x;

    if (index == 0) // Add at the beginning
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (t->next) // To check if t->next is not equal to null, then only it would make sence to point it's prev to *t
            t->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int position) // O(n)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (position < 1 || position > count(p)) // Error
        return -1;

    if (position == 1) // Deletiong Node at first 0th index -> O(1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);   // deleting the node
        if (first) // If more than 1 Node exist in DLL
            first->prev = NULL;
        return x;
    }
    else // O(n)
    {
        for (i = 0; i < position - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next) // If p->next != NULL
            p->next->prev = p->prev;
        x = p->data;
        free(p); // deleting the node
        return x;
    }
}

// By swapping the links -> O(n)
void Reverse(struct Node *p)
{
    struct Node *t;

    while (p != NULL)
    {
        // Swapping the links
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;                      // For movement of p
        if (p != NULL && p->next == NULL) // p!=NULL to avoid error when p==null and it has to check for p->next which throws an error
            first = p;
    }
}

int main()
{

    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    Insert(first, 2, 30); // Inserting 30 at 2nd index
    Display(first);
    printf("\n");
    Reverse(first);
    Display(first);

    return 0;
}