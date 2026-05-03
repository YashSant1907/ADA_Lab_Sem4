// =====================================
// Week-5 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 505;
const int MAXE = 10005;

struct Edge {
    int to, weight;
};

Edge graph[MAXN][MAXE];
int edgeCount[MAXN];

void addEdge(int u, int v, int w) {
    graph[u][edgeCount[u]++] = {v, w};
    graph[v][edgeCount[v]++] = {u, w};
}

// Heap node
struct HeapNode {
    int weight, u;

    bool operator>(const HeapNode &o) const { return weight > o.weight; }
    bool operator<(const HeapNode &o) const { return weight < o.weight; }
};

struct MinHeap {
    HeapNode data[MAXE];
    int sz = 0;

    void push(HeapNode x) {
        data[sz++] = x;
        int i = sz - 1;

        while (i > 0) {
            int p = (i - 1) / 2;
            if (data[i] < data[p]) {
                swap(data[i], data[p]);
                i = p;
            } else break;
        }
    }

    HeapNode top() { return data[0]; }

    void pop() {
        data[0] = data[--sz];
        int i = 0;

        while (true) {
            int l = 2*i+1, r = 2*i+2, smallest = i;

            if (l < sz && data[l] < data[smallest]) smallest = l;
            if (r < sz && data[r] < data[smallest]) smallest = r;

            if (smallest == i) break;

            swap(data[i], data[smallest]);
            i = smallest;
        }
    }

    bool empty() { return sz == 0; }
};

bool visited[MAXN];

int prims(int n) {
    for (int i = 0; i < n; i++) visited[i] = false;

    MinHeap pq;
    pq.push({0, 0});

    int minCost = 0;

    while (!pq.empty()) {
        auto node = pq.top(); pq.pop();

        int weight = node.weight;
        int u = node.u;

        if (visited[u]) continue;

        visited[u] = true;
        minCost += weight;

        for (int i = 0; i < edgeCount[u]; i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;

            if (!visited[v])
                pq.push({w, v});
        }
    }

    return minCost;
}

int testValues[10] = {50,100,150,200,250,300,350,400,450,500};

int main() {
    cout << "Prims Algorithm - Time Analysis\n";

    for (int i = 0; i < 10; i++) {
        int n = testValues[i];

        for (int j = 0; j < n; j++) edgeCount[j] = 0;

        srand(time(0) + i);

        for (int j = 0; j < n - 1; j++)
            addEdge(j, j + 1, rand() % 100 + 1);

        for (int j = 0; j < 2 * n; j++) {
            int u = rand() % n;
            int v = rand() % n;
            if (u != v)
                addEdge(u, v, rand() % 100 + 1);
        }

        double total = 0;

        for (int k = 0; k < 10; k++) {
            auto start = chrono::high_resolution_clock::now();

            int cost = prims(n);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        cout << "Vertices: " << n
             << " | Avg Time: " << total / 10
             << " microseconds\n";
    }
}