#include <iostream>
#include "headers/operations.h"

using namespace std;

/**
 * The function is meant to calculate:
 *
 * It is known that 10% of the insulators are defective.
 *
 * What is the probability off finding three or more defective insulators in a string of five?
 */

void probability_insulators() {
    double insulatorsAll, insulatorsDef, insulatorsDefPercentage, result = 0;

    cout << "How many insulators: ";
    cin >> insulatorsAll;

    cout << "How many or more out of " << insulatorsAll << " is supposed to be defective: ";
    cin >> insulatorsDef;

    cout << "Percentage of defectiveness (0.00): ";
    cin >> insulatorsDefPercentage;

    double tempInsulatorsDef = insulatorsDef;

    while(tempInsulatorsDef != insulatorsAll + 1) {
        result += bernoulliTrial(insulatorsAll, tempInsulatorsDef, insulatorsDefPercentage);
        tempInsulatorsDef++;
    }

    cout << "\nProbability of finding " << insulatorsDef << " or more in a string of " << insulatorsAll << " equals " <<
    result << "\n\n";
}