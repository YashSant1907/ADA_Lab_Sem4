#include <iostream>
#include <vector>
using namespace std;

// Matrix addition
vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];

    return C;
}

// Matrix subtraction
vector<vector<int>> subtractMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];

    return C;
}

// Strassen function
vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();

    vector<vector<int>> C(n, vector<int>(n));

    // Base case
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int mid = n / 2;

    // Splitting matrices
    vector<vector<int>> A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)),
                        A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)),
                        B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // 7 recursive multiplications
    auto M1 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22));
    auto M2 = strassenMultiply(addMatrix(A21, A22), B11);
    auto M3 = strassenMultiply(A11, subtractMatrix(B12, B22));
    auto M4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    auto M5 = strassenMultiply(addMatrix(A11, A12), B22);
    auto M6 = strassenMultiply(subtractMatrix(A21, A11), addMatrix(B11, B12));
    auto M7 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22));

    // Combining results
    auto C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    auto C12 = addMatrix(M3, M5);
    auto C21 = addMatrix(M2, M4);
    auto C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

    // Joining submatrices
    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }

    return C;
}

int main()
{
    int n;
    cout << "Enter size of matrix (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    auto C = strassenMultiply(A, B);

    cout << "\nResult Matrix:\n";
    for (auto &row : C)
    {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}