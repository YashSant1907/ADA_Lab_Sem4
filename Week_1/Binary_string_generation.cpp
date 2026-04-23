#include <iostream>
#include <chrono>
#include <string>

using namespace std;

// Generate all binary strings of length n
void generateBinary(string &s, int pos, int n) {
    if (pos == n) {
        return;
    }

    s[pos] = '0';
    generateBinary(s, pos + 1, n);

    s[pos] = '1';
    generateBinary(s, pos + 1, n);
}

int main() {
    int sizes[10] = {5, 8, 10, 12, 14, 16, 18, 20, 21, 23};

    cout << "Binary String Generation using Recursion\n";
    cout << "Length\t|\tAverage Time (microseconds)\n";
    cout << "--------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        int n = sizes[i];
        double total = 0;

        for (int t = 0; t < 10; t++) {

            string s(n, '0');

            auto start = chrono::high_resolution_clock::now();

            generateBinary(s, 0, n);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / 10.0;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}