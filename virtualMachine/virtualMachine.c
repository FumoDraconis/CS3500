#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define   MAXCHAR 1000

double stack[100];
int oppStack[100];

int stackTop = 0;
int oppStackTop = 0;


void determinOppOrNum(char testString[MAXCHAR]) {
    char * split;
    split = strtok (testString," ");
    while (split != NULL) { 
        if (strcmp(split, "LOADINT") == 0) {
            split = strtok (NULL, " ");
            int LOADINT = atoi(split);
            stack[stackTop] = LOADINT;
            stackTop += 1;
            split = strtok (NULL, " ");
        }
        else if (strcmp(split, "LOADFLOAT") == 0) {
            split = strtok (NULL, " ");
            double LOADFLOAT = atof(split);
            stack[stackTop] = LOADFLOAT;
            stackTop += 1;
            split = strtok (NULL, " ");
        }
        
        else {
            if (strcmp(split, "ADD\n") == 0){
                oppStack[oppStackTop] = 1;
                oppStackTop += 1;
            }
            
            else if (strcmp(split, "MUL\n") == 0) {
                oppStack[oppStackTop] = 2;
                oppStackTop += 1;
            }
            else if (strcmp(split, "SUB\n") == 0) {
                oppStack[oppStackTop] = 3;
                oppStackTop += 1;
            }
            else if (strcmp(split, "DIV\n") == 0) {
                oppStack[oppStackTop] = 4;
                oppStackTop += 1;
            }
        }
        split = strtok (NULL, " ");
    }
}

void readInstructions(){

    FILE *fp;
    char str[MAXCHAR];
    char* filename = "codeGeneratorOutput.txt";
    fp = fopen(filename, "r");
    while (fgets(str, MAXCHAR, fp) != NULL)
        determinOppOrNum(str);
    fclose(fp);
}

void calculateSum(){
    double result;

    while(stackTop > 0){
        double number_2 = stack[stackTop];
        stack[stackTop] = 0.0;
        stackTop -= 1;
        double number_1 = stack[stackTop];

        int opperation = oppStack[oppStackTop];
        oppStack[oppStackTop] = 0.0;
        oppStackTop -= 1;

        switch (opperation) {
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
        stack[stackTop] = result;
    }
}

void printResult(){
    int resultInt = stack[0];
    if (resultInt < stack[0]){
        printf("%.3f\n", stack[0]);
    }
    else {
        printf("%i\n", resultInt);
    }
}

int main(){
    readInstructions();
    stackTop -= 1;
    oppStackTop -= 1;
    calculateSum();
    printResult();
    return 0;
}

