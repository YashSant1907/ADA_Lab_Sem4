#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    int n = s1.length();
    int m = s2.length();

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Step 1: Fill DP table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "Length of LCS: " << dp[n][m] << endl;

    // Step 2: Reconstruct LCS string
    string lcs = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs.begin(), lcs.end());

    cout << "LCS: " << lcs << endl;

    return 0;
}