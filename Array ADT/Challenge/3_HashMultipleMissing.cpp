// Finding multiple missing element in an array of Natural No. Starting from 1

#include <iostream>
using namespace std;

class Array
{
private:
    int A[6] = {6, 7, 9, 12, 13, 14};
    int size = 6;
    int length = 6;

    int Max();

public:
    void Display();
    void HashMultiMissingElement();
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

void Array::HashMultiMissingElement() // O(n)
{
    int l = 1;
    int h = Max();    // 14
    int H[++h] = {0}; // H[15]
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++; // Increment the index corresponding to the present value of array by 1
    }
    for (int i = l; i < h - 1; i++) // h-1 because the last element need not be considered
    {
        if (H[i] == 0)
            printf("\nThe Missing Element: %d\n", i);
    }
}

int main()
{
    Array arr;

    arr.Display();
    arr.HashMultiMissingElement();

    return 0;
}