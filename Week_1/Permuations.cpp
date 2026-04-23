#include <iostream>
#include <chrono>
#include <string>

using namespace std;

// Function to generate permutations
void generatePermutations(string &s, int index) {
    if (index == s.length()) {
        return;
    }

    for (int i = index; i < s.length(); i++) {
        // swap
        swap(s[index], s[i]);

        generatePermutations(s, index + 1);

        // backtrack
        swap(s[index], s[i]);
    }
}

int main() {
    int sizes[8] = {3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Permutation Generation (String)\n";
    cout << "Length\t|\tAverage Time (microseconds)\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < 8; i++) {
        int n = sizes[i];
        double total = 0;

        for (int t = 0; t < 10; t++) {

            string s = "";
            for (int j = 0; j < n; j++) {
                s += char('a' + j);
            }

            auto start = chrono::high_resolution_clock::now();

            generatePermutations(s, 0);

            auto end = chrono::high_resolution_clock::now();

            chrono::duration<double, std::micro> timeTaken = end - start;
            total += timeTaken.count();
        }

        double avg = total / 10.0;
        cout << n << "\t|\t" << avg << endl;
    }

    return 0;
}