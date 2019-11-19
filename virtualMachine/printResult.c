//
// Created by Tom Cronin on 18/11/2019.
//

int print(double result){
    int lessThanZero = 0;
    int tempResult = result;
    int resultInt = result;
    if (result < 0) {
        tempResult *= -1;
        resultInt *= -1;
        lessThanZero = 1;
    }
    if ((resultInt * 1000) < (result * 1000)) {
        if (lessThanZero){
            tempResult *= -1;
        }
        printf("%.3f\n", result);
    } else {
        if (lessThanZero){
            tempResult = tempResult * (-1);
        }
        printf("%i\n", resultInt);
    }
    return 0;

}