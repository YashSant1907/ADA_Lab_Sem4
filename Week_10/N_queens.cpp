// =====================================
// Week-10 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>

using namespace std;

// Check if placing queen at (row, col) is safe
bool isSafe(int row, int col, vector<int> &pos)
{
    for (int prev = 0; prev < row; prev++)
    {
        // same column
        if (pos[prev] == col)
            return false;

        // diagonal conflict
        if (abs(pos[prev] - col) == abs(prev - row))
            return false;
    }
    return true;
}

// Recursive function based on your pseudocode
bool place(int queenNum, int n, vector<int> &pos)
{
    // all queens placed
    if (queenNum == n)
        return true;

    // try each column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(queenNum, col, pos))
        {
            pos[queenNum] = col;  // place queen

            // recursively place next queen
            if (place(queenNum + 1, n, pos))
                return true;
        }
    }

    return false; // no valid placement
}

int main()
{
    int n = 4;

    vector<int> pos(n, -1);

    if (place(0, n, pos))
    {
        cout << "Solution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pos[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists\n";
    }

    return 0;
}