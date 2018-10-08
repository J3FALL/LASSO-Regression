//
// Created by user on 08.10.2018.
//

#include "LassoRegression.h"

LassoRegression::LassoRegression(std::vector<std::vector<double>> samples) {
    this->numberOfSamples = samples.size();
    this->numberOfFeatures = samples[0].size();
    this->features = featuresMatrix(samples);
}

double **LassoRegression::featuresMatrix(std::vector<std::vector<double>> samples) {
    double **matrix = emptyMatrix();

    for (int sampleIdx = 0; sampleIdx < numberOfSamples; sampleIdx++) {
        for (int featureIdx = 0; featureIdx < numberOfFeatures; featureIdx++) {
            matrix[sampleIdx][featureIdx] = samples[sampleIdx][featureIdx];
        }
    }

    return matrix;
}

double **LassoRegression::emptyMatrix() {
    double **result = new double *[numberOfSamples];
    for (int sampleIdx = 0; sampleIdx < numberOfSamples; sampleIdx++) {
        result[sampleIdx] = new double[numberOfFeatures];
    }

    return result;
}