// Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
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

int Delete(struct Node *p, int position) // O(n)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (position < 1 || position > count(p))
        return -1;

    if (position == 1) // Deletiong Node at first 0th index
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q); // deleting the node
        return x;
    }
    else
    {
        for (i = 0; i < position - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p); // deleting the node
        return x;
    }
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    printf("%d\n", Delete(first, 2)); // 2nd position means 2nd position, 1st index
    Display(first);

    return 0;
}