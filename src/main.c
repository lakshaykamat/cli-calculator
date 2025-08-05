#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "../include/calculator.h"

void print(double n){
    printf("%.2lf\n", n);
}

void clear_input_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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
        }
        else{
            printf("Error: Division by zero is not allowed.\n");
            return false;
        }
    case '^':
        *result = power(num1, num2);
        return true;
    default:
        printf("Error: Unsupported operator '%c'.\n", operator);
        return false;
    }
}

int main(){
    double num1, num2, result;
    char operator, choice;
    printf("=== Simple CLI Calculator ===\n");

    do{
        printf("Enter an expression (e.g., 5 + 2): ");

        // Check if input is valid
        if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3){
            printf("Invalid input! Please enter numbers and operator separated by spaces.\n");
            clear_input_buffer();
            
            printf("Do you want to try again? (y/n): ");
            if (scanf(" %c", &choice) != 1) {
                printf("Invalid input. Exiting...\n");
                break;
            }
            clear_input_buffer();
            continue;
        }

        if (calculator(num1, operator, num2, &result)){
            print(result);
        }
        
        printf("Do you want to perform another calculation? (y/n): ");
        if (scanf(" %c", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }
        clear_input_buffer();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator!\n");
    return 0;
}
