#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9;

int main()
{
    int n = 8;

    // Cost adjacency matrix
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
    vector<int> nextNode(n, -1);

    // Destination node cost = 0
    dist[n - 1] = 0;

    // Backward computation
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != INF)
            {
                if (cost[i][j] + dist[j] < dist[i])
                {
                    dist[i] = cost[i][j] + dist[j];
                    nextNode[i] = j;
                }
            }
        }
    }

    // Print minimum cost
    cout << "Minimum cost from source to destination: " << dist[0] << endl;

    // Print path
    cout << "Path: ";
    int current = 0;
    while (current != -1)
    {
        cout << current << " ";
        current = nextNode[current];
    }

    cout << endl;

    return 0;
}