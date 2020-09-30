// Diagonal Matrix - Note: Matrix index starts from 1 and not 0

#include <stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    if (i == j)          // Diagonal Element
        m->A[i - 1] = x; // i-1 because matrix index starts from 1 but array index start from zero
}

int Get(struct Matrix m, int i, int j)
{
    if (i == j)
        return m.A[i - 1];
    else
        return 0;
}

void Display(struct Matrix m) // O(n^2)
{
    int i, j;
    for (i = 0; i < m.n; i++)
    {
        for (j = 0; j < m.n; j++)
        {
            if (i == j) // Diagonal Elements
                printf("%d ", m.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;
    m.n = 4; // size

    Set(&m, 1, 1, 5);  // 1,1 Diagonal Element
    Set(&m, 2, 2, 8);  // 2,2 Diagonal Element
    Set(&m, 3, 3, 9);  // 3,3 Diagonal Element
    Set(&m, 4, 4, 12); // 4,4 Diagonal Element

    printf("\n2,2 Diagonal Element -> %d \n\n", Get(m, 2, 2));

    Display(m);
    return 0;
}