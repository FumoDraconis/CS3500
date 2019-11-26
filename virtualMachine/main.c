/*
* Created by Thomas Cronin
*/
#include "vmFunctionality/virtualMachine.h"
#define INPUT_FILE "virtualMachine/codeGeneratorOutput.txt"



// function main takes no parameters
// calls the two functions readInstructions and calculateSumPrintAnswer
// from virtualMachine.c
// returns 0 on completion
int main () {
    int errorCheck = readInstructions(INPUT_FILE);
    if (errorCheck == 0) {
        calculateSumPrintAnswer();
    }
    return 0;
}
