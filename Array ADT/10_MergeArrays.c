// Merging 2 Arrays struct Array

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

struct Array *Merge(struct Array *arr1, struct Array *arr2) // O(n)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array)); // Dynamically Allocate arr3

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++]; // First it stores arr3->A[k] = arr1->A[i] and then increments k & i by one (Postincrement)
        else
            arr3->A[k++] = arr2->A[j++]; // First it stores arr3->A[k] = arr2->A[i] and then increments k & i by one (Postincrement)
    }
    // To copy the leftover elements from anyone of the array if present
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 16, 18, 28}, 10, 5};
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3); // Dereferencing of arr3, since our display function takes call by value

    return 0;
}