// Checking if Array is Sorted

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertInSorted(struct Array *arr, int x) // -> O(n)
{
    int i = arr->length - 1;
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int isSorted(struct Array arr) // Ascending order -> O(n)
{
    int i;
    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void NegativeToLeft(struct Array *arr) // -> O(n)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 10, 9};

    if (isSorted(arr1) == 1)
        printf("Array Is Sorted \n");
    else
        printf("Array is Not Sorted \n");

    insertInSorted(&arr1, 13);
    printf("\n13 inserted in sorted array");
    Display(arr1);

    struct Array arr2 = {{-2, 3, -9, 16, 18, -21, 28, 32, 35}, 10, 9};
    printf("\nNegative elements to the left \n");
    NegativeToLeft(&arr2);
    Display(arr2);

    return 0;
}