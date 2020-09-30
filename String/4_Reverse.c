// Reverse of a String

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    char S[] = "python";
    char temp;

    for (i = 0; S[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
    }
    for (int j = i - 1, i = 0; i < j; i++, j--)
    {
        //Swap opposite elements
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }

    printf("\nReversed String:\n%s\n", S);

    return 0;
}