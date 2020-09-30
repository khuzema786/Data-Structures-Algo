// Polynomial Representation

#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    int i;
    printf("\nNumber of terms?\n");
    scanf("%d", &p->n);
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    for (i = 0; i < p->n; i++)
    {
        printf("Enter %dst term\n", i + 1);
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
    }
}

void display(struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
    printf("\n");
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    int i, j, k;
    i = j = k = 0;
    struct Poly *sum;

    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->n = k;

    sum->terms = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    while (i < p1->n && j < p2->n) // Check whether if both p1 and p2 contain elements
    {
        if (p1->terms[i].exp > p2->terms[j].exp) // If p1's exponent of first matrix is greater than 2nd, copy that 1st element in sum
            sum->terms[k++] = p1->terms[i++];

        else if (p1->terms[i].exp < p2->terms[j].exp) // If p1's exponent of first matrix is smaller than 2nd, copy 2nd element in sum
            sum->terms[k++] = p2->terms[j++];
        else // If both has equal exponent count, add their coefficients
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    // If either s1 or s2 has lesser number of non zero elements, then the loop exits and the remaining elements left in sparse matrix isprinted as it is to sum matrix
    for (; i < p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for (; j < p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    return sum;
}

int main()
{
    struct Poly p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1, &p2);

    printf("\n");
    display(p1);
    printf("\n");
    display(p2);
    printf("\n");
    display(*p3);

    return 0;
}