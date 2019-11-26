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

  ok (InfixToPostfix(infix1, postfix1) == 0, "Infix to postfix successful with correct input");

  strncat(infix1, "*", 2);
  ok (InfixToPostfix(infix1, postfix1) == 1, "Infix to Postfix successful result with incorrect input");

  ok (push(three) == 1, "Push method successful with empty stack");
  top = 1000;
  ok (push(three) == 0, "Push method successful result with full stack");
  top = 0;

  ok (pop() == three, "Pop successful with items in stack");
  ok (pop() == 'F', "Pop successful result with empty stack");

  ok (is_operator(mul) == 1, "Multiply operator correct result");
  ok (is_operator(add) == 1, "Add operator correct result");
  ok (is_operator(fail) == 0, "Incorrect input outputing correct result");

  ok (precedence(power) == 3, "Precedence returned correctly");
  ok (precedence(mul) == 2, "Precedence returned correctly");
  ok (precedence(add) == 1, "Precedence returned correctly");
  ok (precedence(fail) == 0, "Precedence returned correctly");


}
