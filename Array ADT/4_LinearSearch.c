// Searching in a Array

#include<stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

 void Display(struct Array arr) // O(n)
 {
    int i;
    printf("\nElements are\n");
    for(i=0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
 }
 
void swap(int *x,int *y)
 {
    int temp= *x;
    *x= *y;
    *y= temp;
 }

int LinearSearch(struct Array *arr,int key) // O(n)
{
    int i;
    for(i=0; i < arr-> length; i++)
    {
        if(key == arr-> A[i])
        {
            // swap(&arr->A[i],&arr->A[i-1]); // Transposition
            swap(&arr-> A[i], &arr-> A[0]); // Move to front/head

            return i; // If found, return the index of key
        }
    }
    return -1; // If not found
}

int main()
{
    struct Array arr1={{2,23,14,5,6,9,8,12}, 10, 8};

    printf("Key is found at index: %d", LinearSearch(&arr1,14));
    Display(arr1);

    return 0;
}