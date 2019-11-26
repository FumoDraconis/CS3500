#include <ctap.h>
#include "../vmFunctionality/virtualMachine.h"

double stackTest[100];
int operationsTest[100];
int prevInstIsOpTest = 0;
int stackTopTest = 0;
int operationsLengthTest = 0;

TESTS {
  //Testing prepCalculation:

    // sets up stack and opperations before test
    stackTest[0] = 10.0;
    stackTest[1] = 2.2;
    operationsTest[0] = 1;
    stackTopTest = 1;
    operationsLengthTest = 1;
    //tests 10 + 2.2 does not give any errors
    ok (0 == prepCalculation(stackTest,
                          operationsTest,stackTopTest,
                          operationsLengthTest),
                          "prepCalculation ran with no errors");
    //clears stack and opperations after test
    stackTest[0] = 0;
    stackTest[1] = 0;
    operationsTest[0] = 0;
    stackTopTest = 0;
    operationsLengthTest = 0;


    //sets up 10 / 0
    stackTest[0] = 10.0;
    stackTest[1] = 0;
    operationsTest[0] = 4;
    stackTopTest = 1;
    operationsLengthTest = 1;
    ok (-1 == prepCalculation(stackTest,
                          operationsTest,stackTopTest,
                          operationsLengthTest),
                          "division by 0, handled correctly");
    //clears stack and opperations after test
    stackTest[0] = 0;
    stackTest[1] = 0;
    operationsTest[0] = 0;
    stackTopTest = 0;
    operationsLengthTest = 0;
  //Testing readInstructions
  ok (0 == readInstructions("../codeGeneratorOutput.txt"), "file opened and instructions read succesfully");
  ok (-2 == readInstructions("codeGeneratorOutput"), "file unable to be open, handled succesfully");
  //Testing calculateSumPrintAnswer

}
