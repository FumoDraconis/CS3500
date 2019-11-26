#include <ctap.h>
#include "printResult.h"


TESTS {
  //test should verify that formated output of 12.000 should be an integer
  ok( 1 == printFormattedAnswer(12.000),
      "12.000 is formated to an integer: 12");

  //test should verify that 12.001 should remain a float
  ok( 0 == printFormattedAnswer(12.001),"12.001 is not formated to an integer");
}
