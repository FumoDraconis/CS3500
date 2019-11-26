/*
* Created by Thomas Cronin
*/
#include <stdio.h>
#include "printResult.h"
// printFormattedAnswer takes a parameter of a float number
// it checks if the number can be an interger
// if it is an interger it returns the value 1 
int printFormattedAnswer(double result){
    int testIfInt = (int)result;
    int isItAnInt = 0;
    if ((result - testIfInt) != 0.000 ){
        printf("%.3f\n", result);

    }
    else {
        printf("%i\n", testIfInt);
        isItAnInt = 1;
    }
    return isItAnInt;
}
