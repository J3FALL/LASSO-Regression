//
// Created by user on 08.10.2018.
//

#include "LassoRegression.h"
#include "matrix.h"
#include <cmath>
#include <iostream>

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

double *LassoRegression::ro() {
    double *results = new double[numberOfFeatures];

    for (int idx = 0; idx < numberOfFeatures; idx++) {
        double *penaltyVector = vectorMultiply(feature(idx), numberOfSamples, weights[idx]);
        double *predictionDiff = vectorAdd(target, vectorMultiply(predictions(), numberOfSamples, -1), numberOfSamples);
        double *roVector = vectorScalarMultiply(predictionDiff, penaltyVector, numberOfSamples);
        double roValue = vectorSum(roVector, numberOfSamples);
        results[idx] = roValue;
    }

    return results;
}

double LassoRegression::coordinateDescentStep(int weightIdx, double alpha) {
    double *roValues = ro();
    double newWeight;


    if (weightIdx == 0) {
        newWeight = roValues[weightIdx];
    } else if (roValues[weightIdx] < (-1.0) * alpha / 2.0) {
        newWeight = roValues[weightIdx] + alpha / 2.0;
    } else if (roValues[weightIdx] > alpha / 2.0) {
        newWeight = roValues[weightIdx] - alpha / 2.0;
    } else {
        newWeight = 0.0;
    }

    return newWeight;
}

double *LassoRegression::cyclicalCoordinateDescent(double tolerance, double alpha) {
    bool condition = true;
    double maxChange;

    while (condition) {
        maxChange = 0.0;
        for (int weightIdx = 0; weightIdx < numberOfFeatures; ++weightIdx) {
            double oldWeight = weights[weightIdx];
            double newWeight = coordinateDescentStep(weightIdx, alpha);

            weights[weightIdx] = newWeight;
            double coordinateChange = fabs(oldWeight - newWeight);

            if (coordinateChange > maxChange) {
                maxChange = coordinateChange;
                std::cout << " " << maxChange << std::endl;
            }

            if (coordinateChange < tolerance) {
                condition = false;
            }
        }
    }

    return weights;
}

double **LassoRegression::featuresMatrix(std::vector<std::vector<double>> samples) {
    double **matrix = emptyMatrix();

    // TODO: add 2-form normalization
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
        weights[idx] = 0.0;
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

double *LassoRegression::feature(int featureIdx) {
    double *result = new double[numberOfSamples];

    for (int idx = 0; idx < numberOfSamples; idx++) {
        result[idx] = features[idx][featureIdx];
    }

    return result;
}