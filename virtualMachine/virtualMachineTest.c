#include <ctap.h>
#include "virtualMachine.h"



double stackTest[100];
int operationsTest[100];
int prevInstIsOpTest = 0;
int stackTopTest = 0;
int operationsLengthTest = 0;

TESTS {
  stackTest[0] = 10.0;
  stackTest[1] = 2.2;
  operationsTest[0] = 1;
  stackTopTest = 1;
  operationsLengthTest = 1;

  ok (0 == calculateSum(stackTest, operationsTest,stackTopTest, operationsLengthTest), "calculateSum ran with no errors");
}
