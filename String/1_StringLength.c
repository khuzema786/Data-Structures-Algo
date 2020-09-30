// Finding the length of string

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    // char s[] = "Welcome"; // If we declare as array, it makes string mutable
    char *s = "Welcome";           // If we declare as pointer, it makes string immutable
    for (i = 0; s[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
    }
    printf("Length of string is %d", i);

    return 0;
}