// Static vs Dynamic Arrays

#include <stdio.h>
#include <stdlib.h>
int main()
{
    // int n;
    // cin >> n; // C++ Runtime array memory allocation which is not possible in C
    // int A[n];

    int A[5] = {2, 4, 6, 8, 10}; // Size of array to be decided during compile time
    int *p;
    int i;

    // p = new int[5]; // C++
    p = (int *)malloc(5 * sizeof(int)); // C
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    for (i = 0; i < 5; i++)
        printf("%d ", A[i]);

    printf("\n");
    for (i = 0; i < 5; i++)
        printf("%d ", p[i]); // pointer acts as a name for array

    // delete[] p; // C++
    free(p); // C

    return 0;
}