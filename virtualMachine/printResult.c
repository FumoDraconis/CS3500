
int print(double result){
    int testIfInt = (int)result;
    if ((result - testIfInt) != 0.000 ){
        printf("\n%.3f\n", result);
    }
    else {
        printf("\n%i\n", testIfInt);
    }
    return 0;
}