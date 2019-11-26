#include <ctap.h>
#include "../vmFunctionality/calculate.h"

#define add 1
#define mul 2
#define sub 3
#define div 4
#define exponent 5

TESTS {
  //tests the addition case
  ok (20 == doCalculation(add, 10.0, 10.0), "10 + 10 does equal 20");

  //tests the subtraction case
  ok (30 == doCalculation(sub, 45.0, 15.0), "45 - 15 does equal 30");

  //tests the multiplication case
  ok (7 == doCalculation(mul, 3.5, 2.0), "3.5 * 2.0 does equal 7");

  //tests the division case
  ok (32 == doCalculation(div, 128, 4), "128 / 4 does equal 32");

  TODO("add the exponent test") {
    ok (729 == doCalculation(5, 9, 3), "9 ^ 3 does equal 729");
  }
}
