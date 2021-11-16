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

    cout << probabilityUnits * failureRate(probabilityYears, probabilityPerYears);
}