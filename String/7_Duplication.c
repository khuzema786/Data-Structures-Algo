// Duplication

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "npnpnpnpn";

    int length = (sizeof(A) / sizeof(char)) - 1;

    for (int i = 0; i < length - 1; i++) // Entire aray except the last element
    {
        int count = 1;
        if (A[i] != -1) // To avoid testing of duplicate elements again
        {
            for (int j = i + 1; j < length; j++) // Entire aray
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1; // Elements that are repeated are marked as -1
                }
            }
        }
        if (count > 1)
            printf("\n%c is appearing for %d times.\n", A[i], count); // To get the count of the times a number was duplicated
    }

    // Method 2
    char B[] = "madam";
    int H[26] = {0}; // For all small alphabets hashing
    int i;

    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]++;
    }

    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
            printf("\n%c is repeated %d time via hashing method.\n", i + 97, H[i]);
    }
    return 0;
}