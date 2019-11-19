#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "printResult.c"
#include "calculate.c"

#define   MAXCHAR 1000

double stack[100];
int oppStack[100];
int prevInstIsOp = 0;
int stackTop = 0;
int oppStackLength = 0;
double result = 0.0;

//void calculateSum(){
//    printf("assss");
//
//    int oppStackIter = 0;
//    while(oppStackTop < oppStackLength){
//        double number_2 = stack[stackTop];
//        stack[stackTop] = 0.0;
//        stackTop -= 1;
//        double number_1 = stack[stackTop];
//        int opperation = oppStack[oppStackIter];
//        oppStack[oppStackIter] = 0;
//
//        oppStackIter += 1;
//        stack[stackTop] = doCalculation(opperation, number_1, number_2);
//    }
//}

void calculateSum(){
    oppStackLength -= 1;
    int oppStackIter = 0;
    while (oppStackIter <= oppStackLength ){
        int operator = oppStack[oppStackIter];
        oppStack[oppStackIter] = 0;
        double number_2 = stack[stackTop];
        stack[stackTop] = 0.0;
        stackTop -=1;
        double number_1 = stack[stackTop];

        printf("\n Number 1: %f", number_1);
        printf("\n operator: %i\n", operator);
        printf(" Number 2: %f\n", number_2);
        stack[stackTop] = doCalculation(operator,number_1,number_2);
        result = stack[stackTop];
        oppStackIter += 1;
    }
    printf("\nleft loop\n");
}

void determinOppOrNum(char stringToSplit[MAXCHAR]) {
    char * split;
    split = strtok(stringToSplit," ");

    while (split != NULL) {
        // if new int loading complete sum so far
        if ((strcmp(split, "LOADINT") == 0 || strcmp(split, "LOADFLOAT") == 0) && prevInstIsOp == 1 ) {
            printf("\nin first load conditional\n");
            stackTop -= 1;
            calculateSum();
            stackTop += 1;
            oppStackLength = 0;
        }

        if (strcmp(split, "LOADINT") == 0) {

                split = strtok(NULL, " ");
                int LOADINT = atoi(split);
                stack[stackTop] = LOADINT;
                 printf("loaded: LOADINT %i ", LOADINT);
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
                    printf("\ntest\n");
                    oppStack[oppStackLength] = 1;
                    prevInstIsOp = 1;
                    oppStackLength += 1;
            }
            else if (strcmp(split, "MUL\n") == 0) {
                    oppStack[oppStackLength] = 2;
                    prevInstIsOp = 1;
                    oppStackLength += 1;
            }
            else if (strcmp(split, "SUB\n") == 0) {
                    oppStack[oppStackLength] = 3;
                    prevInstIsOp = 1;
                    oppStackLength += 1;
            }
            else if (strcmp(split, "DIV\n") == 0) {
                    oppStack[oppStackLength] = 4;
                    prevInstIsOp = 1;
                    oppStackLength += 1;
                }

            split = strtok(NULL, " ");
            }


    }
}

void readInstructions(){
    FILE *fp;
    char str[1000];
    char* filename = "codeGeneratorOutput.txt";
    fp = fopen(filename, "r");
    while (fgets(str, 1000, fp) != NULL)
        determinOppOrNum(str);
    fclose(fp);
}




int main(){
    readInstructions();
    stackTop -= 1;
    printf("calculating final");
    calculateSum();
    printf("%f\n", result);
    return 0;
}

