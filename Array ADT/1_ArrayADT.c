#include <stdio.h>

struct Array
{
    int *A;     // Pointer to the array
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
    struct Array arr;
    printf("Enter size of an array");
    scanf("%d", &arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int)); // Dynamic Sized Array
    arr.length=0;
    
    printf("Enter number of numbers inside the array");
    scanf("%d", &arr.length);
    fflush(stdin); // To flush out the new line character from input stream

    // Fill Array
    for (int i = 0; i < arr.length; i++)
        {
            printf("Array element: %d = ", i); 
            fflush(stdin);
            scanf("%d", &arr.A[i]);
        }

    display(arr);
    
    return 0;
}