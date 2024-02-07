#include <stdio.h>

int main(){
    double num1, num2;

    printf("Enter the first number: ");
    scanf("%lf",&num1);
    printf("Enter the second number: ");
    scanf("%lf",&num2);

    printf("Sum: %.2f\n", num1 + num2);
    printf("Difference: %.2f\n", num1 - num2);
    printf("Product: %.2f\n", num1 * num2);
    if (num2 != 0) {
        printf("Quotient: %.2f\n", num1 / num2);
    } else {
        printf("Cannot divide by zero.\n");
    }

    return 0;
}