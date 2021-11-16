#include <cmath>
#include <vector>

// ----- 1 -----

float average(std::vector<double> v) {
    int result = 0;

    for(int i = 0; i < v.size(); i++) {
        result += v[i];
    }

    return result/v.size();
}

float standardDeviation(std::vector<double> v) {
    float sum = 0.0, mean, standardDeviation = 0.0;
    int i;

    for(i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    mean = sum / v.size();

    for(i = 0; i < v.size(); ++i) {
        standardDeviation += pow(v[i] - mean, 2);
    }

    return sqrt(standardDeviation / v.size());
}

// ----- 2 -----

double binomialCoefficient(double n1, double k1) {
    if (k1 == 0 || k1 == n1)
        return 1;

    return binomialCoefficient(n1 - 1, k1 - 1) + binomialCoefficient(n1 - 1, k1);
}

double bernoulliTrial(double n, double k, double p) {
    return binomialCoefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
}

// ----- 5 -----

double failureRate(double years, double perYear) {
    double eConstant = exp(1.0);
    return pow(eConstant, -perYear * years);
}