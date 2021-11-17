#include <iostream>
#include "headers/operations.h"

using namespace std;

void obeying_exponential_law() {
    double obeyingPercentage, obeyingTime;

    cout << "Enter the probability of survival in provided timespan (0.00): ";
    cin >> obeyingPercentage;

    cout << "Multiply the timespan by (default = 1): ";
    cin >> obeyingTime;

    cout << "\nProbability of the event happening in provided timespan is " <<
    obeyExponentialLaw(obeyingTime, obeyingPercentage) << "\n\n";
}