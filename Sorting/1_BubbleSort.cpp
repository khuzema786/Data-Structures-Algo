// Bubble Sort -> O(n^2) -> Adaptive -> Stable -> K Passes Gives K largest elements -> Not Suitable With LL

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

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n)
{
    int flag = 0;
    for (int i = 0; i < n - 1; i++) // Pass
    {
        for (int j = 0; j < n - 1 - i; j++) // Comparisons
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) // For Adaptive Bubble sort, that is the function breaks as and when no comparisons are done in a pass.
        {
            return;
        }
    }
}

int main()
{

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(A[0]);
    Print(A, n, "\t\tA");

    BubbleSort(A, n);
    Print(A, n, " Sorted A");

    return 0;
}