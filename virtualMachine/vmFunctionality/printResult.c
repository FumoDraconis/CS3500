#include <stdio.h>
#include "printResult.h"

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
