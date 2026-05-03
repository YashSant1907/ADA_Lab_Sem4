#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

int counter = 0; // prevents optimization

void generateSubsets(int index, int size, vector<bool> &state)
{
    if (index == size)
    {
        counter++;   // simulate processing a subset
        return;
    }

    state[index] = true;
    generateSubsets(index + 1, size, state);

    state[index] = false;
    generateSubsets(index + 1, size, state);
}

int main()
{
    const int trials = 100;

    cout << "n\tAvg Time (microseconds)\n";

    for (int size = 2; size <= 15; size++)
    {
        long long timeSum = 0;
        vector<bool> state(size);

        for (int t = 0; t < trials; t++)
        {
            counter = 0; // reset

            auto start = high_resolution_clock::now();

            generateSubsets(0, size, state);

            auto end = high_resolution_clock::now();

            timeSum += duration_cast<microseconds>(end - start).count();
        }

        double avgTime = (double)timeSum / trials;

        cout << size << "\t" << avgTime << endl;
    }

    return 0;
}