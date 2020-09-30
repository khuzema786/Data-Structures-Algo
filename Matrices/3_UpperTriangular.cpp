// Upper Triangular

#include <iostream>
#include <algorithm> // std::fill_n(A, n * (n + 1) / 2, 0); to use this
using namespace std;

class UTMatrix
{
private:
    int n;
    int *A;

public:
    UTMatrix(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
        std::fill_n(A, n * (n + 1) / 2, 0); // Initialize all heap array elements to zero
    }
    ~UTMatrix() { delete[] A; }
    void Display(bool row = true);
    void setRowMajor(int i, int j, int x);
    void setColMajor(int i, int j, int x);
    int getRowMajor(int i, int j);
    int getColMajor(int i, int j);
    int getN() { return n; }
};

void UTMatrix::setRowMajor(int i, int j, int x)
{
    if (j >= i)
    {
        int index = (n * (i - 1) - (((i - 2) * (i - 1)) / 2)) + (j - i);
        A[index] = x;
    }
}

void UTMatrix::setColMajor(int i, int j, int x)
{
    if (j >= i)
    {
        int index = ((j * (j - 1)) / 2) + i - 1;
        A[index] = x;
    }
}

int UTMatrix::getRowMajor(int i, int j)
{
    if (j >= i)
    {
        int index = (n * (i - 1) - (((i - 2) * (i - 1)) / 2)) + (j - i);
        return A[index];
    }
    else
    {
        return 0;
    }
}

int UTMatrix::getColMajor(int i, int j)
{
    if (j >= i)
    {
        int index = ((j * (j - 1)) / 2) + i - 1;
        return A[index];
    }
    else
    {
        return 0;
    }
}

void UTMatrix::Display(bool row)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
            {
                if (row)
                {
                    cout << getRowMajor(i, j) << " ";
                }
                else
                {
                    cout << getColMajor(i, j) << " ";
                }
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{

    UTMatrix rm(4);

    rm.setRowMajor(1, 1, 1);
    rm.setRowMajor(1, 2, 2);
    rm.setRowMajor(1, 3, 3);
    rm.setRowMajor(1, 4, 4);
    rm.setRowMajor(2, 2, 5);
    rm.setRowMajor(2, 3, 6);
    rm.setRowMajor(2, 4, 7);
    rm.setRowMajor(3, 3, 8);
    rm.setRowMajor(3, 4, 9);
    rm.setRowMajor(4, 4, 10);

    rm.Display();
    cout << endl;

    UTMatrix cm(4);

    cm.setColMajor(1, 1, 1);
    cm.setColMajor(1, 2, 2);
    cm.setColMajor(1, 3, 3);
    cm.setColMajor(1, 4, 4);
    cm.setColMajor(2, 2, 5);
    cm.setColMajor(2, 3, 6);
    cm.setColMajor(2, 4, 7);
    cm.setColMajor(3, 3, 8);
    cm.setColMajor(3, 4, 9);
    cm.setColMajor(4, 4, 10);

    cm.Display(false);

    return 0;
}