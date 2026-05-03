// =====================================
// Week-5 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>

using namespace std;

// DFS helper to detect cycle
bool detectCycle(int current, int parent, vector<bool> &seen, const vector<vector<int>> &graph)
{
    seen[current] = true;

    for (int next : graph[current])
    {
        if (!seen[next])
        {
            if (detectCycle(next, current, seen, graph))
                return true;
        }
        else if (next != parent)
        {
            return true; // back-edge found
        }
    }
    return false;
}

// Function to check cycle in graph
bool isCyclic(const vector<vector<int>> &graph)
{
    int nodes = graph.size();
    vector<bool> seen(nodes, false);

    for (int i = 0; i < nodes; i++)
    {
        if (!seen[i])
        {
            if (detectCycle(i, -1, seen, graph))
                return true;
        }
    }
    return false;
}

int main()
{
    cout << "Checking Graphs for Cycle\n\n";

    // Graph 1 (contains cycle)
    vector<vector<int>> graph1 = {
        {1, 2}, {0, 2}, {0, 1, 3}, {2}
    };

    cout << "Graph 1: ";
    if (isCyclic(graph1))
        cout << "Cycle detected\n\n";
    else
        cout << "No cycle\n\n";

    // Graph 2 (no cycle)
    vector<vector<int>> graph2 = {
        {1}, {0, 2}, {1, 3}, {2}
    };

    cout << "Graph 2: ";
    if (isCyclic(graph2))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}