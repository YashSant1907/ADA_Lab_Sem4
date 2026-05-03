// =====================================
// Week-7 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dp[100][100];     // cost table
int splitPos[100][100];  // store split points

// Function to compute minimum multiplication cost
void matrixChainOrder(vector<int>& dims, int n) {

    // Base case
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int length = 2; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int currCost = dp[i][k] + dp[k+1][j] 
                               + dims[i-1] * dims[k] * dims[j];

                if (currCost < dp[i][j]) {
                    dp[i][j] = currCost;
                    splitPos[i][j] = k;
                }
            }
        }
    }
}

// Print optimal parenthesis
void showOrder(int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }

    cout << "(";
    showOrder(i, splitPos[i][j]);
    showOrder(splitPos[i][j] + 1, j);
    cout << ")";
}

int main() {
    cout << "UE243129 - Matrix Chain Multiplication\n";

    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> dims(n + 1);

    cout << "Enter dimensions array:\n";
    for (int i = 0; i <= n; i++)
        cin >> dims[i];

    matrixChainOrder(dims, n);

    cout << "\nMinimum Multiplication Cost: " << dp[1][n] << endl;

    cout << "Optimal Parenthesization: ";
    showOrder(1, n);
    cout << endl;

    return 0;
}