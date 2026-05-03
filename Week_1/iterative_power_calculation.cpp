// =====================================
// Week-1 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Iterative power function
long long computePower(int base, int exp) {
    long long result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

int main() {
    int exponents[10] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    int iterations = 10000;

    srand(time(0));
    int base = rand() % 9 + 2;

    cout << "Iterative Power Calculation\n";
    cout << "Base = " << base << endl;
    cout << "Exponent\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        int n = exponents[i];

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int j = 0; j < iterations; j++) {
            temp += computePower(base, n);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::micro> timeTaken = end - start;
        double avg = timeTaken.count() / iterations;

        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}