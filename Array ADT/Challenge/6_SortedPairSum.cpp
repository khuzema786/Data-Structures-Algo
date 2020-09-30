// Finding a Pair of Elements with sum K in Sorted Array

#include <iostream>
using namespace std;

class Array
{
private:
    int A[8] = {1, 3, 4, 5, 6, 8, 10, 12};
    int size = 8;
    int length = 8;

    int Max();

public:
    void Display();
    void SumPair(int k);
    void HashSumPair(int k);
};

int Array::Max() // To get the Maximum value from the array -> O(n)
{
    int max = A[0];
    int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::SumPair(int k) // To compare elements from opposite sides and check if their sum matches the required k -> O(n)
{
    int i = 0, j = length - 1;
    while (i < j) // The moment i==j, stop the loop since we cant add same element
    {
        if (A[i] + A[j] == k)
        {
            printf("\n%d + %d = %d\n", A[i], A[j], k);
            i++, j--;
        }
        else if (A[i] + A[j] > k) // If sum of 2 elements is greater than k, means right hand side element is greater, so decrement j
        {
            j--;
        }
        else
            i++;
    }

    // This can also be represented using for loop which may confuse the reader

    // for (i = 0, j = length - 1; i < j;) // The moment i==j, stop the loop since we cant add same element
    // {
    //     if (A[i] + A[j] == k)
    //     {
    //         printf("\n%d + %d = %d\n", A[i], A[j], k);
    //         i++, j--;
    //     }
    //     else if (A[i] + A[j] > k) // If sum of 2 elements is greater than k, means right hand side element is greater, so decrement j
    //     {
    //         j--;
    //     }
    //     else
    //         i++;
    // }
}

int main()
{
    Array arr;

    arr.Display();
    arr.SumPair(14);

    return 0;
}