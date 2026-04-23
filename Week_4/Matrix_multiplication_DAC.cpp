#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Add matrices
void addMatrix(vector<vector<int>>& A, vector<vector<int>>& B,
               vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Multiply using divide and conquer
void multiply(vector<vector<int>>& A, vector<vector<int>>& B,
              vector<vector<int>>& C, int n) {

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;

    vector<vector<int>> A11(half, vector<int>(half)), A12(half, vector<int>(half));
    vector<vector<int>> A21(half, vector<int>(half)), A22(half, vector<int>(half));

    vector<vector<int>> B11(half, vector<int>(half)), B12(half, vector<int>(half));
    vector<vector<int>> B21(half, vector<int>(half)), B22(half, vector<int>(half));

    vector<vector<int>> C11(half, vector<int>(half)), C12(half, vector<int>(half));
    vector<vector<int>> C21(half, vector<int>(half)), C22(half, vector<int>(half));

    vector<vector<int>> T1(half, vector<int>(half)), T2(half, vector<int>(half));

    // Split matrices
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // C11 = A11*B11 + A12*B21
    multiply(A11, B11, T1, half);
    multiply(A12, B21, T2, half);
    addMatrix(T1, T2, C11, half);

    // C12
    multiply(A11, B12, T1, half);
    multiply(A12, B22, T2, half);
    addMatrix(T1, T2, C12, half);

    // C21
    multiply(A21, B11, T1, half);
    multiply(A22, B21, T2, half);
    addMatrix(T1, T2, C21, half);

    // C22
    multiply(A21, B12, T1, half);
    multiply(A22, B22, T2, half);
    addMatrix(T1, T2, C22, half);

    // Merge results
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

int main() {
    vector<int> sizes = {2, 4, 8, 16, 32, 64};
    int trials = 10;

    cout << "Matrix Multiplication (Divide and Conquer)\n";
    cout << fixed << setprecision(4);

    srand(time(0));

    for (int n : sizes) {

        vector<vector<int>> A(n, vector<int>(n));
        vector<vector<int>> B(n, vector<int>(n));
        vector<vector<int>> C(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }

        double total = 0;

        for (int t = 0; t < trials; t++) {

            auto start = chrono::high_resolution_clock::now();

            multiply(A, B, C, n);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / trials;
        cout << "Size " << setw(3) << n << " : " << avg << " microseconds\n";
    }

    return 0;
}