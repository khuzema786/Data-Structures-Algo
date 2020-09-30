// Finding duplicate elements in an unsorted array

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

void Array::CountDuplicateElement() // To count the total no. of duplicate elements -> O(n^2)
{
    for (int i = 0; i < length - 1; i++) // Entire aray except the last element
    {
        int count = 1;
        if (A[i] != -1) // To avoid testing of duplicate elements again
        {
            for (int j = i + 1; j < length; j++) // Entire aray
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1; // Elements that are repeated are marked as -1
                }
            }
        }
        if (count > 1)
            printf("\n%d is appearing for %d times.\n", A[i], count); // To get the count of the times a number was duplicated
    }
}

void Array::HashCountDuplicate() // O(n)
{
    int l = 1;
    int h = Max();            // 13
    int *H = new int[++h]{0}; // H[14]

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
    arr.HashCountDuplicate();
    arr.CountDuplicateElement();

    return 0;
}