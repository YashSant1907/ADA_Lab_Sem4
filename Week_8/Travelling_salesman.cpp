// =====================================
// Week-8 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9;

// DP + Bitmask TSP
int solveTSP(int current, int visitedMask, vector<vector<int>> &dp, const vector<vector<int>> &cost)
{
    int n = cost.size();

    // All cities visited → return to start
    if (visitedMask == (1 << n) - 1)
        return cost[current][0];

    if (dp[current][visitedMask] != -1)
        return dp[current][visitedMask];

    int answer = INF;

    for (int next = 0; next < n; next++)
    {
        if ((visitedMask & (1 << next)) == 0)
        {
            int newMask = visitedMask | (1 << next);

            int temp = cost[current][next] +
                       solveTSP(next, newMask, dp, cost);

            answer = min(answer, temp);
        }
    }

    return dp[current][visitedMask] = answer;
}

int main()
{
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    int n = cost.size();

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int result = solveTSP(0, 1, dp, cost);

    cout << "Minimum travelling cost: " << result << endl;

    return 0;
}