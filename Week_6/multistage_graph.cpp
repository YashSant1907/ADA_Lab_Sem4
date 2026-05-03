// =====================================
// Week-6 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <climits>
using namespace std;

const int MAX = 50;
const int INF = INT_MAX / 2;

int n, e;
int cost[MAX][MAX];
int dp[MAX], path[MAX];

// Build adjacency matrix
void buildMatrix() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = (i == j) ? 0 : INF;

    cout << "Enter edges (u v cost):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u >= v) {
            cout << "Enter forward edge only (u < v)\n";
            i--;
            continue;
        }

        cost[u][v] = w;
    }
}

// DP function
void multistageGraph() {
    for (int i = 0; i < n; i++) {
        dp[i] = INF;
        path[i] = -1;
    }

    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != INF) {
                if (cost[i][j] + dp[j] < dp[i]) {
                    dp[i] = cost[i][j] + dp[j];
                    path[i] = j;
                }
            }
        }
    }
}

// Print path safely
void printPath() {
    cout << "Path: ";
    int cur = 0;
    int count = 0;

    while (cur != -1 && count < n) {
        cout << cur;
        if (path[cur] != -1) cout << " -> ";
        cur = path[cur];
        count++;
    }
    cout << endl;
}

int main() {
    cout << "UE243129 - Multistage Graph using DP\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    buildMatrix();
    multistageGraph();

    if (dp[0] == INF) {
        cout << "\nNo path exists!\n";
        return 0;
    }

    cout << "\nMinimum Cost: " << dp[0] << endl;
    printPath();

    return 0;
}