// Finding single missing element in an array of Natural No. Starting from n

#include <iostream>
using namespace std;

class Array
{
private:
    int A[8] = {6, 7, 9, 10, 11, 12, 13, 14};
    int size = 8;
    int length = 8;

public:
    void Display();
    void SingleMissingElement();
};

void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::SingleMissingElement() // O(n)
{
    int l = A[0];
    int diff = l - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            printf("The Missing Array Element Is: %d", diff + i);
            break;
        }
    }
}

int main()
{
    Array arr;

    arr.Display();
    arr.SingleMissingElement();

    return 0;
}