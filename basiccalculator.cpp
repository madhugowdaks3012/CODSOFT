#include <stdio.h>

int main() 
{
    double a, b;
    char op;
    double result;

    printf("Enter the first number: ");
    scanf("%lf", &a);
    printf("Enter the second number: ");
    scanf("%lf", &b);
    printf("Enter the operator: ");
    scanf(" %c", &op);

    switch (op) {
        case '+':
            result = a + b;
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = a - b;
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = a * b;
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            if (b != 0) {
                result = a / b;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;
    }

    return 0;
}
