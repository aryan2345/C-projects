#include <stdio.h>

// Function to calculate the power of two recursively
unsigned long power(unsigned int exponent)
{
    // calculates half of the power, needed to calculate
    // the exponent of 2.
    unsigned long half;
    // Base case: when the exponent is 0 return 1
    if(exponent == 0)
    {
        return 1;
    }
    // if the exponent is odd, we calculate half of the power of the exponent
    // and return the square * 2 of the half power.
    if(exponent%2!=0)
    {
        half = power((exponent-1)/2);
        return half * half * 2;
    }
    // if exponent is even, we calculate half of the power of the exponent
    // and return the square of it
    if(exponent%2==0)
    {
        half = power(exponent/2);
        return half*half;
    }
}
// main method to facilitate the calculation of the power.
int main()
{
    // stores the exponent that we need to calculate.
    unsigned int exp;
    // stores the result of the exponent of 2 in long.
    unsigned long result;
    // required while loop to run the program till it stops
    while(1)
    {
        printf("Enter a non-negative integer number ( or 0 to quit )\n");
        scanf("%u" , &exp);
        // when exponent is 0, we print the output
        if(exp == 0)
        {
            // stores the result of the exponent
            result = power(exp);
            // printing the result of the exponent of 2
            printf("2^%u = %lu\n" , exp , result);
            printf("Program ended. Thank you!!\n");
            // required to exit the program
            break;
        }
        // stores the result of the exponent
        result = power(exp);
        // printing the result of the exponent of 2
        printf("2^%u = %lu\n\n", exp, result);
    }
    return 0;
}


