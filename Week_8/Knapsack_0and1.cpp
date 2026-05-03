// =====================================
// Week-8 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>

using namespace std;

int solveKnapsack(int capacity, const vector<int> &weights, const vector<int> &values)
{
    int n = values.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int item = 1; item <= n; item++)
    {
        for (int cap = 1; cap <= capacity; cap++)
        {
            // not taking the item
            dp[item][cap] = dp[item - 1][cap];

            // taking the item (if possible)
            if (weights[item - 1] <= cap)
            {
                int include = values[item - 1] +
                              dp[item - 1][cap - weights[item - 1]];

                dp[item][cap] = max(dp[item][cap], include);
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int result = solveKnapsack(capacity, weights, values);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}