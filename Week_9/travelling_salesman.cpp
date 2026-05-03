#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e9;

// DP function
int tspSolve(int city, int mask, vector<vector<int>> &dp, const vector<vector<int>> &cost)
{
    int n = cost.size();

    // All cities visited → return to start
    if (mask == (1 << n) - 1)
        return cost[city][0];

    if (dp[city][mask] != -1)
        return dp[city][mask];

    int best = INF;

    for (int next = 0; next < n; next++)
    {
        if ((mask & (1 << next)) == 0)
        {
            int newMask = mask | (1 << next);

            int currCost = cost[city][next] +
                           tspSolve(next, newMask, dp, cost);

            best = min(best, currCost);
        }
    }

    return dp[city][mask] = best;
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

    int answer = tspSolve(0, 1, dp, cost);

    cout << "Minimum tour cost: " << answer << endl;

    return 0;
}