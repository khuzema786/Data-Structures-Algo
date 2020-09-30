// Reversing an Array

#include <iostream>  // for printf and scanf functions
//#include <stdlib.h> // for malloc function
using namespace std;

// Use Structure only to store some data that needs to be nicely organised,
// In c++ there is not much difference between structure and a class, hence
// In C++ use classes, Structure require mode space
// In this solution I have decresed the space complexity only a few bits though
/*struct Array
{
    int A[10];
    int size;
    int length;
};
*/
void Display(int *arr,int length)
{
    cout<<"\nElements are\n";
    for (int i = 0; i < length; i++)
        cout<<arr[i]<<" ";
}

void LeftShift(int *arr,int length) // Reverse by copying into a new array from backwards -> O(n^2)
{
    for (int i = 0; i <length - 1; i++)
        arr[i] = arr[i + 1];
    arr[length - 1] = 0;
}

void LeftRotate(int *arr,int length) // Reverse by copying into a new array from backwards -> O(n^2)
{
    int j;
    j = arr[0];
    for (int i = 0; i < length - 1; i++)
        arr[i] = arr[i + 1];
    arr[length-1] = j; // Along with left shift, first element of array is added as last element in array
}

void RightShift(int arr[],int length) // Reverse by copying into a new array from backwards -> O(n^2)
{
    for (int i = length - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = 0;
}

void RightRotate(int arr[],int length) // Reverse by copying into a new array from backwards -> O(n^2)
{
    int j;
    j = arr[length - 1];
    for (int i = length - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = j; // Along with right shift, last element of array is added as first element in array
}

int main()
{
    int arr1[] = {2, 3, 9, 16, 18, 21, 28, 32, 35};
    int num;
    int length = (int)(sizeof(arr1)/sizeof(int));
    cout<<"\n Enter a choice: \n 1. Left Shift \n 2. Right Shift \n 3. Left Rotate \n 4. Right Rotate \n 0. Exit \n";
    cin>>num;
    switch (num)
    {
    case 1:
        LeftShift(arr1,length);
        Display(arr1,length);
        break;
    case 2:
        RightShift(arr1,length);
        Display(arr1,length);
        break;
    case 3:
        LeftRotate(arr1,length);
        Display(arr1,length);
        break;
    case 4:
        RightRotate(arr1,length);
        Display(arr1,length);
        break;

    default:
        cout<<"Enter a valid choice";
        break;
    }
    return 0;
}