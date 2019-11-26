/*
* Created by Thomas Cronin
*/
#include <stdio.h>
#include <math.h>
#include "calculate.h"

/*
 * doCalculation takes an operator as an int and to floats of numbers
 * it uses a switch to determine what the operator to use
 * it calculates and stores the result as a double
 * it returns the result of the calculations as a double
 * */
double doCalculation(int operation, double number_1, double number_2) {
    double result;
    switch (operation) {
        case 1: // Add
            result = number_1 + number_2;
            break;
        case 2: // mull;
            result = number_1 * number_2;
            break;
        case 3: // sub;
            result = number_1 - number_2;
            break;
        case 4: // div;
            result = number_1 / number_2;
            break;
        case 5: // EXP;
            result = number_1;
            double base = number_1;
            double exponent = number_2;
            if (number_2 == 0) {
                result = 1;
            }
            while (number_2 > 1) {
                result *= base;
                number_2 -= 1;
            }
            break;
        case 6: // div;
            result = (number_1 / number_2);
            int tempResult = (int) result;
            result = (number_1 - (tempResult * number_2));
            break;
    }

    return result;
}
