#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include "../include/calculator.h"

/**
 * The main entry point of the calculator program.
 *
 * Accepts command-line arguments in the format: program num1 operator num2
 * Example: ./calculator 5 + 3
 *
 * @param argc Number of command-line arguments
 * @param argv Array of command-line argument strings
 * @return Exit status code (0 on success, 1 on error)
 */
int main(int argc, char *argv[]) {
    // Check if correct number of arguments provided
    if (argc != 4) {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        printf("Example: %s 5 + 3\n", argv[0]);
        printf("Supported operators: +, -, *, /, ^\n");
        return 1;
    }

    // Convert first argument to double
    char *end1;
    double num1 = strtod(argv[1], &end1);
    if (*end1 != '\0') {
        printf("Error: Invalid number '%s'\n", argv[1]);
        return 1;
    }

    // Read operator character
    char operator = argv[2][0];
    if (argv[2][1] != '\0') {
        printf("Error: Invalid operator '%s'. Use single character: +, -, *, /, ^\n", argv[2]);
        return 1;
    }

    // Convert third argument to double
    char *end2;
    double num2 = strtod(argv[3], &end2);
    if (*end2 != '\0') {
        printf("Error: Invalid number '%s'\n", argv[3]);
        return 1;
    }

    // Perform calculation
    double result;
    if (calculator(num1, operator, num2, &result)) {
        printf("\033[32m%.2lf %c %.2lf = %.2lf\033[32m\n", num1, operator, num2, result);
        return 0;
    } else {
        return 1;
    }
}
