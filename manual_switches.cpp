#include <iostream>
#include <vector>
#include "headers/operations.h"

using namespace std;

/**
 * The function is meant to calculate:
 *
 * The following table shows the time in years between maintenance actions to 50manual switches for a given utility.
 * (1 1 1 2 2 2 3 3 3 3 3 4 4 4 4 4 4 4 4 5 5 5 5 5 5 5 5 6 6 6 6 6 6 6 6 6 6 6 8 8 8 8 9 9 9 11 15 15 18 20)
 *
 * What is the average number of years between maintenance actions of manual switches?
 * What is the standard deviation?
 */

void manual_switches() {
    double input;
    vector<double> v;

    cout << "Input all years between maintenance actions: ";
    while(cin >> input) {
        v.push_back(input);
        if (cin.get() == '\n')
            break;
    }

    cout << "\nAverage between maintenance actions is " << average(v) << " years, while standard deviations equals " <<
    standardDeviation(v) << "\n\n";
}