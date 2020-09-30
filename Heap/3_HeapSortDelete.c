// Heap Sort

#include <stdio.h>
void Insert(int A[], int n)
{
    int i = n, temp;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[1]; // Root goes out, gets deleted and stored in val
    // x = A[n];
    A[1] = A[n]; // When root goes out, last elemenrt in complete binary tree take its place
    A[n] = val;  // Deleted value gets stored at last of array, for maintaining heap sort
    i = 1;
    j = 2 * i;
    while (j <= n - 1)
    {
        // Also j should be less than n-1 so that when it has to move a step ahead... it moves correctly
        if (j < n - 1 && A[j + 1] > A[j]) // If right child is greater than left then move j to right child
            j = j + 1;
        if (A[i] < A[j]) // Compare the greatest value of child with parent, if greater than swap
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;     // Move i to j
            j = 2 * j; // Move j to left child
        }
        else
            break;
    }
    return val;
}
int main()
{
    int H[] = {0, 14, 15, 5, 20, 30, 8, 40}; // Note: Here indexing starts from 1
    int i;
    // Step1 -> Creating Heap -> O(n log n)
    for (i = 2; i <= 7; i++)
        Insert(H, i);
    // Step 2 -> Deleting Heap -> O(n log n)
    for (i = 7; i > 1; i--)
    {
        Delete(H, i);
    }
    // Step 3 -> Heap Sort -> O(n log n)
    for (i = 1; i <= 7; i++)
        printf("%d ", H[i]);
    printf("\n");

    return 0;
}