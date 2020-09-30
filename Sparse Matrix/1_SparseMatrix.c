// Sparse Matrix using C

#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;               // total no. of rows
    int n;               // total no. of columns
    int num;             // total no. of non-zero elements
    struct Element *ele; // Array of non-zero elements along with their position in matrix
};

void create(struct Sparse *s)
{
    int i;
    printf("Enter Dimensions\n");
    scanf("%d%d", &s->m, &s->n); // Total no. of rows and columns in matrix

    printf("Number of non-zero\n");
    scanf("%d", &s->num); // total no. of non-zero elements

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element)); // Array of non zero elements struct

    printf("Enter non-zero Elements\n");
    for (i = 0; i < s->num; i++)
    {
        printf("\nEnter i, j, x for %dst non-zero element.\n", i + 1);
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
        s->ele[i].i -= 1; // subtract 1 because array indexing starts from 0 and matrix index starts from 1
        s->ele[i].j -= 1;
    }
}

void display(struct Sparse s)
{
    int i, j, k = 0;

    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j) // For a non zero element to encounter at the position, print it
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    if (s1->n != s2->n && s1->m != s2->m) // Check whether if Rows and column of both matrix are equal, then only it may be added
        return NULL;

    sum = (struct Sparse *)malloc(sizeof(struct Sparse)); // Sum is the 3rd sparse matrix that is created on adding s1 & s2
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    sum->ele = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num) // Till both s1 and s2 contain elements, loop will execute
    {
        if (s1->ele[i].i < s2->ele[j].i) // If Row count of first matrix is smaller than 2nd, copy that 1st element in sum
            sum->ele[k++] = s1->ele[i++];

        else if (s1->ele[i].i > s2->ele[j].i) // If Row count of first matrix is greater than 2nd, copy 2nd element in sum
            sum->ele[k++] = s2->ele[j++];
        else // If both has equal row count
        {
            if (s1->ele[i].j < s2->ele[j].j) // If Column count of first matrix is smaller than 2nd, copy that 1st element in sum
                sum->ele[k++] = s1->ele[i++];

            else if (s1->ele[i].j > s2->ele[j].j) // If Column count of first matrix is greater than 2nd, copy 2nd element in sum
                sum->ele[k++] = s2->ele[j++];
            else // If both has equal column count, copy sum of element 1 and 2 in matrix
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
    }

    // If either s1 or s2 has lesser number of non zero elements, then the loop exits and the remaining elements left in sparse matrix isprinted as it is to sum matrix
    for (; i < s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++)
        sum->ele[k++] = s2->ele[j];

    return sum;
}

int main()
{
    struct Sparse s1, s2, *s3;

    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    printf("First Matrix\n");
    display(s1);
    printf("Second Matrix\n");
    display(s2);
    printf("Sum Matrix\n");
    display(*s3); // Dereferencing the pointer to pass as call by value to display() func.

    return 0;
}