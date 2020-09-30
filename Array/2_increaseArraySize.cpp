// Array Size Increasing In Heap

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, *q;
    int i;
    p = (int *)malloc(5 * sizeof(int)); // P of size 5
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    q = (int *)malloc(10 * sizeof(int)); // q of size 10

    for (i = 0; i < 5; i++)
        q[i] = p[i]; // Copying contents of p to q

    free(p);  // deleting contents of p
    p = q;    // p is pointing to array pointed by q
    q = NULL; // q is set to null pointer, so that only p is made a pointer to that array of size 10

    for (i = 0; i < 5; i++)
        printf("%d \n", p[i]);

    return 0;
}