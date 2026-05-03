// =====================================
// Week-4 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Item {
    int profit;
    int weight;
};

// Sort by weight (ascending)
int knapsackByWeight(Item items[], int n, int capacity) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (items[j].weight > items[j + 1].weight)
                swap(items[j], items[j + 1]);

    int total = 0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            total += items[i].profit;
            capacity -= items[i].weight;
        }
    }
    return total;
}

// Sort by profit (descending)
int knapsackByProfit(Item items[], int n, int capacity) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (items[j].profit < items[j + 1].profit)
                swap(items[j], items[j + 1]);

    int total = 0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            total += items[i].profit;
            capacity -= items[i].weight;
        }
    }
    return total;
}

// Sort by profit/weight ratio
void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((double)items[j].profit / items[j].weight <
                (double)items[j + 1].profit / items[j + 1].weight)
                swap(items[j], items[j + 1]);
}

// Fractional knapsack
double fractionalKnapsack(Item items[], int n, int capacity) {
    sortByRatio(items, n);

    double total = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            total += items[i].profit;
            capacity -= items[i].weight;
        } else {
            total += (double)capacity / items[i].weight * items[i].profit;
            break;
        }
    }
    return total;
}

int main() {
    int sizes[10] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000};
    int runs = 10;

    srand(time(0));

    cout << "Knapsack (Greedy) - Time Analysis\n";
    cout << "Size | ByWeight | ByProfit | ByRatio\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < 10; i++) {
        int n = sizes[i];
        int capacity = rand() % 5000 + 1000;

        Item* original = new Item[n];
        for (int k = 0; k < n; k++) {
            original[k].profit = rand() % 1000 + 1;
            original[k].weight = rand() % 100 + 1;
        }

        double t1 = 0, t2 = 0, t3 = 0;

        for (int r = 0; r < runs; r++) {
            Item* temp = new Item[n];

            for (int k = 0; k < n; k++) temp[k] = original[k];
            auto start = chrono::high_resolution_clock::now();
            knapsackByWeight(temp, n, capacity);
            auto end = chrono::high_resolution_clock::now();
            t1 += chrono::duration<double, std::micro>(end - start).count();

            for (int k = 0; k < n; k++) temp[k] = original[k];
            start = chrono::high_resolution_clock::now();
            knapsackByProfit(temp, n, capacity);
            end = chrono::high_resolution_clock::now();
            t2 += chrono::duration<double, std::micro>(end - start).count();

            for (int k = 0; k < n; k++) temp[k] = original[k];
            start = chrono::high_resolution_clock::now();
            fractionalKnapsack(temp, n, capacity);
            end = chrono::high_resolution_clock::now();
            t3 += chrono::duration<double, std::micro>(end - start).count();

            delete[] temp;
        }

        cout << n
             << " | " << t1 / runs
             << " | " << t2 / runs
             << " | " << t3 / runs
             << endl;

        delete[] original;
    }

    return 0;
}