// To find pair of elements that sums up to the passed number

#include <iostream>
using namespace std;

class Array
{
private:
    int A[8] = {6, 9, 7, 12, 7, 13, 13, 2};
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

void Array::SumPair(int k) // To find pair of elements that sums up to the passed number -> O(n^2)
{
    for (int i = 0; i < length - 1; i++) // Entire aray except the last element
    {
        for (int j = i + 1; j < length; j++) // Entire aray
        {
            if (A[i] + A[j] == k)
            {
                printf("\n%d + %d = %d\n", A[i], A[j], k);
            }
        }
    }
}

void Array::HashSumPair(int k) // O(n)
{
    int l = 1;
    int h = Max();            // 13
    int *H = new int[++h]{0}; // H[14]

    for (int i = 0; i < length; i++)
    {
        if (H[k - A[i]] != 0) // Suppose if k=10 & A[i]=6 so we need to look if H[10-6]->H[4]>0, if yes then that means a pair is formed
            printf("\nHashing: %d + %d = %d\n", A[i], k - A[i], k);

        H[A[i]]++; // Increment the index corresponding to the present value of array by 1
    }
}

int main()
{
    Array arr;

    arr.Display();
    arr.SumPair(14);
    arr.HashSumPair(14);

    return 0;
}