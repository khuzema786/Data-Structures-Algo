// Get Set Max Min on Array

#include<stdio.h>

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
    for(i=0; i < arr.length; i++)
        printf("%d ",arr.A[i]);
}

void swap(int *x,int *y)
{
    int temp= *x;
    *x= *y;
    *y= temp;
}

int Get(struct Array arr, int index) // To get a value at an index from the array -> O(1)
{
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr,int index,int x) // To set a value at an index in the array -> O(1)
{
    if(index >= 0 && index < arr ->length)
        arr-> A[index] = x;
}

int Max(struct Array arr) // To get the Maximum value from the array -> O(n)
{
    int max= arr.A[0];
    int i;
    for(i=1; i < arr.length; i++)
    {
        if(arr.A[i] > max)
            max= arr.A[i];
    }
    return max;
}

int Min(struct Array arr) // To get the Minimum value from the array -> O(n)
{
    int min= arr.A[0];
    int i;
    for(i=1; i < arr.length; i++)
    {
        if(arr.A[i] < min)
            min= arr.A[i];
    }
    return min;
}

int Sum(struct Array arr) // To get the sum of all the elements in the array -> O(n)
{
    int s=0;
    int i;
    for(i=0; i < arr.length; i++)
        s += arr.A[i];
    return s;
}

float Avg(struct Array arr) // To get the avg of all the elements in the array -> O(n)
{
    return (float)Sum(arr)/arr.length;
}

int main()
{
    struct Array arr1={{2,3,9,16,18,21,28,32,35},10,9};
    printf("%d",Sum(arr1));
    Display(arr1);
    return 0;
}