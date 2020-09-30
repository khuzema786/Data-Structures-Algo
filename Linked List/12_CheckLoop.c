// Checking for Loop Linked List

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
int isLoop(struct Node *f)
{
    struct Node *p, *q; // *p takes one step and *q takes 2 steps
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;         // first step
        q = q ? q->next : q; // second step
    } while (p && q && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}
int main()
{
    struct Node *t1, *t2;

    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    t1 = first->next->next;             // 30's address
    t2 = first->next->next->next->next; // 50's address
    t2->next = t1;                      // Forms a loop

    printf("%d\n", isLoop(first));

    return 0;
}