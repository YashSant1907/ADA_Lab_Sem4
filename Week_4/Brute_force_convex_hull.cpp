// =====================================
// Week-4 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    int x, y;
};

// Cross product
long long crossProduct(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Check if point lies inside triangle
bool isInside(Point A, Point B, Point C, Point P) {
    long long c1 = crossProduct(A, B, P);
    long long c2 = crossProduct(B, C, P);
    long long c3 = crossProduct(C, A, P);

    bool neg = (c1 < 0) || (c2 < 0) || (c3 < 0);
    bool pos = (c1 > 0) || (c2 > 0) || (c3 > 0);

    return !(neg && pos);
}

// Brute-force convex hull (count boundary points)
int bruteHull(vector<Point>& pts) {
    int n = pts.size();
    vector<bool> interior(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int p = 0; p < n; p++) {
                    if (p == i || p == j || p == k) continue;

                    if (isInside(pts[i], pts[j], pts[k], pts[p])) {
                        interior[p] = true;
                    }
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!interior[i]) count++;
    }
    return count;
}

int main() {
    vector<int> sizes = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    cout << "Convex Hull (Brute Force) - Time Analysis\n";
    cout << "Points\t|\tAvg Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    srand(time(0));

    for (int n : sizes) {
        vector<Point> pts(n);

        for (int i = 0; i < n; i++) {
            pts[i].x = rand() % 1000;
            pts[i].y = rand() % 1000;
        }

        double total = 0;

        for (int i = 0; i < 10; i++) {

            auto start = chrono::high_resolution_clock::now();

            int res = bruteHull(pts);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / 10.0;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}