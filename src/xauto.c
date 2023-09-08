/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xauto.h"

//
// EXTRA MATH FUNCTIONS
//
double xauto_exp_with_squaring(double x, int n) {
    if (n == 0) {
        return 1.0;
    } // end if

    if (n % 2 == 0) {
        double half = xauto_exp_with_squaring(x, n / 2);
        return half * half;
    } else {
        double half = xauto_exp_with_squaring(x, (n - 1) / 2);
        return half * half * x;
    } // end if else
} // end of func

// Sigmoid function
double xauto_sigmoid(double x) {
    return 1.0 / (1.0 + xauto_exp_with_squaring(-x, 10));
} // end of func

//
// AI TRAINING
//

// Training function for Logistic Regression
void xauto_train_logistic_regression(LogisticRegressionModel* model, const double* input, const int* labels, int num_samples, double learning_rate, int num_epochs) {
    // Initialize model coefficients and intercept to zeros
    for (int i = 0; i < model->num_features; ++i) {
        model->coefficients[i] = 0.0;
    } // end for
    model->intercept = 0.0;

    // Perform gradient descent
    for (int epoch = 0; epoch < num_epochs; ++epoch) {
        for (int sample = 0; sample < num_samples; ++sample) {
            double prediction = model->intercept;
            for (int feature = 0; feature < model->num_features; ++feature) {
                prediction += model->coefficients[feature] * input[sample * model->num_features + feature];
            } // end for
            double probability = xauto_sigmoid(prediction);

            // Update coefficients and intercept using gradient descent
            double error = labels[sample] - probability;
            model->intercept += learning_rate * error;
            for (int feature = 0; feature < model->num_features; ++feature) {
                model->coefficients[feature] += learning_rate * error * input[sample * model->num_features + feature];
            } // end for
        } // end for
    } // end for
} // end of func

// Training function for Linear Regression
void xauto_train_linear_regression(LinearRegressionModel* model, const double* x, const double* y, int num_samples) {
    double sum_x = 0.0;
    double sum_y = 0.0;
    double sum_xy = 0.0;
    double sum_x_squared = 0.0;

    for (int i = 0; i < num_samples; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    } // end for

    // Calculate the slope (gradient) and intercept (bias) of the line
    double mean_x = sum_x / num_samples;
    double mean_y = sum_y / num_samples;
    double slope = (sum_xy - num_samples * mean_x * mean_y) / (sum_x_squared - num_samples * mean_x * mean_x);
    double intercept = mean_y - slope * mean_x;

    model->slope = slope;
    model->intercept = intercept;
} // end of func
