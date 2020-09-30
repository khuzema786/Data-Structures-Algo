// Finding duplicate elements in a sorted array

#include <iostream>
using namespace std;

class Array
{
private:
    int A[9] = {6, 7, 7, 9, 12, 13, 13, 13};
    int size = 8;
    int length = 8;

    int Max();

public:
    void Display();
    void DuplicateElement();
    void CountDuplicateElement();
    void HashCountDuplicate();
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

void Array::DuplicateElement() // Returns the duplicate elements in array by keeping a track of lastDuplicate -> O(n)
{
    int lastDuplicate;

    for (int i = 0; i < length; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate) // To check if an element is duplicate in a sorted array
        {
            printf("\nThe Duplicate Array Element Is: %d\n", A[i]);
            lastDuplicate = A[i];
        }
    }
}

void Array::CountDuplicateElement() // To count the total no. of duplicate elements -> O(n^2)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] == A[i + 1]) // To check if an element is duplicate in a sorted array
        {
            int j = i + 1;
            while (A[j] == A[i] && j < length) // To iterate till the same element is being duplicated
            {
                j++;
            }
            printf("\n%d is appearing for %d times.\n", A[i], j - i); // To get the count of the times a number was duplicated
            // To get i at the j-1 th position which will come on jth position after i++ and will continue to iterate and compare accordingly and smoothly
            i = j - 1;
        }
    }
}

void Array::HashCountDuplicate() // O(n)
{
    int l = 1;
    int h = Max();    // 13
    int H[++h] = {0}; // H[14]

    for (int i = 0; i < length; i++)
    {
        H[A[i]]++; // Increment the index corresponding to the present value of array by 1
    }
    for (int i = l; i < h; i++)
    {
        if (H[i] > 1) // For duplicate elements
            printf("\n%d is appearing for %d times with hashing.\n", i, H[i]);
    }
}

int main()
{
    Array arr;

    arr.Display();
    arr.DuplicateElement();
    arr.CountDuplicateElement();
    arr.HashCountDuplicate();

    return 0;
}