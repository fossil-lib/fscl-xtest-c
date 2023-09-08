/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xauto.h"
#include <math.h>

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

// Taylor series expansion for the exponential term
double taylor_exp(double x, int num_terms) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i < num_terms; ++i) {
        term *= x / i;
        result += term;
    } // end for

    return result;
} // end of func

// Approximation of square root using the Newton-Raphson method
double approximate_sqrt(double x) {
    if (x == 0.0) {
        return 0.0;
    } // end if

    double guess = x; // Initial guess
    double epsilon = 1e-6; // Tolerance for convergence

    while (1) {
        double new_guess = 0.5 * (guess + x / guess);
        if (fabs(new_guess - guess) < epsilon) {
            return new_guess;
        } // end if
        guess = new_guess;
    } // end while
} // end of func

// Approximated Gaussian probability density function without exp
double approximate_gaussian_pdf(double x, double mean, double variance) {
    double pi = 3.14159265358979323846;
    double exponent = -((x - mean) * (x - mean)) / (2 * variance);
    double exponential_term = taylor_exp(exponent, 10); // Adjust the number of terms as needed
    return (1.0 / (approximate_sqrt(2 * pi * variance))) * exponential_term;
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

// Training function for Gaussian Naive Bayes
void xauto_train_gaussian_naive_bayes(GaussianNaiveBayesModel* model, const double* features, const int* labels, int num_samples, int num_features) {
    // Initialize class probabilities, means, and variances
    model->class_probabilities[0] = 0.0;
    model->class_probabilities[1] = 0.0;
    model->mean[0] = 0.0;
    model->mean[1] = 0.0;
    model->variance[0] = 0.0;
    model->variance[1] = 0.0;

    int count_class_0 = 0;
    int count_class_1 = 0;

    // Calculate class probabilities, means, and variances
    for (int i = 0; i < num_samples; ++i) {
        if (labels[i] == 0) {
            count_class_0++;
            model->mean[0] += features[i];
        } else {
            count_class_1++;
            model->mean[1] += features[i];
        } // end if esle
    } // end for

    if (count_class_0 > 0) {
        model->class_probabilities[0] = (double)count_class_0 / num_samples;
        model->mean[0] /= count_class_0;
    } // end if

    if (count_class_1 > 0) {
        model->class_probabilities[1] = (double)count_class_1 / num_samples;
        model->mean[1] /= count_class_1;
    } // end if

    for (int i = 0; i < num_samples; ++i) {
        int class_label = labels[i];
        double diff = features[i] - model->mean[class_label];
        model->variance[class_label] += diff * diff;
    } // end for

    if (count_class_0 > 0) {
        model->variance[0] /= count_class_0;
    } // end if

    if (count_class_1 > 0) {
        model->variance[1] /= count_class_1;
    } // end if
} // end of func

// Prediction function for Gaussian Naive Bayes using the approximate Gaussian PDF
int xauto_predict_gaussian_naive_bayes(const GaussianNaiveBayesModel* model, double feature) {
    double likelihood_class_0 = approximate_gaussian_pdf(feature, model->mean[0], model->variance[0]);
    double likelihood_class_1 = approximate_gaussian_pdf(feature, model->mean[1], model->variance[1]);

    double posterior_class_0 = model->class_probabilities[0] * likelihood_class_0;
    double posterior_class_1 = model->class_probabilities[1] * likelihood_class_1;

    return (posterior_class_0 > posterior_class_1) ? 0 : 1;
} // end of func
