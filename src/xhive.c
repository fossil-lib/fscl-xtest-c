/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xhive.h"

//
// EXTRA MATH FUNCTIONS
//

/**
 * @brief Calculates the exponential of a number using squaring and recursion.
 *
 * This function calculates the exponential term 'e^x' using a recursive approach that leverages squaring.
 * It computes 'e^x' with the specified number of recursive divisions and squaring operations.
 *
 * @param x The input value for the exponential term.
 * @param n The number of recursive divisions and squaring operations.
 *
 * @return The approximate value of 'e^x' using squaring and recursion.
 */
double xhive_exp_with_squaring(double x, int n) {
    if (n == 0) {
        return 1.0;
    } // end if

    if (n % 2 == 0) {
        double half = xhive_exp_with_squaring(x, n / 2);
        return half * half;
    } else {
        double half = xhive_exp_with_squaring(x, (n - 1) / 2);
        return half * half * x;
    } // end if else
} // end of func

/**
 * @brief Calculates the sigmoid function.
 *
 * This function computes the sigmoid function for a given value 'x'.
 *
 * @param x The input value.
 *
 * @return The sigmoid value for the input 'x'.
 */
double xhive_sigmoid(double x) {
    return 1.0 / (1.0 + xhive_exp_with_squaring(-x, 10));
} // end of func

/**
 * @brief Calculates the exponential term using a Taylor series expansion.
 *
 * This function approximates the exponential term 'e^x' using a Taylor series expansion with a specified number
 * of terms.
 *
 * @param x           The input value for the exponential term.
 * @param num_terms   The number of terms to use in the Taylor series expansion.
 *
 * @return An approximation of 'e^x' using the Taylor series expansion.
 */
double taylor_exp(double x, int num_terms) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i < num_terms; ++i) {
        term *= x / i;
        result += term;
    } // end for

    return result;
} // end of func

/**
 * @brief Approximates the square root of a number using the Newton-Raphson method.
 *
 * This function approximates the square root of a given number 'x' using the Newton-Raphson method.
 * It iteratively refines the estimate until it converges within a specified tolerance.
 *
 * @param x The number for which the square root is approximated.
 *
 * @return The approximate square root of 'x'.
 */
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

/**
 * @brief Approximates the Gaussian Probability Density Function (PDF).
 *
 * This function approximates the Gaussian PDF for a given value 'x' with the provided mean and variance.
 * It uses an approximation method to compute the PDF.
 *
 * @param x        The value for which the PDF is calculated.
 * @param mean     The mean (average) of the Gaussian distribution.
 * @param variance The variance of the Gaussian distribution.
 *
 * @return The approximate PDF value at 'x' given the mean and variance.
 */
double approximate_gaussian_pdf(double x, double mean, double variance) {
    double pi = 3.14159265358979323846;
    double exponent = -((x - mean) * (x - mean)) / (2 * variance);
    double exponential_term = taylor_exp(exponent, 10); // Adjust the number of terms as needed
    return (1.0 / (approximate_sqrt(2 * pi * variance))) * exponential_term;
} // end of func

//
// AI TRAINING
//

/**
 * @brief Trains a Logistic Regression model using gradient descent.
 *
 * This function trains a Logistic Regression model using the provided input, labels, learning rate, and the number
 * of epochs for training. It initializes model coefficients and intercept to zeros and then performs gradient descent
 * to update these parameters to fit the data.
 *
 * @param model         Pointer to the Logistic Regression model to be trained.
 * @param input         Pointer to the input data.
 * @param labels        Pointer to the labels corresponding to the input data.
 * @param num_samples   Number of data samples.
 * @param learning_rate Learning rate for gradient descent.
 * @param num_epochs    Number of training epochs.
 */
void xhive_train_logistic_regression(LogisticRegressionModel* model, const double* input, const int* labels, int num_samples, double learning_rate, int num_epochs) {
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
            double probability = xhive_sigmoid(prediction);

            // Update coefficients and intercept using gradient descent
            double error = labels[sample] - probability;
            model->intercept += learning_rate * error;
            for (int feature = 0; feature < model->num_features; ++feature) {
                model->coefficients[feature] += learning_rate * error * input[sample * model->num_features + feature];
            } // end for
        } // end for
    } // end for
} // end of func

/**
 * @brief Trains a Linear Regression model.
 *
 * This function trains a Linear Regression model using the provided input (x) and output (y) data.
 * It calculates the slope and intercept of the linear regression line that best fits the data points.
 *
 * @param model         Pointer to the Linear Regression model to be trained.
 * @param x             Pointer to the input data (features).
 * @param y             Pointer to the output data (target values).
 * @param num_samples   Number of data samples.
 */
void xhive_train_linear_regression(LinearRegressionModel* model, const double* x, const double* y, int num_samples) {
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

/**
 * @brief Trains a Gaussian Naive Bayes model.
 *
 * This function trains a Gaussian Naive Bayes model using the provided features and labels. It calculates
 * class probabilities, means, and variances for two classes (assuming binary classification).
 *
 * @param model         Pointer to the Gaussian Naive Bayes model to be trained.
 * @param features      Pointer to the input features.
 * @param labels        Pointer to the labels corresponding to the features.
 * @param num_samples   Number of data samples.
 * @param num_features  Number of features in the input.
 */
void xhive_train_gaussian_naive_bayes(GaussianNaiveBayesModel* model, const double* features, const int* labels, int num_samples, int num_features) {
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

/**
 * @brief Predicts using a trained Gaussian Naive Bayes model.
 *
 * This function predicts the class label (0 or 1) using a trained Gaussian Naive Bayes model for a given feature.
 *
 * @param model    Pointer to the trained Gaussian Naive Bayes model.
 * @param feature  The feature for which the prediction is made.
 *
 * @return        The predicted class label (0 or 1).
 */
int xhive_predict_gaussian_naive_bayes(const GaussianNaiveBayesModel* model, double feature) {
    double likelihood_class_0 = approximate_gaussian_pdf(feature, model->mean[0], model->variance[0]);
    double likelihood_class_1 = approximate_gaussian_pdf(feature, model->mean[1], model->variance[1]);

    double posterior_class_0 = model->class_probabilities[0] * likelihood_class_0;
    double posterior_class_1 = model->class_probabilities[1] * likelihood_class_1;

    return (posterior_class_0 > posterior_class_1) ? 0 : 1;
} // end of func
