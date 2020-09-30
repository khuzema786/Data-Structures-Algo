// Compare of a String

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j;
    char A[] = "pythona";
    char B[] = "pythonb";

    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j]) // If not equal then come out of loop
        {
            break;
        }
    }
    if (A[i] == B[j])
    {
        printf("\nString 1 %s is equal to string 2 %s", A, B);
    }
    if (A[i] > B[j])
    {
        printf("\nString 1 %s is greater %d", A, A[i]);
    }
    if (A[i] < B[j])
    {
        printf("\nString 2 %s is greater %d\n", B, B[j]);
    }

    return 0;
}