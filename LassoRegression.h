//
// Created by user on 08.10.2018.
//

#ifndef LASSOREGRESSION_LASSOREGRESSION_H
#define LASSOREGRESSION_LASSOREGRESSION_H

#include <vector>

class LassoRegression {
public:
    double **features;
    double *weights;
    double *target;

    unsigned long numberOfSamples;

    unsigned long numberOfFeatures;

    LassoRegression(std::vector<std::vector<double>> samples, std::vector<double> target);

    double *predictions();

private:

    double **featuresMatrix(std::vector<std::vector<double>> samples);

    double **emptyMatrix();

    double *initialWeights();

    double *targetAsArray(std::vector<double> target);
};


#endif //LASSOREGRESSION_LASSOREGRESSION_H
