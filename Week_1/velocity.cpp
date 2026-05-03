// =====================================
// Week-1 ADA Lab Codes
// Algorithm Design and Analysis
// =====================================
#include <iostream>
using namespace std;

// Function to calculate number of bounces
int countBounces(double velocity) 
{
    // base case: if velocity is too small, no more bounces
    if (velocity < 1.0) 
        return 0;

    // reduce velocity after each bounce (loss of energy)
    double reducedVelocity = velocity * 0.575;

    return 1 + countBounces(reducedVelocity);
}

int main() 
{
    double initialVelocity;

    cout << "Enter initial velocity: ";
    cin >> initialVelocity;

    int result = countBounces(initialVelocity);

    cout << "Total number of dips: " << result;

    return 0;
}