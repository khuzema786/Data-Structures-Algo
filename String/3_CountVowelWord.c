// Counting Words and Vowels in a String

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int ccount = 0; // Consonants
    int vcount = 0; // Vowels
    // char A[] = "How are you";
    // char *S = A;
    char S[] = "How are     you";

    // FOR COUNTING VOWELS AND CONSONANTS
    for (i = 0; S[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
        if (S[i] == 'a' || S[i] == 'A' || S[i] == 'e' || S[i] == 'E' || S[i] == 'i' ||
            S[i] == 'I' || S[i] == 'o' || S[i] == 'O' || S[i] == 'u' || S[i] == 'U')
        {
            vcount++; // If vowels
        }
        else if ((S[i] >= 65 && S[i] <= 90) || (S[i] >= 97 && S[i] <= 122))
        {
            ccount++;
        }
    }
    printf("\n%s\nHas %d Vowels.\nHas %d Consonants.\n", S, vcount, ccount);

    // FOR COUNTING WORDS
    int words = 0;
    for (i = 0; S[i] != '\0'; i++) // Iterate till the null character is encountered -> O(n)
    {
        if (S[i] == ' ' && S[i - 1] != ' ') // S[i - 1] != ' ' to make sure that it counts more than one cosecutive space as one single space
        {
            words++; // count no. of spaces
        }
    }
    printf("\n%s\nHas %d Words.\n", S, words + 1);

    return 0;
}