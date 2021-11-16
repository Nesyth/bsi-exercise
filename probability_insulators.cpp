#include <iostream>
#include "headers/operations.h"

using namespace std;

long double probability_insulators() {
    int insulatorsAll = 0, insulatorsDef = 0;
    double insulatorsDefPercentage = 0;
    long double result = 0;

    cout << "How many insulators: ";
    cin >> insulatorsAll;

    cout << "How many or more out of " << insulatorsAll << " is supposed to be defective: ";
    cin >> insulatorsDef;

    cout << "Percentage of defectiveness (0.00): ";
    cin >> insulatorsDefPercentage;

    while(insulatorsDef != insulatorsAll + 1) {
        result += bernoulliTrial(insulatorsAll, insulatorsDef, insulatorsDefPercentage);
        insulatorsDef++;
    }

    return result;
}