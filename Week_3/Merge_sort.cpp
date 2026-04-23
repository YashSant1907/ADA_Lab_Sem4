#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Merge function (without sentinel)
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    vector<int> sizes = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    int runs = 10;

    srand(time(0));

    cout << "Merge Sort Performance\n";
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

            mergeSort(temp, 0, n - 1);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / runs;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}