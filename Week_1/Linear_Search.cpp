#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Linear Search Function
int searchElement(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    vector<int> sizes = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    int repetitions = 10000;

    srand(time(0));

    cout << "Linear Search Performance Analysis\n";
    cout << "Size\t|\tAverage Time (microseconds)\n";
    cout << "------------------------------------------\n";

    for (int n : sizes) {

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000 + 1;
        }

        int key = -1; // not present → worst case

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < repetitions; i++) {
            temp += searchElement(arr, key);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::micro> timeTaken = end - start;
        double avg = timeTaken.count() / repetitions;

        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}