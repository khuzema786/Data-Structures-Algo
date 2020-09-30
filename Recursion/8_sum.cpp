// Sum of N natural numbers

#include <stdio.h>

// Using recursion
int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n - 1) + n;
}
// Using for loop iteration - less time complexity, efficient
int Isum(int n)
{
    int s = 0, i;
    for (i = 1; i <= n; i++)
        s = s + i;

    return s;
}
int main()
{
    int r = sum(5);
    printf("recursion: %d ", r);
    int r = Isum(5);
    printf("using for loop: %d", r);
    return 0;
}