/* Simple calculator: addition, subtraction, multiplication and division
   using functions and control statements. */

#include <stdio.h>

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

/* Reads a number safely; keeps asking until valid input is entered. */
double get_number(const char *prompt) {
    double value;
    int c;

    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1) {
            return value;
        }
        printf("Invalid input. Please enter a number.\n");
        while ((c = getchar()) != '\n' && c != EOF)
            ;   /* clear the input buffer */
        if (c == EOF) {
            return 0;
        }
    }
}

int main(void) {
    int choice, c;
    double num1, num2, result;

    while (1) {
        printf("\n===== CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number from 1 to 5.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            if (c == EOF) {
                break;
            }
            continue;
        }

        if (choice == 5) {
            printf("Thank you for using the calculator. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please select a number from 1 to 5.\n");
            continue;
        }

        num1 = get_number("Enter first number: ");
        num2 = get_number("Enter second number: ");

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
        }
    }

    return 0;
}
