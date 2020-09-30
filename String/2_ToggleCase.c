// Toggle the case of string from upper to lower and vice versa

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    // char A[] = "WELCOME";
    // char *S = A;
    char S[] = "WeLcoME";
    for (i = 0; S[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
        if (S[i] < 97)        // Uppercase
            S[i] = S[i] + 32; // Change to lower case
        else                  // Lower case
            S[i] = S[i] - 32; // Change to Upper case
    }
    printf("%s", S);

    return 0;
}