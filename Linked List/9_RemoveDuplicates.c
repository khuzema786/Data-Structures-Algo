// Remove Duplicates from Linked List

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

void RemoveDuplicate(struct Node *p) // O(n)
{
    struct Node *q = p->next; // q is a pointer to the node leading *p

    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q); // Remove the duplicate node pointed by *q
            q = p->next;
        }
    }
}

int main()
{

    int A[] = {10, 20, 20, 40, 50, 50, 50, 60};
    create(A, 8);

    RemoveDuplicate(first);
    Display(first);

    return 0;
}