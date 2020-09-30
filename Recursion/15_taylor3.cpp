// Taylor Serie Iterative

#include <stdio.h>
double e(int x, int n)
{
    double s = 1;

    while (n > 0)
    {
        s = 1 + (x / n) * s;
        n--;
    }
    return s;
}
int main()
{
    printf("%lf \n", e(2, 10));
    return 0;
}