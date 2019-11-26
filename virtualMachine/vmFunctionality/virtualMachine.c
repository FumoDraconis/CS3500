/*
* Created by Thomas Cronin
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"
#include "virtualMachine.h"
#include "printResult.h"
#define   MAXCHAR 100

// virtualMachine
// creates the stack for the ints and floats
double stack[MAXCHAR];
//creates the list of opperations being used
int operations[MAXCHAR];
// creates variable to check if previous instruction was an operand
int prevInstIsOp = 0;
// creates the stack pointer stackTop
int stackTop = 0;
// creates the operationslength variable
int operationsLength = 0;



// prepCalculation takes no parameters
// it uses the global stack, operations, prevInstIsOp, stackTop operationsLength
// to prepare each calculation
// returns an int of 0 if no error occured
// else it returns an int error code
int prepCalculation() {
    /*
     * prepCalculation
     * while there are operations to do
     * it takes two numbers of the stack
     * takes the first or next operation to do
     * runs the function doCalculation with the operator, and both numbers
     * */
    operationsLength -= 1;
    int operationsIter = 0;
    while (operationsIter <= operationsLength ){
        int operator = operations[operationsIter];
        operations[operationsIter] = 0;
        double number_2 = stack[stackTop];
        stack[stackTop] = 0.0;
        stackTop -=1;
        double number_1 = stack[stackTop];
        if (operator == 4 && number_2 == 0) {
            printf("Error: Cannot divide by 0\n");
            return -1;
        }

        stack[stackTop] = doCalculation(operator,number_1,number_2);
        operationsIter += 1;
    }
    return 0;
}

// determineOppOrNumAndCalcIfNecessary takes a parameter of an aray of
// characters
// its splits the array on spaces and returns the executes each instruction
// returns an error code if an error occured
int determineOppOrNumAndCalcIfNecessary(char stringToSplit[MAXCHAR]) {
    char * split;
    // seperates line on spaces
    split = strtok(stringToSplit," ");
    while (split != NULL) {
         //checks if there are calculations to be made before loading the next number
        if ((strcmp(split, "LOADINT") == 0 || strcmp(split, "LOADFLOAT") == 0) && prevInstIsOp == 1 ) {
            stackTop -= 1;
            int div0 = prepCalculation();
            if (div0 == -1){return div0;};
            stackTop += 1;
            operationsLength = 0;
        }
        // checks if it will be loading and int or float
        if (strcmp(split, "LOADINT") == 0) {
            split = strtok(NULL, " ");
            int LOADINT = atoi(split);
            stack[stackTop] = LOADINT;
            stackTop += 1;
            split = strtok(NULL, " ");
            prevInstIsOp = 0;
        }
        else if (strcmp(split, "LOADFLOAT") == 0) {
            split = strtok(NULL, " ");
            double LOADFLOAT = atof(split);
            stack[stackTop] = LOADFLOAT;
            stackTop += 1;
            split = strtok(NULL, " ");
            prevInstIsOp = 0;
        }
        // determines the correct operand number
        else {
            if (strcmp(split, "ADD\n") == 0) {
                operations[operationsLength] = 1;
                prevInstIsOp = 1;
                operationsLength += 1;
            }
            else if (strcmp(split, "MUL\n") == 0) {
                operations[operationsLength] = 2;
                prevInstIsOp = 1;
                operationsLength += 1;
            }
            else if (strcmp(split, "SUB\n") == 0) {
                operations[operationsLength] = 3;
                prevInstIsOp = 1;
                operationsLength += 1;
            }
            else if (strcmp(split, "DIV\n") == 0) {
                operations[operationsLength] = 4;
                prevInstIsOp = 1;
                operationsLength += 1;
                }
            else if (strcmp(split, "EXP\n") == 0) {
                operations[operationsLength] = 5;
                prevInstIsOp = 1;
                operationsLength += 1;
            }
            else if (strcmp(split, "MOD\n") == 0) {
                operations[operationsLength] = 6;
                prevInstIsOp = 1;
                operationsLength += 1;
            }

            split = strtok(NULL, " ");
            }
    }
}

// readInstructions takes in an char array of a file path
// it then opens the file and reads it line by line calling
// determineOppOrNumAndCalcIfNecessary
// returns 0 if executed with no errors
// returns error code otherwise
int readInstructions(char * file){
  // opens the file to be read
    FILE *fp;
    char fileLine[MAXCHAR];
    char* filename = file;
    fp = fopen(filename, "r");
    // if file exists
    if (fp != NULL){
      // reads file line by line
      while (fgets(fileLine, MAXCHAR, fp) != NULL){
          int div0 = determineOppOrNumAndCalcIfNecessary(fileLine);
          //if division of 0 occured
          if (div0 == -1){
            return div0;
          }
        }
        // closes the file
      fclose(fp);
    }
    else {
      printf("\nError codeGeneratorOutput file was not found\n");
      return -2;
    }
    return 0;
}

// calculateSumPrintAnswer takes no parameter it uses the global variables
// it returns 0 or else the divison of 0 error code
int calculateSumPrintAnswer() {
  stackTop -= 1;
  int div0 = prepCalculation();
  if (div0 == 0){
    printFormattedAnswer(stack[0]);
    return 0;
    }
  return div0;
}
