//
// Created by user on 08.10.2018.
//

#ifndef LASSOREGRESSION_MATRIX_H
#define LASSOREGRESSION_MATRIX_H


double *vectorAdd(double *first, double *second, unsigned long vectorSize);

double *vectorMultiply(double *vector, unsigned long vectorSize, double constantValue);

double *vectorMultiplyComponentWise(double *first, double *second, unsigned long vectorSize);

double vectorSum(double *vector, unsigned long vectorSize);

double norm(double *vector, unsigned long vectorSize);

#endif //LASSOREGRESSION_MATRIX_H
