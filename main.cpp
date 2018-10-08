#include <iostream>
#include "DataSet.h"
#include "LassoRegression.h"
#include "matrix.h"

using namespace std;


int main() {
    DataSet dataSet;
    LassoRegression *lasso = new LassoRegression(dataSet.sample, dataSet.target);


    double *weights = lasso->cyclicalCoordinateDescent(1.0, 1e-3);

    for (int idx = 0; idx < lasso->numberOfFeatures; ++idx) {
        std::cout << ' ' << weights[idx];
    }
    return 0;
}