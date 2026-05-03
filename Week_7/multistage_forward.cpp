#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9;

int main()
{
    int n = 8; // number of nodes

    // Adjacency matrix (cost)
    vector<vector<int>> cost = {
        {INF, 2, 1, 3, INF, INF, INF, INF},
        {INF, INF, INF, INF, 2, 3, INF, INF},
        {INF, INF, INF, INF, 6, 7, INF, INF},
        {INF, INF, INF, INF, 6, 8, 9, INF},
        {INF, INF, INF, INF, INF, INF, INF, 6},
        {INF, INF, INF, INF, INF, INF, INF, 4},
        {INF, INF, INF, INF, INF, INF, INF, 5},
        {INF, INF, INF, INF, INF, INF, INF, INF}
    };

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    dist[0] = 0; // source node

    // Forward DP computation
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF) continue;

        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INF)
            {
                if (dist[i] + cost[i][j] < dist[j])
                {
                    dist[j] = dist[i] + cost[i][j];
                    parent[j] = i;
                }
            }
        }
    }

    // Print shortest cost
    cout << "Minimum cost to reach destination: " << dist[n - 1] << endl;

    // Print path
    vector<int> path;
    int current = n - 1;

    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    cout << "Path: ";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";

    cout << endl;

    return 0;
}