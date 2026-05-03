// =====================================
// Week-1 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

// Evaluate polynomial using Horner's Method
double evaluatePolynomial(const vector<double>& coeff, double x) {
    int degree = coeff.size() - 1;
    double value = coeff[degree];

    for (int i = degree - 1; i >= 0; --i) {
        value = value * x + coeff[i];
    }
    return value;
}

int main() {
    vector<int> degrees = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    double x = 0.5;
    int iterations = 10000;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(1.0, 10.0);

    cout << "Polynomial Evaluation using Horner Method\n";
    cout << "Degree\t|\tAvg Time (microseconds)\n";
    cout << "------------------------------------------\n";

    for (int deg : degrees) {
        vector<double> coeff(deg + 1);

        for (auto &c : coeff) {
            c = dist(gen);
        }

        double temp = 0;

        auto start = chrono::high_resolution_clock::now();

        for (int i = 0; i < iterations; ++i) {
            temp += evaluatePolynomial(coeff, x);
        }

        auto stop = chrono::high_resolution_clock::now();

        chrono::duration<double, micro> elapsed = stop - start;
        double avg = elapsed.count() / iterations;

        cout << deg << "\t|\t" << avg << endl;
    }

    return 0;
}