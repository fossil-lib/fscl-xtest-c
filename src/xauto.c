/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xauto.h"

// Sigmoid function
double xauto_sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
} // end of func

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
