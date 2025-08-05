#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include "../include/calculator.h"

#define INPUT_BUFFER_SIZE 100

/**
 * A safer wrapper around scanf that:
 * - Reads a full line of input safely.
 * - Parses the input according to the format.
 * - Clears leftover input by reading the whole line.
 * - Returns the number of matched inputs.
 *
 * @param format The scanf-style format string.
 * @param ... Pointers to variables where parsed values will be stored.
 * @return Number of successfully matched input items, or -1 on error.
 */
int safe_scanf(const char *format, ...) {
    char buffer[INPUT_BUFFER_SIZE];

    // Read a full line of input safely
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        // Input error or EOF
        return -1;
    }

    va_list args;
    va_start(args, format);
    int matched = vsscanf(buffer, format, args);
    va_end(args);

    // matched can be EOF (-1) or number of inputs matched
    return matched;
}

/**
 * The main entry point of the calculator program.
 *
 * Reads user input expressions, calculates results,
 * and asks the user if they want to perform more calculations.
 *
 * @return Exit status code (0 on success).
 */
int main(){
    double num1, num2, result;
    char operator, choice;

    printf("=== Simple CLI Calculator ===\n");

    do {
        // Prompt user and read expression
        printf("Enter an expression (e.g., 5 + 2): ");
        if (safe_scanf("%lf %c %lf", &num1, &operator, &num2) != 3){
            printf("Invalid input! Please enter two numbers and an operator.\n");

            printf("Do you want to try again? (y/n): ");
            if (safe_scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y')) {
                printf("Exiting...\n");
                break;
            }
            continue;
        }

        // Calculate and print result
        if (calculator(num1, operator, num2, &result)){
            printf("%.2lf",result);
        }

        // Ask user whether to continue
        printf("Do you want to perform another calculation? (y/n): ");
        if (safe_scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y')) {
            break;
        }

    } while (true);

    printf("Thank you for using the calculator!\n");
    return 0;
}
