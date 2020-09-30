// Finding multiple missing element in an array of Natural No. Starting from n

#include <iostream>
using namespace std;

class Array
{
private:
    int A[6] = {6, 7, 9, 12, 13, 14};
    int size = 6;
    int length = 6;

public:
    void Display();
    void MultiMissingElement();
};

void Array::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::MultiMissingElement() // O(n) -> Not O(n^2) since time taken by inner while loop to print multiple missing elements is negligible
{
    int l = A[0];
    int diff = l - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff) // To check if an element is missing
        {
            while (diff < A[i] - i) // In case of multiple missing element
            {
                printf("The Missing Array Element Is: %d", diff + i);
                diff++;
            }
        }
    }
}

int main()
{
    Array arr;

    arr.Display();
    arr.MultiMissingElement();

    return 0;
}