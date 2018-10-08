//
// Created by user on 08.10.2018.
//

#include "LassoRegression.h"

LassoRegression::LassoRegression(std::vector<std::vector<double>> samples, std::vector<double> target) {
    this->numberOfSamples = samples.size();
    this->numberOfFeatures = samples[0].size();
    this->features = featuresMatrix(samples);
    this->weights = initialWeights();
    this->target = targetAsArray(target);
}

double *LassoRegression::predictions() {
    double *result = new double[numberOfSamples];

    for (int sampleIdx = 0; sampleIdx < numberOfSamples; sampleIdx++) {
        double prediction = 0.0;
        for (int featureIdx = 0; featureIdx < numberOfFeatures; featureIdx++) {
            prediction += features[sampleIdx][featureIdx] * weights[featureIdx];
        }
        result[sampleIdx] = prediction;
    }

    return result;
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

double *LassoRegression::initialWeights() {
    double *weights = new double[numberOfFeatures];

    for (int idx = 0; idx < numberOfFeatures; idx++) {
        weights[idx] = 1.0;
    }

    return weights;
}

double *LassoRegression::targetAsArray(std::vector<double> target) {
    double *result = new double[target.size()];

    for (int targetIdx = 0; targetIdx < target.size(); targetIdx++) {
        result[targetIdx] = target[targetIdx];
    }

    return result;
}