// Change the case of string

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    // char A[] = "WELCOME";
    // char *S = A; // Makes sring immutable
    char S[] = "WELCOME";          // Makes string mutable
    for (i = 0; S[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
        S[i] = S[i] + 32; // Since A ascii value is 65... & a ascii value is 97... So, 97-65
    }
    printf("%s", S);

    return 0;
}