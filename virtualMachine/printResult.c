#include <stdio.h>
#include "printResult.h"

void printFormattedAnswer(double result){
    int testIfInt = (int)result;
    if ((result - testIfInt) != 0.000 ){
        printf("%.3f\n", result);
    }
    else {
        printf("%i\n", testIfInt);
    }
}
