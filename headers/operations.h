#ifndef OPERATIONS_H
#define OPERATIONS_H

// ----- manual_switches -----

double average(std::vector<double> v);
double standardDeviation(std::vector<double> v);

// ----- probability_insulators -----

double binomialCoefficient(double n1, double k1);
double bernoulliTrial(double n, double k, double p);

// ----- obeying_exponential_law -----

double obeyExponentialLaw(double timespan, double probability);

// ----- transformers_failure -----

double factorial(double n);
double poissonDistribution(double occurrences, double poisson);

// ----- constant_failure_rate -----

double failureRate(double years, double perYear);

#endif