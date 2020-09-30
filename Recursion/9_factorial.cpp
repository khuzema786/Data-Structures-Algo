// Factorial of N

#include <stdio.h>

// Recursion
int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

// Using for loop
int Ifact(int n)
{
    int f = 1, i;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}
int main()
{
    int r = fact(5);
    printf("recursion: %d ", r);
    int r = Ifact(5);
    printf("For loop iterations: %d ", r);
    return 0;
}