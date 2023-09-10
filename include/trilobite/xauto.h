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

/**
 * @brief An enumeration defining the maximum number of features for models.
 *
 * This enumeration specifies the maximum number of features that can be accommodated
 * by machine learning models in the context of this code.
 */
enum {
    XAUTO_MAX_FEATURES = 100
}; // end enum

/**
 * @brief Structure defining a Logistic Regression model.
 *
 * This structure represents a Logistic Regression model and includes coefficients for features,
 * an intercept, and the number of features used in the model.
 */
typedef struct {
    double coefficients[XAUTO_MAX_FEATURES];
    double intercept;
    int num_features;
} LogisticRegressionModel;

/**
 * @brief Structure defining a Linear Regression model.
 *
 * This structure represents a Linear Regression model and includes the slope and intercept
 * parameters.
 */
typedef struct {
    double slope;
    double intercept;
} LinearRegressionModel;

/**
 * @brief Structure defining a Gaussian Naive Bayes model.
 *
 * This structure represents a Gaussian Naive Bayes model for binary classification.
 * It includes class probabilities, mean values for each class, and variances for each class.
 */
typedef struct {
    double class_probabilities[2]; // Assuming binary classification
    double mean[2];               // Mean for each class
    double variance[2];           // Variance for each class
} GaussianNaiveBayesModel;

/**
 * @brief Trains a Logistic Regression model.
 *
 * This function trains a Logistic Regression model using the provided input data, labels,
 * learning rate, and the number of epochs for training.
 *
 * @param model         Pointer to the Logistic Regression model to be trained.
 * @param input         Pointer to the input data.
 * @param labels        Pointer to the labels corresponding to the input data.
 * @param num_samples   Number of data samples in the input.
 * @param learning_rate Learning rate for training.
 * @param num_epochs    Number of training epochs.
 */
XTEST_API void xauto_train_logistic_regression(LogisticRegressionModel* model, const double* input, const int* labels, int num_samples, double learning_rate, int num_epochs);

/**
 * @brief Trains a Linear Regression model.
 *
 * This function trains a Linear Regression model using the provided input (x) and output (y) data.
 *
 * @param model         Pointer to the Linear Regression model to be trained.
 * @param x             Pointer to the input data (features).
 * @param y             Pointer to the output data (target values).
 * @param num_samples   Number of data samples.
 */
XTEST_API void xauto_train_linear_regression(LinearRegressionModel* model, const double* x, const double* y, int num_samples);

/**
 * @brief Trains a Gaussian Naive Bayes model.
 *
 * This function trains a Gaussian Naive Bayes model using the provided features, labels, the number of data samples,
 * and the number of features.
 *
 * @param model         Pointer to the Gaussian Naive Bayes model to be trained.
 * @param features      Pointer to the input features.
 * @param labels        Pointer to the labels corresponding to the features.
 * @param num_samples   Number of data samples.
 * @param num_features  Number of features in the input.
 */
XTEST_API void xauto_train_gaussian_naive_bayes(GaussianNaiveBayesModel* model, const double* features, const int* labels, int num_samples, int num_features);

/**
 * @brief Predicts using a Gaussian Naive Bayes model.
 *
 * This function predicts the label using a trained Gaussian Naive Bayes model for a given feature.
 *
 * @param model   Pointer to the trained Gaussian Naive Bayes model.
 * @param feature The feature for which the prediction is made.
 *
 * @return        The predicted label.
 */
XTEST_API int xauto_predict_gaussian_naive_bayes(const GaussianNaiveBayesModel* model, double feature);

#ifdef __cplusplus
}
#endif

#endif
