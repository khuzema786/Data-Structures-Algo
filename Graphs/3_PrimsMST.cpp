// Prims MST

#include <iostream>
#define V 8
#define I 32767

using namespace std;

void PrintMST(int T[][V - 2], int G[V][V])
{
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n"
         << endl;
    int sum{0};
    // Iterate through T containing minimum cost edges
    for (int i{0}; i < V - 2; i++)
    {
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}

void PrimsMST(int G[V][V], int n)
{
    int u;
    int v;
    int min{I};
    int near[V];
    int T[2][V - 2]{0}; // T[2][6]

    // Initial: Find min cost edge from upper triangular cost matrix
    for (int i{1}; i < V; i++)
    {
        near[i] = I; // Initialize near array with INFINITY
        for (int j{i}; j < V; j++)
        {
            if (G[i][j] < min)
            {
                min = G[i][j]; // 5
                u = i;         // 1
                v = j;         // 6
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    near[u] = near[v] = 0;

    // Initialize near array to near min cost edges
    for (int i{1}; i < V; i++)
    {
        if (near[i] != 0)
        {
            if (G[i][u] < G[i][v])
            {
                near[i] = u;
            }
            else
            {
                near[i] = v;
            }
        }
    }

    // Repeat till you find all minimum edges
    for (int i{1}; i < n - 1; i++)
    {
        int k;
        min = I;
        for (int j{1}; j < V; j++)
        {
            if (near[j] != 0 && G[j][near[j]] < min)
            {
                k = j; // Visited vertex which has minimum cost so far
                min = G[j][near[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = near[k];
        near[k] = 0; // Visited minimum cost vertex is set to zero in near array so that it does not get visited again

        // Update near array to near min cost edges
        for (int j{1}; j < V; j++)
        {
            if (near[j] != 0 && G[j][k] < G[j][near[j]])
            {
                near[j] = k;
            }
        }
    }
    PrintMST(T, G);
}

int main()
{

    int cost[V][V]{
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1; // 7

    PrimsMST(cost, n);

    return 0;
}