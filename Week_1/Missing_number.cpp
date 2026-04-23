#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to find missing number in sorted array
int getMissing(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1] + 1) {
            return arr[i - 1] + 1;
        }
    }
    return arr.back() + 1;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int repetitions = 10000;

    cout << "Missing Number Detection (Sequential Array)\n";
    cout << "Size\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int n : sizes) {

        vector<int> arr;
        arr.reserve(n);

        int missingValue = n; // simulate missing number

        for (int i = 1; i <= n + 1; i++) {
            if (i != missingValue) {
                arr.push_back(i);
            }
        }

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < repetitions; i++) {
            temp += getMissing(arr);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::micro> timeTaken = end - start;
        double avg = timeTaken.count() / repetitions;

        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}