// =====================================
// Week-10 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
using namespace std;

const int MAX = 10;

// Check if color is safe
bool isSafe(int node, int graph[MAX][MAX], int color[], int c, int n) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function
bool solve(int graph[MAX][MAX], int m, int color[], int node, int n) {
    if (node == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, graph, color, c, n)) {
            color[node] = c;

            if (solve(graph, m, color, node + 1, n))
                return true;

            color[node] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    int n = 4;

    int graph[MAX][MAX] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int color[MAX];

    int m = 1;

    while (true) {
        for (int i = 0; i < n; i++)
            color[i] = 0;

        if (solve(graph, m, color, 0, n)) {
            cout << "Minimum colors required: " << m << endl;

            for (int i = 0; i < n; i++)
                cout << "Node " << i << " -> Color " << color[i] << endl;

            break;
        }

        m++;
    }

    return 0;
}