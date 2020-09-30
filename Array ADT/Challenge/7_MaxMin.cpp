// Finding Max & Min in a single scan

// To find pair of elements that sums up to the passed number

#include <iostream>
using namespace std;

class Array
{
private:
    int A[8] = {8, 7, 6, 5, 4, 3, 2, 1};        // Descending order takes n-1 comparisions -> Best Comparison Case Scenario, So Descending sorted array is best
    int B[8] = {9, 10, 11, 12, 13, 14, 15, 16}; // Ascending order takes 2(n-1) comparisions -> Worst Comparison Case Scenario
    int size = 8;
    int length = 8;

public:
    void Display();
    void MaxMinDesc();
    void MaxMinAsc();
};

void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::MaxMinDesc() // O(n)
{
    int min = A[0], max = A[0];

    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
        else if (A[i] > max)
            max = A[i];
    }
    printf("\nDescending\n%d is minimum.\n%d is maximum.\n", min, max);
}

void Array::MaxMinAsc() // O(n)
{
    int min = B[0], max = B[0];

    for (int i = 1; i < length; i++)
    {
        if (B[i] < min)
            min = B[i];
        else if (B[i] > max)
            max = B[i];
    }
    printf("\nAscending\n%d is minimum.\n%d is maximum.\n", min, max);
}

int main()
{
    Array arr;

    arr.Display();
    arr.MaxMinDesc();
    arr.MaxMinAsc();

    return 0;
}