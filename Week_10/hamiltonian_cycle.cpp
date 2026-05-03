#include <iostream>
#include <vector>

using namespace std;

int n = 5; // number of vertices

// Adjacency matrix
vector<vector<int>> adj = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

vector<int> cycle(n, -1);

// Check if node can be placed at position "step"
bool canPlace(int node, int step)
{
    // Check adjacency with previous node
    if (adj[cycle[step - 1]][node] == 0)
        return false;

    // Check if already included in cycle
    for (int i = 0; i < step; i++)
    {
        if (cycle[i] == node)
            return false;
    }

    return true;
}

// Recursive function
bool buildCycle(int step)
{
    // All vertices included
    if (step == n)
    {
        // Check last node connects to first
        if (adj[cycle[step - 1]][cycle[0]] == 1)
        {
            return true;
        }
        else
            return false;
    }

    // Try all possible vertices
    for (int candidate = 1; candidate < n; candidate++)
    {
        if (canPlace(candidate, step))
        {
            cycle[step] = candidate;

            if (buildCycle(step + 1))
                return true;

            // backtrack
            cycle[step] = -1;
        }
    }

    return false;
}

int main()
{
    cycle[0] = 0; // start from vertex 0

    if (buildCycle(1))
    {
        cout << "Hamiltonian Cycle: ";
        for (int i = 0; i < n; i++)
            cout << cycle[i] << " ";
        cout << cycle[0] << endl; // complete cycle
    }
    else
    {
        cout << "No Hamiltonian cycle exists\n";
    }

    return 0;
}