#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9;

int main()
{
    int n = 4; // number of vertices

    // Distance matrix (use INF for no direct edge)
    vector<vector<int>> dist = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // Core algorithm
    for (int k = 0; k < n; k++)        // intermediate (via)
    {
        for (int i = 0; i < n; i++)    // source
        {
            for (int j = 0; j < n; j++) // destination
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print shortest path matrix
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Optional: Detect negative cycle
    bool hasNegativeCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < 0)
        {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle)
        cout << "\nGraph contains a negative cycle!\n";

    return 0;
}