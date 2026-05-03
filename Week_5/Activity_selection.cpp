#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Task {
    int id;
    int startTime;
    int endTime;
};

// Comparator 1: sort by finishing time
bool byFinish(const Task &a, const Task &b) {
    return a.endTime < b.endTime;
}

// Comparator 2: sort by duration
bool byLength(const Task &a, const Task &b) {
    return (a.endTime - a.startTime) < (b.endTime - b.startTime);
}

// Function to perform activity selection
void activitySelection(vector<Task> tasks, bool useFinishTime) {

    if (useFinishTime) {
        sort(tasks.begin(), tasks.end(), byFinish);
        cout << "Strategy: Finish Time Priority\n";
    } else {
        sort(tasks.begin(), tasks.end(), byLength);
        cout << "Strategy: Shortest Duration First\n";
    }

    int selectedCount = 0;
    int lastFinish = -1;

    cout << "Chosen Activities: ";

    for (const auto &t : tasks) {
        if (t.startTime >= lastFinish) {
            cout << "A" << t.id << " ";
            lastFinish = t.endTime;
            selectedCount++;
        }
    }

    cout << "\nTotal Activities Selected: " << selectedCount << "\n\n";
}

int main() {

    vector<Task> activities = {
        {1, 0, 4}, {2, 3, 5}, {3, 4, 8},
        {4, 5, 9}, {5, 8, 12}, {6, 11, 13},
        {7, 12, 16}, {8, 15, 17}, {9, 16, 20}, {10, 1, 19}
    };

    activitySelection(activities, true);   // Finish time
    activitySelection(activities, false);  // Duration

    return 0;
}