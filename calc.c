#include <stdio.h>

int main() {
// Declare and initialize variables
double firstNumber = 0.0;
double secondNumber = 0.0;
double calculationResult = 0.0;
char operatorInput = '\0';
  
// Prompt the user for the first number
printf("Enter First Number: ");
scanf("%lf", &firstNumber);
// Prompt the user for the operator
printf("Enter Operator (+, -, *, /): ");
scanf(" %c", &operatorInput); // Note the space before %c to catch whitespace
// Prompt the user for the second number
printf("Enter Second Number: ");
scanf("%lf", &secondNumber);
  
// Perform calculation based on the operator input
switch (operatorInput) {
case '+':
calculationResult = firstNumber + secondNumber;
printf("Result: %.2lf\n", calculationResult);
break;
case '-':
calculationResult = firstNumber - secondNumber;
printf("Result: %.2lf\n", calculationResult);
break;
case '*':
calculationResult = firstNumber * secondNumber;
printf("Result: %.2lf\n", calculationResult);
break;
case '/':
// Check division by zero
if (secondNumber == 0.0) {
printf("Error: Division by zero is not allowed.\n");
} else {
calculationResult = firstNumber / secondNumber;
printf("Result: %.2lf\n", calculationResult);
}
break;
default:
// Handle invalid operator input
printf("Invalid operator. Please use +, -, *, or / only.\n");
break;
}
return 0; // Successful program termination
}
