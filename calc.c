#include <stdio.h>

/* Return codes */
#define APP_OK      (0)
#define APP_ERROR   (1)

static int read_double(const char * prompt, double * value)
{
    int rc;

    if ((prompt == NULL) || (value == NULL))
    {
        return APP_ERROR;
    }

    (void)printf("%s", prompt);
    rc = scanf("%lf", value);
    if (rc != 1)
    {
        /* Clear invalid input from stdin */
        (void)printf("Error: Invalid number input.\n");
        (void)fflush(stdout);

        /* Consume remaining characters until newline or EOF */
        for (;;)
        {
            int ch = getchar();
            if ((ch == '\n') || (ch == EOF))
            {
                break;
            }
        }
        return APP_ERROR;
    }

    return APP_OK;
}

static int read_operator(const char * prompt, char * op)
{
    int rc;

    if ((prompt == NULL) || (op == NULL))
    {
        return APP_ERROR;
    }

    (void)printf("%s", prompt);
    rc = scanf(" %c", op); /* leading space skips whitespace */
    if (rc != 1)
    {
        (void)printf("Error: Invalid operator input.\n");
        return APP_ERROR;
    }

    return APP_OK;
}

int main(void)
{
    double first_number = 0.0;
    double second_number = 0.0;
    double result = 0.0;
    char op = '\0';
    int status = APP_OK;

    if (read_double("Enter First Number: ", &first_number) != APP_OK)
    {
        status = APP_ERROR;
    }
    else if (read_operator("Enter Operator (+, -, *, /): ", &op) != APP_OK)
    {
        status = APP_ERROR;
    }
    else if (read_double("Enter Second Number: ", &second_number) != APP_OK)
    {
        status = APP_ERROR;
    }
    else
    {
        switch (op)
        {
            case '+':
                result = first_number + second_number;
                (void)printf("Result: %.2f\n", result);
                break;

            case '-':
                result = first_number - second_number;
                (void)printf("Result: %.2f\n", result);
                break;

            case '*':
                result = first_number * second_number;
                (void)printf("Result: %.2f\n", result);
                break;

            case '/':
                if (second_number == 0.0)
                {
                    (void)printf("Error: Division by zero is not allowed.\n");
                    status = APP_ERROR;
                }
                else
                {
                    result = first_number / second_number;
                    (void)printf("Result: %.2f\n", result);
                }
                break;

            default:
                (void)printf("Invalid operator. Please use +, -, *, or / only.\n");
                status = APP_ERROR;
                break;
        }
    }

    return status;
}
