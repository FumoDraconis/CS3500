//
// Created by Tom Cronin on 25/11/2019.
//
#include "vmFunctionality/virtualMachine.h"
#define INPUT_FILE "codeGeneratorOutput.txt"

int main () {
    int errorCheck = readInstructions(INPUT_FILE);
    if (errorCheck == 0) {
        calculateSumPrintAnswer();
    }
    return 0;
}
