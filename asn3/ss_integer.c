// CS2211 2023
// Assignment number : 3
// Aryan gupta
// 251306109
// agupt379
// 12th October 2023.
#include <stdio.h>
#include <math.h>
// Defining the seven-segment display for each individual digit
const char segments[10][3][3] =
{
    // 0
    { 
        {' ', '_', ' '},
        {'|', ' ', '|'},
        {'|', '_', '|'}
    },
    // 1
    { 
        {' ', ' ', ' '},
        {' ', ' ', '|'},
        {' ', ' ', '|'}
    },
    // 2
    {
        {' ', '_', ' '},
        {' ', '_', '|'},
        {'|', '_', ' '}
    },
    // 3
    { 
        {' ', '_', ' '},
        {' ', '_', '|'},
        {' ', '_', '|'}
    },
    // 4
    { 
        {' ', ' ', ' '},
        {'|', '_', '|'},
        {' ', ' ', '|'}
    },
    // 5
    { 
        {' ', '_', ' '},
        {'|', '_', ' '},
        {' ', '_', '|'}
    },
    // 6
    { 
        {' ', '_', ' '},
        {'|', '_', ' '},
        {'|', '_', '|'}
    },
    // 7
    { 
        {' ', '_', ' '},
        {' ', ' ', '|'},
        {' ', ' ', '|'}
    },
    // 8
    { 
        {' ', '_', ' '},
        {'|', '_', '|'},
        {'|', '_', '|'}
    },
    // 9
    { 
        {' ', '_', ' '},
        {'|', '_', '|'},
        {' ', ' ', '|'}
    }
};
// method used to the output of each individual digit
void display(int dig)
{
    // in the case double digit has been passed by mistake
    if(dig < 0 || dig > 9)
    {
        printf("Invalid Input\n");
        return;
    }
    // total number of rows for each individual digit is 3.
    for(int r = 0; r < 3; r++)
    {
        // total number of columns for each individual digit is 3.
        for(int c = 0; c < 3; c++)
        {
            // to help us print each digit.
            printf("%c" , segments[dig][r][c]);
        }
        // required newline otherwise digit won't be formed properly.
        printf("\n");
    }
}
// main method used to run the program, and provide the desired output.
int main()
{
    // stores the value of the choice.
    char choice;
    do 
    {
        // stores the value of a valid integer.
        int vi;
        printf("Enter enter a valid integer: ");
        scanf("%d" , &vi);
        // in the case of negative integer
        if(vi < 0)
        {
            printf("-\n");
            // to make sure the program works, we need to do this.
            vi = -vi;
        }
        // in the case of positive integer
        else
        {
            printf("+\n");
        }
        // temporary variable
        // used to count the number of digits in the integer.
        int temp = vi;
        // intializing it to 0 at first.
        int digitCount = 0;
        // loop used to count the number of digits in the 
        // given integer.
        while (temp > 0) 
        {
            temp /= 10;
            digitCount++;
        }
        // helper integer used to print the digits of the inputted 
        // integer in the correct order
        int help = pow(10,(digitCount-1));
        // loop used to print the individual digits in segmented format 
        // of the inputted integer.
        while(help>0)
        {
            // stores the first digit of the integer each time
            int dig = vi/help;
            // calling the display method to print the given digit in 
            // correct segmented format
            display(dig);
            // used to remove the first integer after it has been printed
            // using the display(dig) method.
            vi = vi%help;
            // this is done to extract the subsequent digits 
            // of the integer to print the in the segmented format.
            help/=10;
        }
        printf("Do you want to continue (Y/N)? ");
        // to check if user wants to continue or not.
        scanf(" %c", &choice); 
    }
    // if choice is y or Y, we still continue the loop.
    while (choice == 'Y' || choice == 'y');
    return 0;
}
