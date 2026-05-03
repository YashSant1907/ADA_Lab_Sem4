// =====================================
// Week-1 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to calculate sum of elements
int computeSum(const vector<int>& arr) {
    int total = 0;

    for (int i = 0; i < arr.size(); i++) {
        total += arr[i];
    }

    return total;
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int iterations = 10000;

    srand(time(0));

    cout << "Array Sum Computation\n";
    cout << "Size\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int n : sizes) {

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000 + 1;
        }

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < iterations; i++) {
            temp += computeSum(arr);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::micro> timeTaken = end - start;
        double avg = timeTaken.count() / iterations;

        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}