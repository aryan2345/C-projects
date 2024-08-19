// CS2211 2023
// Assignment number : 3
// Aryan gupta
// 251306109
// agupt379
// 12th October 2023.
#include <stdio.h>
#include <stdlib.h>

// Function to get the next operator from stdin.
char get_op(void)
{
    // stores the value of the next operator.
    char op;
    while (1) 
    {
        // Read a character from the standard input
        op = getchar(); 
        // Skip spaces and tabs
        if (op == '\t' || op == ' ') 
        {
            continue;
        } 
        // Valid operator, return it (either + or -).
        else if (op == '-' || op == '+')
        {
            return op;
        }
        // End of expression, returning a newline character as stated in the question.
        else if (op == '\n')
        {
            return op; 
        }
        // Invalid character, exit with an error
        else 
        {
            printf("Error: Invalid Input.\n");
            exit(EXIT_FAILURE); 
        }
    }
}

// Function to get the next numeric value from stdin
float get_num(void)
{
    // next_num stores the value of the next numeric value.
    float next_num;
    // Read and store the next numeric value (either integer or float)
    scanf("%f", &next_num); 
    // returning the next numeric value as stated in the question.
    return next_num; 
}

// Recursive function to evaluate a sub-expression.
float sub_sim_exp(float sub_exp)
{
    // To get the value of the next operator needed to evaluate the arithmetic 
    // expression.
    char op = get_op();
    // End of expression, return the result
    if (op == '\n') 
    {
        return sub_exp; 
    } 
    // in case of valid operators, we proceed with this.
    else if (op == '+' || op == '-') 
    {
        // Get the next numeric value
        float next = get_num(); 
        // Recursively evaluate with addition
        if (op == '-')
        {
            return sub_sim_exp(sub_exp - next);
        } 
        // Recursively evaluate with subtraction
        else
        {
            return sub_sim_exp(sub_exp + next);
        }
    } 
    // Invalid operator, exit with an error.
    else
    {
        printf("Error: Invalid Input.\n");
        exit(EXIT_FAILURE); 
    }
}

// Main function which is used to evaluate the simple arithmetic expression.
float sim_exp(void) 
{
    // Get the first numeric value used to evaluate the arithmetic expression.
    float num = get_num(); 
    // Starting the recursive evaluation.
    return sub_sim_exp(num); 
}

int main()
{
    // Stores the result of the simple arithmetic function
    float finalResult;
    // Stores character input to determine if the program will run again or not
    char input;
    while (1) 
    {
        printf("Enter an arithmetic expression please: ");
        // Evaluate the expression
        finalResult = sim_exp(); 
        printf("Result: %.2f\n", finalResult);
        // to check if the user wants to continue evaluating arithmetic expression or not
        printf("Do you want to continue (Y/N)\n");
        // stores the value of the character input to check if user wants to continue or not
        scanf(" %c", &input);
        // in case user inputs y, we have to evaluate another arithmetic expression.
        if (input == 'Y' || input == 'y')
        {
            continue;
        }
        // exiting the loop if the user doesn't want to continue.
        break;
    }

    return 0;
}

