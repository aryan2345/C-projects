#include <stdio.h>
// function to convert from Celsius to Fahrenheit
float celToFah(float celsius)
{
    return (celsius*(9.0/5.0))+32.0;
}
// function to convert from Fahrenheit to Celsius
float fahToCel(float fah)
{
    return (fah-32.0) * (5.0/9.0);
}
// function to convert Centimetre to Inch
float cenToInch(float cen)
{
    return cen/2.54;
}
// function to convert Inch to Centimetre
float inchToCen(float inch)
{
    return inch*2.54;
}
// function to convert Kilometer to Mile
float kilToMile(float kil)
{
    return kil/1.61;
}
// function to convert Mile to Kilometer
float mileToKilometer(float mile)
{
    return mile*1.61;
}
// function to convert gallon to Liter
float galToLiter(float gallon)
{
    return gallon*3.79;
}
// function to convert to Liter to gallon
float literToGallon(float liter)
{
    return liter/3.79;
}
// main method to facilate the required conversions 
int main()
{
    do{
    // conversion chart
    // stores the option picked by the user
    int option;
    printf("Pick an option: \n");
    printf("1 for conversion between Celsius and Fahrenheit\n");
    printf("2 for conversion between Centimetre and Inch\n");
    printf("3 for conversion between Kilometer and Mile\n");
    printf("4 for conversion between Gallon and Liter\n");
    printf("0 for quit\n");
    scanf("%d" , &option);
    // stores the result for the converted value of the inputted value by the user
    float result;
    // stores the inputted character, telling us what conversion will take place.
    char ic;
        // switch case used to make the required conversion chart
        // and to do the required conversions.
        switch(option)
        {
            // in the case the user doesn't want to do any conversions
            // we return 0 to end the program.
            case 0:
                printf("Program ended. Thank you!");
                return 0;
            // to convert from Celsius to Fahrenheit or from Fahrenheit to
            // Celsius.
            case 1:
                // label for handling incorrect input.
                Incor1:
                printf("Please give the conversion direction: \n");
                printf("C for conversion from Celsius to Fahrenheit\n");
                printf("F for conversion from Fahrenheit to Celsius\n");
                scanf(" %c" , &ic);
                if(ic == 'C' || ic == 'c')
                {
                    // stores celsius value
                    float cel;
                    printf("Enter Celsius value: ");
                    scanf("%f" , &cel);
                    result = celToFah(cel);
                    printf("Celsius in %.2f to Fahrenheit is %.2f\n" , cel , result);
                }
                else if(ic == 'F' || ic == 'f')
                {
                    // stores Fahrenheit value
                    float fah;
                    printf("Enter Fahrenheit value: ");
                    scanf("%f" , &fah);
                    result = fahToCel(fah);
                    printf("Fahrenheit in %.2f to Celsius is %.2f\n" , fah , result);
                }
                else
                {
                    // In the case of there being an incorrect input. We take back the
                    // control to the beginning of this case.
                    printf("Incorrect Input. Please enter again: \n");
                    goto Incor1;
                }
                break;
            // to convert from Centimetre to inch or from Centimetre to inch.
            case 2:
                // label for handling incorrect input. 
                Incor2:
                printf("Please give the conversion direction: \n");
                printf("C for conversion from Centimetre to Inch\n");
                printf("I for conversion from Inch to Centimetre\n");
                scanf(" %c" , &ic);
                if(ic == 'C' || ic == 'c')
                {
                    // stores Centimetre value
                    float cent;
                    printf("Enter Centimetre value: ");
                    scanf("%f" , &cent);
                    result = cenToInch(cent);
                    printf("Centimeter in %.2f to Inch is %.2f\n" , cent , result);
                }
                else if(ic == 'I' || ic == 'i')
                {
                    // stores inch value
                    float inch;
                    printf("Enter Inch value: ");
                    scanf("%f", &inch);
                    result = inchToCen(inch);
                    printf("Inch in %.2f to Centimeter is %.2f\n" , inch , result);
                }
                else
                {
                    // In the case of there being an incorrect input. We take back the
                    // control to the beginning of this case.
                    printf("Incorrect Input. Please enter again: \n");
                    goto Incor2;
                }
                break;
            // to convert from Kilometer to mile or from mile to Kilometer
            case 3:
                // label for handling incorrect input.
                Incor3:
                printf("Please give the conversion direction: \n");
                printf("K for conversion from Kilometer to mile\n");
                printf("M for conversion from Mile to Kilometer\n");
                scanf(" %c" , &ic);
                if(ic == 'K' || ic == 'k')
                {
                    // stores Kilometer value
                    float km;
                    printf("Enter Kilometer value: \n");
                    scanf("%f" , &km);
                    result = kilToMile(km);
                    printf("Kilometer in %.2f to mile is %.2f\n" , km , result);
                }
                else if(ic == 'M' || ic == 'm')
                {
                    // stores mile value
                    float mile;
                    printf("Enter Mile value: \n");
                    scanf("%f" , &mile);
                    result = mileToKilometer(mile);
                    printf("Mile in %.2f to Kilometer is %.2f\n" , mile , result);
                }
                else
                {
                    // In the case of there being an incorrect input. We take back the
                    // control to the beginning of this case.
                    printf("Incorrect Input. Please enter again: \n");
                    goto Incor3;
                }
                break;
            // to convert from gallon to Liter or from liter to gallon
            case 4:
                // label for handling incorrect input.
                Incor4:
                printf("Please give the conversion direction: \n");
                printf("G for conversion from gallon to liter\n");
                printf("L for conversion from liter to gallon\n");
                scanf(" %c" , &ic);
                if(ic == 'G' || ic == 'g')
                {
                    // stores gallon value
                    float gallon;
                    printf("Enter gallon value: \n");
                    scanf("%f" , &gallon);
                    result = galToLiter(gallon);
                    printf("Gallon in %.2f to liter is %.2f\n" , gallon , result);
                }
                else if(ic == 'L' || ic == 'l')
                {
                    // stores liter value
                    float liter;
                    printf("Enter liter value: \n");
                    scanf("%f" , &liter);
                    result = literToGallon(liter);
                    printf("Liter in %.2f to gallon is %.2f\n" , liter , result);
                }
                else
                {
                    // In the case of there being an incorrect input. We take back the
                    // control to the beginning of this case.
                    printf("Incorrect Input. Please enter again: \n");
                    goto Incor4;
                }
                break;
            // in case the user didn't input the correct integer for 
            // conversion.
            default:
                printf("Incorrect Input. Please try again.\n");
        }
    }
    while(1);
    return 0;
}

