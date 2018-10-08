#include <iostream>
#include "DataSet.h"
#include "LassoRegression.h"

using namespace std;


int main() {
    DataSet dataSet;
    LassoRegression *lasso = new LassoRegression(dataSet.sample);

    for (int sampleIdx = 0; sampleIdx < lasso->numberOfSamples; sampleIdx++) {
        for (int featureIdx = 0; featureIdx < lasso->numberOfFeatures; featureIdx++) {
            std::cout << ' ' << lasso->features[sampleIdx][featureIdx];
        }
        std::cout << std::endl;
    }
    return 0;
}