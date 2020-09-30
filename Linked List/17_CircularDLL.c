// Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} * Head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->prev = Head;
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next; // CLL
        t->prev = last;
        last->next = t;
        last = t;
    }
    Head->prev = last;
}

void Display(struct Node *h)
{
    do // while won't work, since very Head time h==Head and we dont want to include that
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}

int Length(struct Node *p) // Count the number of nodes
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != Head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Length(p)) // Error
        return;

    if (index == 0) // To insert at 0th index
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
            Head->prev = Head;
        }
        else
        {
            while (p->next != Head) // To reach the last node
                p = p->next;
            p->next = t;
            t->prev = p;
            t->next = Head;
            Head->prev = t;
            Head = t; // Head is assigned to the new node pointed by t at 0th index
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        if (t->next != NULL)
            t->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

int Delete(struct Node *p, int index) // O(n)
{
    struct Node *q;
    int i, x;

    if (index < 0 || index > Length(Head))
        return -1;
    if (index == 1) // Deleting First Node
    {
        while (p->next != Head) // traverse till p reaches last node
            p = p->next;
        x = Head->data;
        if (Head == p) // If CLL has just one node
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            Head->next = p;
            free(Head);
            Head = p->next; // Make head point to p->next that was actually head->next
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next; // *q is leading p and it is the pointer to the node that is to be deleted
        p->next = q->next;
        p->next->prev = p;
        x = q->data;
        free(q); // Deallocate memory for that node
    }
    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Insert(Head, 5, 7); // Insert 7 at 5th index
    Delete(Head, 1);    // Delete from 1st position (0th index)
    Delete(Head, 2);    // Delete from 2nd position (1st index)
    Display(Head);
    return 0;
}