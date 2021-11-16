#include <iostream>
#include "headers/operations.h"

using namespace std;

void transformers_failure() {
    double transformerFailureRate, transformerOccurrences, transformerMultiply;

    cout << "What's the average probability of the event happening: ";
    cin >> transformerFailureRate;

    cout << "Time multiplied (default = 1): ";
    cin >> transformerMultiply;

    cout << "For how many occurrences you want to calculate the probability: ";
    cin >> transformerOccurrences;

    cout << "The probability is " <<
    poissonDistribution(transformerOccurrences, transformerMultiply *  transformerFailureRate) << "\n\n";
}