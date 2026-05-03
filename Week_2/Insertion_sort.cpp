// =====================================
// Week-2 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Insertion Sort (worst case)
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    vector<int> sizes = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    int iterations = 10;

    cout << "Insertion Sort (Worst Case)\n";
    cout << "Size\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int n : sizes) {

        // Create worst-case array (descending order)
        vector<int> original(n);
        for (int i = 0; i < n; i++) {
            original[i] = n - i;
        }

        double total = 0;

        for (int i = 0; i < iterations; i++) {

            vector<int> temp = original; // copy

            auto start = chrono::high_resolution_clock::now();

            insertionSort(temp);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / iterations;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}