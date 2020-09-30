// Anagram, Presence of same letters in both the strng at same or random position

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int H[26] = {0}; // For all small alphabets hashing
    int i;

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++; // Increment index corresponding to the letter in A[i] by 1
    }

    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--; // Decrement index corresponding to the letter in B[i] by 1
        if (H[B[i] - 97] < 0)
        {
            printf("\nString is not anagram.\n");
            break;
        }
    }
    if (B[i] == '\0')
        printf("\nString is anagram.\n");

    return 0;
}