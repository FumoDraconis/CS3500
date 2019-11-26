#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "printResult.c"
#include "calculate.c"

#define   MAXCHAR 100
#define   INPUT_FILE "virtualMachine/codeGeneratorOutput.txt"

double stack[MAXCHAR];
int operations[MAXCHAR];
int prevInstIsOp = 0;
int stackTop = 0;
int operationsLength = 0;


void calculateSum(){
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
            exit(0);
        }
        stack[stackTop] = doCalculation(operator,number_1,number_2);
        operationsIter += 1;
    }
}

void determineOppOrNumAndCalcIfNecessary(char stringToSplit[MAXCHAR]) {
    char * split;
    split = strtok(stringToSplit," ");
    while (split != NULL) {
        /*
         * checks if there are calculations to be made before loading the next number
         * */
        if ((strcmp(split, "LOADINT") == 0 || strcmp(split, "LOADFLOAT") == 0) && prevInstIsOp == 1 ) {
            stackTop -= 1;
            calculateSum();
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
            else if (strcmp(split, "EXP\n") == 0) {
                operations[operationsLength] = 5;
                prevInstIsOp = 1;
                operationsLength += 1;
            }

            split = strtok(NULL, " ");
            }


    }
}

void readInstructions(){
    FILE *fp;
    char str[MAXCHAR];
    char* filename = INPUT_FILE;
    fp = fopen(filename, "r");
    while (fgets(str, MAXCHAR, fp) != NULL)
        determineOppOrNumAndCalcIfNecessary(str);
    fclose(fp);
}

int main(){
    readInstructions();
    stackTop -= 1;
    calculateSum();
    print(stack[0]);
    return 0;
}
