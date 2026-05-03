// =====================================
// Week-9 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str1 = "ABCBDAB";
    string str2 = "BDCABA";

    int n = str1.size();
    int m = str2.size();

    // DP table
    vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));

    // Build table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                table[i][j] = 1 + table[i - 1][j - 1];
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    cout << "Length of LCS: " << table[n][m] << endl;

    // Reconstruct LCS string
    string result = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if (table[i - 1][j] > table[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(result.begin(), result.end());

    cout << "LCS: " << result << endl;

    return 0;
}