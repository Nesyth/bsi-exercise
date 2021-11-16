#ifndef OPERATIONS_H
#define OPERATIONS_H

// ----- 1 -----

float average(std::vector<double> v);
float standardDeviation(std::vector<double> v);

// ----- 2 -----

double binomialCoefficient(double n1, double k1);
double bernoulliTrial(double n, double k, double p);

// ----- 5 -----

double failureRate(double years, double perYear);

#endif