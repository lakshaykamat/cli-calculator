#include <stdio.h>
#include <stdbool.h>
#include "../include/calculator.h"

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

    printf("\033[36m=== Simple CLI Calculator ===\033[36m\n");

    do {
        printf("\033[33mEnter an expression (e.g., 5 + 2): \033[33m");
        if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3){
            printf("\033[31mInvalid input! Please enter two numbers and an operator.033[31m\n");

            printf("\033[0m\nDo you want to try again? (y/n): \033[0m\n");
            if (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y')) {
                printf("\033[34mExiting...\033[0m\n");
                break;
            }
            continue;
        }

        if (calculator(num1, operator, num2, &result)){
            printf("\033[32m%lf %c %lf = \033[32m",num1,operator,num2);
            printf("\033[32m%.2lf\033[32m\n",result);
        }

        printf("\33[36mDo you want to perform another calculation? (y/n): \033[35m");
        if (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y')) {
            break;
        }

    } while (true);
    return 0;
}
