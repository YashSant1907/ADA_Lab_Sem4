// =====================================
// Week-1 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Fast power using recursion (divide and conquer)
long long fastPower(int base, int exp) {
    if (exp == 0)
        return 1;

    long long result = fastPower(base, exp / 2);

    if (exp % 2 == 0)
        return result * result;
    else
        return base * result * result;
}

int main() {
    int exponents[10] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    int iterations = 10000;

    srand(time(0));
    int base = rand() % 9 + 2;

    cout << "Recursive Fast Power Calculation\n";
    cout << "Base = " << base << endl;
    cout << "Exponent\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        int n = exponents[i];

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int j = 0; j < iterations; j++) {
            temp += fastPower(base, n);
        }

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::micro> timeTaken = end - start;
        double avg = timeTaken.count() / iterations;

        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}