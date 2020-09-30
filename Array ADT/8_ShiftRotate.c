// Reversing an Array

#include <stdio.h>  // for printf and scanf functions
#include <stdlib.h> // for malloc function

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Reset(struct Array *arr)
{
    int i;
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};
    for (i = 0; i <= arr1.length - 1; i++)
        arr->A[i] = arr1.A[i];
    arr->length = arr1.length;
    arr->size = arr1.size;
}

void LeftShift(struct Array *arr) // O(n)
{
    int i;
    for (i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
}

void LeftRotate(struct Array *arr) // O(n)
{
    int i, j;
    j = arr->A[0];
    for (i = 0; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i + 1];
    arr->A[arr->size - 1] = j; // Along with left shift, first element of array is added as last element in array
}

void RightShift(struct Array *arr) // O(n)
{
    int i;
    for (i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
}

void RightRotate(struct Array *arr) // O(n)
{
    int i, j;
    j = arr->A[arr->length - 1];
    for (i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i - 1];
    arr->A[0] = j; // Along with right shift, last element of array is added as first element in array
}

int main()
{
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    int num;
    // fflush(stdin); // If a string comes after a number
    while (num != 0)
    {
        printf("\n Enter a choice: \n 1. Left Shift \n 2. Right Shift \n 3. Left Rotate \n 4. Right Rotate \n 0. Exit \n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            LeftShift(&arr1);
            Display(arr1);
            break;
        case 2:
            RightShift(&arr1);
            Display(arr1);
            break;
        case 3:
            LeftRotate(&arr1);
            Display(arr1);
            break;
        case 4:
            RightRotate(&arr1);
            Display(arr1);
            break;
        case 0:
            printf("Thank You, Ended !");
            break;
        default:
            printf("Enter a valid choice");
            break;
        }

        Reset(&arr1);
        printf("\nPresent Array: ");
        Display(arr1);
    }
    return 0;
}