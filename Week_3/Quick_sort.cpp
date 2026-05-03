 // =====================================
 // Week-3 ADA Lab Codes
 // Algorithm Design and Analysis
 // =====================================
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[i]);
    return i;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int runs = 10;

    srand(time(0));

    cout << "Quick Sort Performance\n";
    cout << "Size\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int n : sizes) {

        vector<int> original(n);
        for (int i = 0; i < n; i++) {
            original[i] = rand() % 1000 + 1;
        }

        double total = 0;

        for (int i = 0; i < runs; i++) {

            vector<int> temp = original;

            auto start = chrono::high_resolution_clock::now();

            quickSort(temp, 0, n - 1);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / runs;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}