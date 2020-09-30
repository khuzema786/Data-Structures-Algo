// Finding single missing element in an array of Natural No. Starting from 1

#include <iostream>
using namespace std;

class Array
{
private:
    int A[8] = {1, 2, 3, 4, 5, 6, 7, 9};
    int size = 8;
    int length = 8;

public:
    void Display();
    int SingleMissingElement();
};

void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

int Array::SingleMissingElement() // O(n)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += A[i];
    }
    int n = A[length - 1];
    int s = n * (n + 1) / 2; // Sum of N natural numbers
    return s - sum;          // s-sum gives the missing number
}

int main()
{
    Array arr;

    arr.Display();
    printf("\nThe missing element is: %d", arr.SingleMissingElement());

    return 0;
}