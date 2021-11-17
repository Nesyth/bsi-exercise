#include <iostream>
#include <vector>
#include "headers/operations.h"

using namespace std;

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