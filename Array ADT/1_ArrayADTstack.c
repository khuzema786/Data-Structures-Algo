#include <stdio.h>

struct Array
{
    int A[20];  // array of size 20
    int size;   // Size of array
    int length; // No. of elements in array
};

void display(struct Array arr) {
     for (int i = 0; i < arr.length; i++)
        {
            printf("%d ", arr.A[i]);
        }
}

int main()
{
    struct Array arr = {{1,2,3,4,5},20,5}; // A,size,length

    display(arr);

    return 0;
}