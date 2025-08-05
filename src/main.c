#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/calculator.h"

/**
 * Display help information for the calculator
 */
void show_help(const char *program_name) {
    printf("\033[36m╔══════════════════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[36m║                    CLI CALCULATOR HELP                      ║\033[0m\n");
    printf("\033[36m╚══════════════════════════════════════════════════════════════╝\033[0m\n");
    printf("\n");
    printf("\033[33m📖 USAGE:\033[0m\n");
    printf("  %s <number1> <operator> <number2>\n", program_name);
    printf("  %s -h, --help\n", program_name);
    printf("\n");
    printf("\033[33m📋 EXAMPLES:\033[0m\n");
    printf("  %s 5 + 3\n", program_name);
    printf("  %s 10 - 4\n", program_name);
    printf("  %s 6 * 7\n", program_name);
    printf("  %s 15 / 3\n", program_name);
    printf("  %s 2 ^ 3\n", program_name);
    printf("  %s 10 %% 3\n", program_name);
    printf("\n");
    printf("\033[33m🔧 SUPPORTED OPERATIONS:\033[0m\n");
    printf("  \033[32m+\033[0m  Addition\n");
    printf("  \033[32m-\033[0m  Subtraction\n");
    printf("  \033[32m*\033[0m  Multiplication\n");
    printf("  \033[32m/\033[0m  Division\n");
    printf("  \033[32m^\033[0m  Power (exponentiation)\n");
    printf("  \033[32m%%\033[0m  Modulo (remainder)\n");
    printf("\n");
    printf("\033[33m⚠️  ERROR HANDLING:\033[0m\n");
    printf("  • Division by zero\n");
    printf("  • Invalid numbers\n");
    printf("  • Unsupported operators\n");
    printf("  • Wrong number of arguments\n");
    printf("\n");
    printf("\033[33m📊 OUTPUT FORMAT:\033[0m\n");
    printf("  number1 operator number2 = result\n");
    printf("  Example: 5.00 + 3.00 = 8.00\n");
    printf("\n");
    printf("\033[33m🚀 SYSTEM INSTALLATION:\033[0m\n");
    printf("  make install    # Install as 'calc' command\n");
    printf("  make uninstall  # Remove 'calc' command\n");
    printf("\n");
    printf("\033[33m🔗 EXIT CODES:\033[0m\n");
    printf("  0 - Success\n");
    printf("  1 - Error (invalid input, division by zero, etc.)\n");
    printf("\n");
    printf("\033[36m╔══════════════════════════════════════════════════════════════╗\033[0m\n");
    printf("\033[36m║                    HAPPY CALCULATING!                       ║\033[0m\n");
    printf("\033[36m╚══════════════════════════════════════════════════════════════╝\033[0m\n");
}

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
    // Check for help flag
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        show_help(argv[0]);
        return 0;
    }
    
    // Check if correct number of arguments provided
    if (argc != 4) {
        printf("\033[31mError: Wrong number of arguments!\033[0m\n");
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        printf("Example: %s 5 + 3\n", argv[0]);
        printf("For help: %s -h\n", argv[0]);
        return 1;
    }

    // Convert first argument to double
    char *end1;
    double num1 = strtod(argv[1], &end1);
    if (*end1 != '\0') {
        printf("\033[31mError: Invalid number '%s'\033[0m\n", argv[1]);
        return 1;
    }

    // Read operator character
    char operator = argv[2][0];
    if (argv[2][1] != '\0') {
        printf("\033[31mError: Invalid operator '%s'. Use single character: +, -, *, /, ^, %%\033[0m\n", argv[2]);
        return 1;
    }

    // Convert third argument to double
    char *end2;
    double num2 = strtod(argv[3], &end2);
    if (*end2 != '\0') {
        printf("\033[31mError: Invalid number '%s'\033[0m\n", argv[3]);
        return 1;
    }

    // Perform calculation
    double result;
    if (calculator(num1, operator, num2, &result)) {
        printf("\033[32m%.2lf %c %.2lf = %.2lf\033[0m\n", num1, operator, num2, result);
        return 0;
    } else {
        return 1;
    }
}
