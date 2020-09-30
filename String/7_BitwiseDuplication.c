// Bitwise Duplication

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[] = "madam";
    long H = 0, X = 0; // long is 32 bits and alphabets are 25 so nearest is 32 bits

    for (int i = 0; A[i] != '\0'; i++) // To Merge bit corresponding to the letter by performing Bitwise OR -> O(n)
    {
        X = 1;
        X = X << A[i] - 97; // Performs left shift of 1 by A[i] - 97 times -> Since char to long

        if ((X & H) > 0) // To check if H[i] is repeated H.X is done and if both bits are more than 1 then its identified as duplicate
        {
            printf("\n%c is duplicate.\n", A[i]);
        }
        else // Upon first occurence of a letter we need to set H[i] to 1 so we do X OR H (X+H)
        {
            H = X | H;
        }
    }

    return 0;
}