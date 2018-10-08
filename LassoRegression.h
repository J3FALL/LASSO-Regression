//
// Created by user on 08.10.2018.
//

#ifndef LASSOREGRESSION_LASSOREGRESSION_H
#define LASSOREGRESSION_LASSOREGRESSION_H

#include <vector>

class LassoRegression {
public:
    double **features;

    unsigned long numberOfSamples;

    unsigned long numberOfFeatures;

    LassoRegression(std::vector<std::vector<double>> samples);

private:

    double **featuresMatrix(std::vector<std::vector<double>> samples);

    double **emptyMatrix();
};


#endif //LASSOREGRESSION_LASSOREGRESSION_H
