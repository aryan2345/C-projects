#include <stdio.h>

// Function to calculate the factorial of a number
long long factorial(int n)
{
    if (n == 1)
    {
        // factorial of 1 is 1.
        return 1;
    }

    else
    {
        // recursion to calculate the factorial of given number n.
        return n * factorial(n - 1);
    }
}
// Function to calculate the approximation of e
double calculateE(double epsilon)
{
    double e; // stores final e value.
    int n; // used to calculate factorial of given number needed for e.
    double term; // stores value of 1/n! where n = 1,2,3,4,... ,n
    e = 1.0;
    n = 1;
    // while loop will run till term < epsilon.
    while (1)
    {
        term = 1.0 / factorial(n);

        if (term < epsilon)
        {
            break;
        }

        e += term;
        n++;
    }
    // returning final e value.
    return e;
}

int main() {
    double epsilon;

    // Input epsilon from the user
    printf("Enter a small number (epsilon): ");
    scanf("%lf", &epsilon);

    // Calculate and print the approximation of e for the given epsilon
    double result = calculateE(epsilon);
    printf("Approximation of e: %.13lf\n", result);

    return 0;
}



