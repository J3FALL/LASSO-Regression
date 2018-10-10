#include <iostream>
#include "DataSet.h"
#include "LassoRegression.h"
#include "matrix.h"

using namespace std;


int main() {
    DataSet dataSet;
    LassoRegression *lasso = new LassoRegression(dataSet.sample, dataSet.target);


    double *weights = lasso->cyclicalCoordinateDescent(0.001, 0.01);


    for (int weightIdx = 0; weightIdx < lasso->numberOfFeatures; ++weightIdx) {
        std::cout << " " << weights[weightIdx];
    }

    lasso->dumpWeightsToFile();
}