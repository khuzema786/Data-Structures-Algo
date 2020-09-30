// Representation of sparse matrix with LL

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int col;           // column index
    int val;           // non zero value in that column
    struct Node *next; // address to next node
} *first = NULL;

void Display(struct Node *p, struct Node *A[], int m, int n)
{
    for (int i = 0; i < m; i++) // Rows
    {
        p = A[i];
        for (int j = 0; j < n; j++) // Columns
        {
            if (j == p->col)
            {
                printf("%d\t", p->val);
                if (p->next != NULL)
                    p = p->next;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

int main()
{
    int m, n;
    printf("\nEnter Dimensions\n");
    printf("Enter Number Of Rows\t");
    scanf("%d", &m);
    printf("\nEnter Number Of Columns\t");
    scanf("%d", &n);

    struct Node *A[m]; // Array of pointers of size to that of rows in matrix

    int Mat[m][n];
    // Constructing Matrix
    for (int i = 0; i < m; i++) // Rows
    {
        for (int j = 0; j < n; j++) // Columns
        {
            int k;
            printf("\nEnter Mat[%d][%d] Element: ", i, j);
            scanf("%d", &Mat[i][j]);
        }
    }
    // Displaying Matrix
    printf("\nMATRIX\n");
    for (int i = 0; i < m; i++) // Rows
    {
        for (int j = 0; j < n; j++) // Columns
        {
            int k;
            printf("%d\t", Mat[i][j]);
        }
        printf("\n");
    }

    // Create LL
    struct Node *p;
    for (int i = 0; i < m; i++) // Rows
    {
        static int flag = 0;
        for (int j = 0; j < n; j++) // Columns
        {
            if (Mat[i][j] != 0 && flag == 1)
            {
                struct Node *t = (struct Node *)malloc(sizeof(struct Node));
                p->next = t;
                p = t;
                t->col = j;
                t->val = Mat[i][j];
                t->next = NULL;
            }
            if (Mat[i][j] != 0 && flag == 0) // Will just execute once to make A[i] point to first node
            {
                struct Node *t = (struct Node *)malloc(sizeof(struct Node));
                A[i] = t;
                p = t;
                t->col = j;
                t->val = Mat[i][j];
                t->next = NULL;
                flag = 1;
            }
        }
        flag = 0;
    }

    printf("\nSPARSE MATRIX LL\n");
    Display(first, A, 3, 3);
}