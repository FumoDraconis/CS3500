#include <ctap.h>
#include "../vmFunctionality/virtualMachine.h"

TESTS {

  //Testing readInstructions
  ok (0 == readInstructions("../codeGeneratorOutput.txt"), "file opened and instructions read succesfully");
  ok (-2 == readInstructions("codeGeneratorOutput"), "file unable to be open, handled succesfully");
  //Testing calculateSumPrintAnswer

}
