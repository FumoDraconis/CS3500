#include <ctap.h>
#include "../vmFunctionality/calculate.h"

#define add 1
#define mul 2
#define sub 3
#define div 4
#define exponent 5
#define mod 6

TESTS {
  //tests the addition case
  ok (20 == doCalculation(add, 10.0, 10.0), "10 + 10 does equal 20");
  ok (20.8 == doCalculation(add, 10.3, 10.5), "10.3 + 10.5 does equal 20.8");

  //tests the subtraction case
  ok (30 == doCalculation(sub, 45.0, 15.0), "45 - 15 does equal 30");
  ok (29.5 == doCalculation(sub, 45.0, 15.5), "45 - 15.5 does equal 29.5");

  //tests the multiplication case
  ok (7 == doCalculation(mul, 3.5, 2.0), "3.5 * 2.0 does equal 7");
  ok (10.85 == doCalculation(mul, 3.5, 3.1), "3.5 * 3.1 does equal 10.85");

  //tests the division case
  ok (32 == doCalculation(div, 128, 4), "128 / 4 does equal 32");
  ok (60 == doCalculation(div, 30, .5), "30 / .5 does equal 60");

  //tests the exponent case
  ok (729 == doCalculation(exponent, 9, 3), "9 ^ 3 does equal 729");
  //tests the mod case
  ok (4 == doCalculation(mod, 4, 5), "4 % 5 does equal 4");
  ok (1 == doCalculation(mod, 5, 4), "4 % 5 does equal 4");
}
