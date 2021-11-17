#include <cmath>
#include <vector>

// ----- manual_switches -----

double average(std::vector<double> v) {
    int result = 0;

    for(int i = 0; i < v.size(); i++) {
        result += v[i];
    }

    return result/v.size();
}

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

double binomialCoefficient(double n1, double k1) {
    if (k1 == 0 || k1 == n1)
        return 1;

    return binomialCoefficient(n1 - 1, k1 - 1) + binomialCoefficient(n1 - 1, k1);
}

double bernoulliTrial(double n, double k, double p) {
    return binomialCoefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
}

// ----- obeying_exponential_law -----

double obeyExponentialLaw(double timespan, double probability) {
    double j = probability;
    for(int i = 0; i < timespan - 1; i++) {
        j *= probability;
    }
    return j;
}

// ----- transformers_failure -----

double factorial(double n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double poissonDistribution(double occurrences, double poissonProbability) {
    if(occurrences == 0) occurrences = 1;
    return (pow(exp(1.0), -poissonProbability) * pow(poissonProbability, occurrences)) / factorial(occurrences);
}

// ----- constant_failure_rate -----

double failureRate(double years, double perYear) {
    double eConstant = exp(1.0);
    return pow(eConstant, -perYear * years);
}