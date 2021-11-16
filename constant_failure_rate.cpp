#include <iostream>
#include "headers/operations.h"

using namespace std;

void constant_failure_rate() {
    double probabilityUnits, probabilityYears, probabilityPerYears;

    cout << "How many units: ";
    cin >> probabilityUnits;

    cout << "How many years: ";
    cin >> probabilityYears;

    cout << "How many failures per year: ";
    cin >> probabilityPerYears;

    double originalRate = failureRate(probabilityYears, probabilityPerYears) * probabilityUnits;
    double lowerRate = failureRate(probabilityYears - 1, probabilityPerYears) * probabilityUnits - originalRate;

    cout << "No. of units in service after " << probabilityYears << " years is " << originalRate <<
    "\nNo. of units that failed in Year " << probabilityYears << " is " << lowerRate;
}