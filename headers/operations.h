#ifndef OPERATIONS_H
#define OPERATIONS_H

// ----- 1 -----

float average(std::vector<float> v);
float standardDeviation(std::vector<float> v);

// ----- 2 -----

long double binomialCoefficient(long double n1, long double k1);
long double bernoulliTrial(long double n, long double k, long double p);

// ----- 5 -----

double failureRate(double years, double perYear);

#endif