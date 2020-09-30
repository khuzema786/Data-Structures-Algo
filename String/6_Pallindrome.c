// Pallindrome

#include <stdio.h>
#include <stdlib.h>
int main()
{
    // Method 1
    int i, j;
    char S[] = "ABBA";

    for (i = 0; S[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
    }
    for (j = i - 1, i = 0; i < j; i++, j--)
    {
        if (S[i] != S[j])
        {
            printf("\n%s is not a pallindrome", S);
            break;
        }
    }
    if (S[i] == S[j])
    {
        printf("\n%s is a pallindrome", S);
    }

    // Method 2
    char A[] = "madam";
    char B[6];
    // int i, j;
    for (i = 0; A[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
    }
    for (j = i - 1, i = 0; j >= 0; i++, j--)
    {
        B[j] = A[i];
    }
    // Compare
    for (i = 0, j = 0; A[i] != '\0' && B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j]) // If not equal then come out of loop
        {
            printf("\n%s is not a pallindrome to %s", A, B);
            break;
        }
    }
    B[j] = '\0'; // Adding null character to the end of string

    if (A[i] == B[j])
    {
        printf("\n%s is pallindrome to %s", A, B);
    }

    return 0;
}