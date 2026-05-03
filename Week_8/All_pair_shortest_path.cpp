#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main()
{
    int n = 4; // number of vertices

    vector<vector<int>> dist = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // Floyd-Warshall Algorithm
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][via] < INF && dist[via][j] < INF)
                {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    // Print result
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

    return 0;
}