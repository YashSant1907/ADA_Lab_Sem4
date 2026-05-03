#include <iostream>
#include <vector>

using namespace std;

int n = 4; // number of nodes

// Adjacency matrix
vector<vector<int>> G = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

vector<int> color; // color array

// Check if color can be assigned
bool isValid(int node, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (G[node][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool assignColor(int node, int m)
{
    // all nodes colored
    if (node == n)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isValid(node, c))
        {
            color[node] = c;

            if (assignColor(node + 1, m))
                return true;

            color[node] = 0; // backtrack
        }
    }

    return false;
}

int main()
{
    int m = 1;

    while (true)
    {
        color.assign(n, 0); // reset colors

        if (assignColor(0, m))
        {
            cout << "Minimum colors needed: " << m << endl;

            cout << "Color assignment:\n";
            for (int i = 0; i < n; i++)
                cout << "Node " << i << " -> Color " << color[i] << endl;

            break;
        }

        m++; // try with more colors
    }

    return 0;
}