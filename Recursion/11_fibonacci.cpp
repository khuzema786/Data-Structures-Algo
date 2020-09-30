// Fibonacci series - 0 1 1 2 3 5 8 13 (Every term is obtained by sum of previous 2 terms)

#include <stdio.h>

// Iterative -> O(n)
int fib(int n)
{
    int t0 = 0, t1 = 1, s = 0, i;

    if (n <= 1)
        return n;

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s;
}

// Excessive Recursive - Since it calls itself multiple times for same parameters -> O(2^n)
int rfib(int n)
{
    if (n <= 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

// To eliminate excessive recursion and avoid calling of same parameters multiple times -> O(n)
int F[10]; // Memorization array for storing the results of same call to avoid excessive calls for same paramaters
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = mfib(n - 2);

        if (F[n - 1] == -1)
            F[n - 1] = mfib(n - 1);

        F[n] = F[n - 2] + F[n - 1];
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    int i;
    for (i = 0; i < 10; i++) // Initializing all elements in the array to -1
        F[i] = -1;

    printf("%d \n", mfib(5));
    return 0;
}