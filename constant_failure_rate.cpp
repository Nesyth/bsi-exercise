#include <iostream>
#include "headers/operations.h"

using namespace std;

/**
 * The function is meant to calculate:
 *
 * One thousand new OCRs are put in service. They have a constant failure rate of 0.05 per year.
 *
 * How many units of the original 1000 will still be in service after 5 years?
 * How many of the original will fail in Year 5?
 */

void constant_failure_rate() {
    double probabilityUnits, probabilityYears, probabilityPerYears;

    cout << "How many units: ";
    cin >> probabilityUnits;

    cout << "Failure rate per year (0.00): ";
    cin >> probabilityPerYears;

    cout << "How many years: ";
    cin >> probabilityYears;

    double originalRate = failureRate(probabilityYears, probabilityPerYears) * probabilityUnits;
    double lowerRate = failureRate(probabilityYears - 1, probabilityPerYears) * probabilityUnits - originalRate;

    cout << "\nNo. of units in service after " << probabilityYears << " years is " << originalRate <<
    "\nNo. of units that failed in Year " << probabilityYears << " is " << lowerRate << "\n\n";
}