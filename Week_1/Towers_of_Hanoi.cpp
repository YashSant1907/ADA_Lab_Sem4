// =====================================
// Week-1 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <chrono>

using namespace std;

// Recursive function for Tower of Hanoi
void solveHanoi(int n, char source, char destination, char helper) {
    if (n == 0)
        return;

    solveHanoi(n - 1, source, helper, destination);

    // Move step (not printing to avoid time overhead)

    solveHanoi(n - 1, helper, destination, source);
}

int main() {
    int disks[10] = {5, 8, 10, 12, 14, 16, 18, 20, 22, 24};

    cout << "Tower of Hanoi Execution Time\n";
    cout << "Disks\t|\tAverage Time (microseconds)\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        int n = disks[i];
        double total = 0;

        for (int j = 0; j < 10; j++) {

            auto start = chrono::high_resolution_clock::now();

            solveHanoi(n, 'A', 'C', 'B');

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / 10.0;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}