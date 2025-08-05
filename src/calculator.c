#include "../include/calculator.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// Basic arithmetic operations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}


double power(double base, double exponent) {
    return pow(base,exponent);
}

/**
 * Performs the calculation based on the given operator and operands.
 *
 * Supports addition (+), subtraction (-), multiplication (*),
 * division (/), and exponentiation (^).
 *
 * @param num1 First operand.
 * @param operator Operator character (+, -, *, /, ^).
 * @param num2 Second operand.
 * @param result Pointer to double where the calculation result is stored.
 * @return true if calculation was successful; false if an error occurred
 *         (e.g., division by zero or unsupported operator).
 */
bool calculator(double num1, char operator, double num2, double *result){
    switch (operator){
        case '+':
            *result = add(num1, num2);
            return true;
        case '-':
            *result = subtract(num1, num2);
            return true;
        case '*':
            *result = multiply(num1, num2);
            return true;
        case '/':
            if (num2 != 0){
                *result = divide(num1, num2);
                return true;
            } else {
                printf("\033[31mError: Division by zero is not allowed.\033[31m\n");
                return false;
            }
        case '^':
            *result = power(num1, num2);
            return true;
        default:
            printf("\033[31mError: Unsupported operator '%c'.\033[31m\n", operator);
            return false;
    }
}