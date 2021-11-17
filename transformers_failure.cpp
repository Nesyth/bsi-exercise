#include <iostream>
#include "headers/operations.h"

using namespace std;

/**
 * The function is meant to calculate:
 *
 * The failure of power transformers is assumed to follow a Poisson probability distribution. Suppose on average, a transformer fails once every 10 years.
 *
 * What is the probability that it will not fail in the next 12 months?
 * That it will fail once in the next 24 months?
 */

void transformers_failure() {
    double transformerFailureRate, transformerOccurrences, transformerMultiply;

    cout << "What's the average probability of the event happening (0.00): ";
    cin >> transformerFailureRate;

    cout << "Time multiplied (default = 1): ";
    cin >> transformerMultiply;

    cout << "For how many occurrences you want to calculate the probability: ";
    cin >> transformerOccurrences;

    cout << "\nThe probability is " <<
    poissonDistribution(transformerOccurrences, transformerMultiply *  transformerFailureRate) << "\n\n";
}