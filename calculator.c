// calculator.c - IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#include "calculator.h"

int sum(int num1, int num2)
{
 return num1 + num2;
}
int sub(int num1, int num2)
{
  return num1 - num2;
}
int mult(int num1, int num2)
{
  return num1 * num2;
}
int divide(int num1, int num2)
{
  return num1 / num2;
}
int rem(int num1, int num2)
{
  return num1 % num2; //% says to return the remainder
}

// Return title of the program
char *calculator_get_title()
{
  return "Calculator Program";
}

//int main(void)
int calculator_menu()
{
 char operator;
    double num1, num2, result;

    printf("\nEnter first number: ");
    scanf("%lf", &num1);
    getchar();
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);
    getchar();
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Cannot divide by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    printf("\n%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);

    return 0;
}