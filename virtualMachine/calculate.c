//
// Created by Tom Cronin on 18/11/2019.
//



double doCalculation(int operation, double number_1, double number_2) {
        printf("\nFirst Number: %.3f ", number_1);
        printf("Opperator (%d)",operation );
        printf(" Second Number: %.3f", number_2);
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
    }
    printf(" result = %.3f\n", result);
    return result;
}