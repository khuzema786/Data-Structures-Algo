// Insertion Sort -> O(n^2) -> Adaptive -> Stable -> No K Passes -> Suitable With LL

#include <iostream>

using namespace std;

template <class T>
void Print(T &vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1; // To make comparison
        int x = A[i];  // To make comparison
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j]; // Right shift larger elements
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{

    int A[] = {19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    Print(A, sizeof(A) / sizeof(A[0]), "       A");

    InsertionSort(A, sizeof(A) / sizeof(A[0]));
    Print(A, sizeof(A) / sizeof(A[0]), "Sorted A");

    return 0;
}