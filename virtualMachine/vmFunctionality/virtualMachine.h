/*
* Created by Thomas Cronin
*/
#ifndef CS3500_VIRTUALMACHINE_H
#define CS3500_VIRTUALMACHINE_H
    // declares function readInstructions which takes
    // array of characters as a function
    int readInstructions(char *);
    // declares function determineOppOrNumAndCalcIfNecessary which takes
    // array of characters as a function
    int determineOppOrNumAndCalcIfNecessary(char stringToSplit[]);
    // declares the function prepCalculation
    int prepCalculation();
    //declares the function calculateSumPrintAnswer
    int calculateSumPrintAnswer();
#endif //CS3500_VIRTUALMACHINE_H
