#include <cmath>
#include <vector>

// ----- manual_switches -----

/**
 * Calculates the average of values put in v
 *
 * @param v stores all number inputs
 * @return calculated average
 */

double average(std::vector<double> v) {
    int result = 0;

    for(int i = 0; i < v.size(); i++) {
        result += v[i];
    }

    return result/v.size();
}

/**
 * Calculates the standard deviation of values put in v
 *
 * @param v stores all number inputs
 * @return calculated standard deviation
 */

double standardDeviation(std::vector<double> v) {
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;

    for(i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    mean = sum / v.size();

    for(i = 0; i < v.size(); i++) {
        standardDeviation += pow(v[i] - mean, 2);
    }

    return sqrt(standardDeviation / v.size());
}

// ----- probability_insulators -----

/**
 * Calculates binomial coefficient
 *
 * @param n1 upper value
 * @param k1 lower value
 * @return calculated binomial coefficient
 */

double binomialCoefficient(double n1, double k1) {
    if (k1 == 0 || k1 == n1)
        return 1;

    return binomialCoefficient(n1 - 1, k1 - 1) + binomialCoefficient(n1 - 1, k1);
}

/**
 * Calculates the probability based on Bernoulli trial
 *
 * @param n upper value of binomial coefficient
 * @param k lower value of binomial coefficient
 * @param p probability of success
 * @return calculated probability
 */

double bernoulliTrial(double n, double k, double p) {
    return binomialCoefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
}

// ----- obeying_exponential_law -----

/**
 * Calculates the probability ignoring exponential law
 *
 * @param timespan multiplied timespan
 * @param probability probability of success
 * @return j calculated probability
 */

double obeyExponentialLaw(double timespan, double probability) {
    double j = probability;
    for(int i = 0; i < timespan - 1; i++) {
        j *= probability;
    }
    return j;
}

// ----- transformers_failure -----

/**
 * Calculates factorial
 *
 * @param n number to calculate factorial of
 * @return calculated factorial
 */

double factorial(double n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

/**
 * Calculates the Poisson distribution
 *
 * @param occurrences desired occurrences to have probability calculated
 * @param poissonProbability average probability of the event
 * @return calculated probability
 */

double poissonDistribution(double occurrences, double poissonProbability) {
    if(occurrences == 0) occurrences = 1;
    return (pow(exp(1.0), -poissonProbability) * pow(poissonProbability, occurrences)) / factorial(occurrences);
}

// ----- constant_failure_rate -----

/**
 * Calculates constant failure rate
 *
 * @param years desired years to be calculated
 * @param perYear failure rate per year (0.00)
 * @return failure rate based on given params
 */

double failureRate(double years, double perYear) {
    double eConstant = exp(1.0);
    return pow(eConstant, -perYear * years);
}