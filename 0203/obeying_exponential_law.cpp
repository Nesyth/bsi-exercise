#include <iostream>
#include "headers/operations.h"

using namespace std;

/**
 * The function is meant to calculate:
 *
 * An equipment obeying exponential law of reliability has 97 percent probability of survival in first 100 hours of operation.
 *
 * What is the probability of its survival in first 200 hours operation?
 * What is the probability of its survival post 100 hours of operation provided it has survived for the 900 hours of the 1000 hours of useful life?
 */

void obeying_exponential_law() {
    double obeyingPercentage, obeyingTime;

    cout << "Enter the probability of survival in provided timespan (0.00): ";
    cin >> obeyingPercentage;

    cout << "Multiply the timespan by (default = 1): ";
    cin >> obeyingTime;

    cout << "\nProbability of the event happening in provided timespan is " <<
    obeyExponentialLaw(obeyingTime, obeyingPercentage) << "\n\n";
}