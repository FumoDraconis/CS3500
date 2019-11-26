#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "calculate.h"
#include "virtualMachine.h"
#include "printResult.h"

#define   MAXCHAR 100

// virtualMachine/
double stack[MAXCHAR];
int operations[MAXCHAR];
int prevInstIsOp = 0;
int stackTop = 0;
int operationsLength = 0;


int prepCalculation(double stack[],int operations[],int stackTop,int operationsLength) {
    /*
     * calculateSum
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

int determineOppOrNumAndCalcIfNecessary(char stringToSplit[MAXCHAR]) {
    char * split;
    split = strtok(stringToSplit," ");
    while (split != NULL) {
        /*
         * checks if there are calculations to be made before loading the next number
         * */
        if ((strcmp(split, "LOADINT") == 0 || strcmp(split, "LOADFLOAT") == 0) && prevInstIsOp == 1 ) {
            stackTop -= 1;
            int div0 = prepCalculation(stack, operations, stackTop, operationsLength);
            if (div0 == -1){return div0;};
            stackTop += 1;
            operationsLength = 0;
        }

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

            split = strtok(NULL, " ");
            }
    }
}

int readInstructions(char * file){
    FILE *fp;
    char fileLine[MAXCHAR];
    char* filename = file;
    fp = fopen(filename, "r");
    if (fp != NULL){
      while (fgets(fileLine, MAXCHAR, fp) != NULL){
          int div0 = determineOppOrNumAndCalcIfNecessary(fileLine);
          if (div0 == -1){
            return div0;
          }
        }
      fclose(fp);
    }
    else {
      printf("\nError codeGeneratorOutput file was not found\n");
      return -2;
    }
    return 0;
}

int calculateSumPrintAnswer() {
  stackTop -= 1;
  int div0 = prepCalculation(stack, operations, stackTop, operationsLength);
  if (div0 == 0){
    printFormattedAnswer(stack[0]);
    return 0;
    }
  return div0;
}
