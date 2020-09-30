#include <iostream>
using namespace std;

class Array
{
private:
    int *A;     // Pointer to the array
    int size;   // Size of array
    int length; // No. of elements in array

public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    void create()
    {
        // https://www.youtube.com/watch?v=dSsukh8EdWk // For flush
        cout << "Enter number of elements: " << flush; // To flush out the new line character from input string buffer
        // cin.ignore(); // Alternate to flush
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }

    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
    }

    ~Array()
    {
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main()
{
    Array arr(10); // Initialized array of size 10
    arr.create();
    arr.display();

    return 0;
}