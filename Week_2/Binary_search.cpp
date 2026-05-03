// =====================================
// Week-2 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Recursive Binary Search
int binarySearch(const vector<int>& arr, int left, int right, int key) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, left, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, right, key);
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int iterations = 10000;

    cout << "Binary Search Performance\n";
    cout << "Size\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int n : sizes) {

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;  // sorted array
        }

        int key = -1; // not present → worst case

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < iterations; i++) {
            temp += binarySearch(arr, 0, n - 1, key);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::micro> timeTaken = end - start;
        double avg = timeTaken.count() / iterations;

        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}