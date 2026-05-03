#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int> &arr, int n, int target,
                     int pos, int sum,
                     vector<int> &temp, int len, int &count)
{
    // If target achieved → print subset
    if (sum == target)
    {
        cout << "{ ";
        for (int i = 0; i < len; i++)
            cout << temp[i] << " ";
        cout << "}\n";

        count++;
    }

    // Stop conditions
    if (pos == n || sum > target)
        return;

    // Include current element
    temp[len] = arr[pos];
    generateSubsets(arr, n, target,
                    pos + 1, sum + arr[pos],
                    temp, len + 1, count);

    // Exclude current element
    generateSubsets(arr, n, target,
                    pos + 1, sum,
                    temp, len, count);
}

int main()
{
    vector<int> arr = {2, 4, 6, 10};
    int target = 16;
    int n = arr.size();

    vector<int> temp(n); // to store subset
    int count = 0;

    generateSubsets(arr, n, target, 0, 0, temp, 0, count);

    cout << "\nTotal subsets found: " << count << endl;

    return 0;
}