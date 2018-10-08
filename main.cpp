#include <iostream>
#include "DataSet.h"
#include "LassoRegression.h"
#include "matrix.h"

using namespace std;


int main() {
    DataSet dataSet;
    LassoRegression *lasso = new LassoRegression(dataSet.sample, dataSet.target);

    for (int sampleIdx = 0; sampleIdx < lasso->numberOfSamples; sampleIdx++) {
        for (int featureIdx = 0; featureIdx < lasso->numberOfFeatures; featureIdx++) {
            std::cout << ' ' << lasso->features[sampleIdx][featureIdx];
        }
        std::cout << std::endl;
    }

    for (int idx = 0; idx < lasso->numberOfFeatures; idx++) {
        std::cout << ' ' << lasso->weights[idx];
    }


    double *predictions = lasso->predictions();

    for (int idx = 0; idx < lasso->numberOfSamples; idx++) {
        std::cout << predictions[idx] << std::endl;
    }


    for (int idx = 0; idx < lasso->numberOfSamples; idx++) {
        std::cout << " " << lasso->target[idx];
    }
    std::cout << std::endl;


    double *ro = lasso->ro();

    for (int idx = 0; idx < lasso->numberOfFeatures; idx++) {
        std::cout << ' ' << ro[idx];
    }
    std::cout << std::endl;

    return 0;
}