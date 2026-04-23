#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 505;
const int MAXE = 1505;

struct Edge {
    int u, v, weight;
};

int parent[MAXN];
int rankValue[MAXN];

void initDS(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankValue[i] = 0;
    }
}

int findParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}

void unionSet(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if (u == v) return;

    if (rankValue[u] < rankValue[v]) parent[u] = v;
    else if (rankValue[u] > rankValue[v]) parent[v] = u;
    else {
        parent[v] = u;
        rankValue[u]++;
    }
}

Edge edges[MAXE];
int edgeCount;

// Insertion sort by weight
void sortEdges(int count) {
    for (int i = 1; i < count; i++) {
        Edge key = edges[i];
        int j = i - 1;

        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j--;
        }

        edges[j + 1] = key;
    }
}

int kruskal(int n) {
    sortEdges(edgeCount);
    initDS(n);

    int minCost = 0;

    for (int i = 0; i < edgeCount; i++) {
        if (findParent(edges[i].u) != findParent(edges[i].v)) {
            minCost += edges[i].weight;
            unionSet(edges[i].u, edges[i].v);
        }
    }

    return minCost;
}

int testValues[10] = {50,100,150,200,250,300,350,400,450,500};

int main() {
    cout << "Kruskal Algorithm - Time Analysis\n";

    for (int i = 0; i < 10; i++) {
        int n = testValues[i];
        edgeCount = 0;

        srand(time(0) + i);

        for (int j = 0; j < n - 1; j++)
            edges[edgeCount++] = {j, j + 1, rand() % 100 + 1};

        for (int j = 0; j < 2 * n; j++) {
            int u = rand() % n;
            int v = rand() % n;
            if (u != v)
                edges[edgeCount++] = {u, v, rand() % 100 + 1};
        }

        double total = 0;

        for (int k = 0; k < 10; k++) {
            auto start = chrono::high_resolution_clock::now();

            int cost = kruskal(n);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        cout << "Vertices: " << n
             << " | Avg Time: " << total / 10
             << " microseconds\n";
    }
}