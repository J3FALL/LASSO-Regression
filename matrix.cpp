//
// Created by user on 08.10.2018.
//

#include "matrix.h"
#include <cmath>
#include <iostream>

double *vectorAdd(double *first, double *second, unsigned long vectorSize) {
    double *result = new double[vectorSize];

    for (int idx = 0; idx < vectorSize; idx++) {
        result[idx] = first[idx] + second[idx];
    }

    return result;
}

double *vectorMultiply(double *vector, unsigned long vectorSize, double constantValue) {
    double *result = new double[vectorSize];
    for (int idx = 0; idx < vectorSize; idx++) {
        result[idx] = vector[idx] * constantValue;
    }

    return result;
}

double *vectorMultiplyComponentWise(double *first, double *second, unsigned long vectorSize) {
    double *result = new double[vectorSize];

    for (int idx = 0; idx < vectorSize; idx++) {
        result[idx] = first[idx] * second[idx];
    }

    return result;
}

double vectorSum(double *vector, unsigned long vectorSize) {
    double result = 0.0;

    for (int idx = 0; idx < vectorSize; idx++) {
        result += vector[idx];
    }

    return result;
}

double norm(double *vector, unsigned long vectorSize) {
    double result = 0.0;
    for (int idx = 0; idx < vectorSize; ++idx) {
        result += pow(vector[idx], 2);
    }

    return sqrt(result);
}