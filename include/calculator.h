#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>

// Basic arithmetic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);

// Calculator function prototype
bool calculator(double num1, char operator, double num2, double *result);

#endif
