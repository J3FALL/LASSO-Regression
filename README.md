# LASSO-Regression
LASSO Regularization in C++.

This repository contains a source code of LASSO (<a href="https://www.codecogs.com/eqnedit.php?latex=L^{1}" target="_blank"><img src="https://latex.codecogs.com/png.latex?L^{1}" title="L^{1}" /></a>) regularization for simple polynomial regression implemented from scratch in C++17.

The solution was tested on the simple task of the sine function approximation by polynomials, but it could work for any regression tasks (i hope it does).

In a nutshell, LASSO regularization iteratively updates regression weights using coordinate descent algorithm taking into account the penalty for absolute values of weights. So, it minimizes the above cost function:

<a href="https://www.codecogs.com/eqnedit.php?latex=L(w)=\sum_{i=1}^{N}(y_i-\sum_{j=0}^{N}w_jx_i_j)^2&space;&plus;\lambda\sum_{j=0}^{M}\left&space;|&space;w_j&space;\right&space;|" target="_blank"><img src="https://latex.codecogs.com/png.latex?L(w)=\sum_{i=1}^{N}(y_i-\sum_{j=0}^{N}w_jx_i_j)^2&space;&plus;\lambda\sum_{j=0}^{M}\left&space;|&space;w_j&space;\right&space;|" title="L(w)=\sum_{i=1}^{N}(y_i-\sum_{j=0}^{N}w_jx_i_j)^2 +\lambda\sum_{j=0}^{M}\left | w_j \right |" /></a>

# How to use

Optimized regression weights can be obtained such way:

```c++
#include "DataSet.h"
#include "LassoRegression.h"

int main() {
    DataSet dataSet;
    LassoRegression *lasso = new LassoRegression(dataSet.sample, dataSet.target);

    double tolerance = 0.001, alpha = 0.01;
    double *weights = lasso->cyclicalCoordinateDescent(tolerance, alpha);

}
```

For your custom regression tasks you only need to change the implementation of DataSet class that encapsulates a training set. 

# Some useful references

1. Main paper about LASSO: Tibshirani R. Regression shrinkage and selection via the lasso //Journal of the Royal Statistical Society. Series B (Methodological). – 1996. – С. 267-288.
2. Introductory post about "Why do we need LASSO?": https://www.analyticsvidhya.com/blog/2016/01/complete-tutorial-ridge-lasso-regression-python/
2. All math about: "How to use coordinate descent algorithm for LASSO" is well explained: https://ru.coursera.org/lecture/ml-regression/deriving-the-lasso-coordinate-descent-update-6OLyn.
