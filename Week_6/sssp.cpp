#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> Edge; // (neighbor, weight)

void shortestPath(int source, const vector<vector<Edge>> &graph)
{
    int n = graph.size();

    vector<int> dist(n, numeric_limits<int>::max());

    // Min-heap (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (currDist > dist[node])
            continue;

        for (auto &edge : graph[node])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor])
            {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Output result
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

int main()
{
    int V = 5;

    vector<vector<Edge>> graph(V);

    // Example graph (undirected)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({0, 4});
    graph[2].push_back({1, 1});
    graph[2].push_back({4, 3});
    graph[3].push_back({1, 7});
    graph[3].push_back({4, 1});
    graph[4].push_back({2, 3});
    graph[4].push_back({3, 1});

    int source = 0;

    shortestPath(source, graph);

    return 0;
}