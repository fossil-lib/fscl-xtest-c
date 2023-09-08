/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XAUTO_H
#define TRILOBITE_XAUTO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

// Define the maximum number of features your code can handle
enum {
    XAUTO_MAX_FEATURES = 100
}; // end enum

// Define your Logistic Regression model
typedef struct {
    double coefficients[XAUTO_MAX_FEATURES];
    double intercept;
    int num_features;
} LogisticRegressionModel;

// Define your Linear Regression model
typedef struct {
    double slope;
    double intercept;
} LinearRegressionModel;

// Training function for Logistic Regression
TRILOBITE_XTEST_API void xauto_train_logistic_regression(LogisticRegressionModel* model, const double* input, const int* labels, int num_samples, double learning_rate, int num_epochs);
TRILOBITE_XTEST_API void xauto_train_linear_regression(LinearRegressionModel* model, const double* x, const double* y, int num_samples);

#ifdef __cplusplus
}
#endif

#endif
