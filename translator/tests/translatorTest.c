#include <ctap.h>
#include "../translator.c"

char three = '3';
char mul = '*';
char divide = '/';
char add = '+';
char fail = '$';
char power = '^';




TESTS {

  char infixInput[100] = "";
  char infix1[100], postfix1[100];

  strncat(infixInput, "(10^2)*(5+5+5+5)/10000", 25);
  strcpy(infix1, infixInput);

  ok (InfixToPostfix(infix1, postfix1) == 0, "Success");

  ok (push(three) == 1, "success");
  top = 1000;
  ok (push(three) == 0, "successful");
  top = 0;

  ok (pop() == three, "success");
  ok (pop() == 'F', "success");

  ok (is_operator(mul) == 1, "Success");
  ok (is_operator(add) == 1, "Success");
  ok (is_operator(fail) == 0, "Success");

  ok (precedence(power) == 3, "Success");
  ok (precedence(mul) == 2, "Success");
  ok (precedence(add) == 1, "Success");
  ok (precedence(fail) == 0, "Success");


}
