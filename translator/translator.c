//Author: Patrick O'Donoghue

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char myString[100] = ""; //storage for string manipulation
int len; //initializing len for later use
int top = -1; //current position of the top of the stack
char stack[500]; //array of size 500 for stack
int counter = 0; //initialize counter for later
char newLine = ' '; //constant spacing character
int set = 0; //initialize marker for spaces
int pushTest; //initialize output variable to push method
char failure = 'F'; //constant failure marker

/*
push method gets passed a character. It checks if the current possition exceeds
the max size of the stack. If not, it increments the top marker, places the item
in the stack. Returns 0 for failure and 1 for success
*/
int push(char item){
	if(top >= 500 - 1){
		printf("\n Stack Overflow.\n");
		return 0;
	} else {
		top = top + 1;
		stack[top] = item;
		return 1;
	}
}
/*
pop method gets passed nothing as it is just popping the top item from the Stack.
It checks if there are still items in the stack. If not, it fails and returns F,
otherwise it takes the item from the stack, decrements the top position and Returns
the item
*/
char pop(){
	char item;

	if (top < 0){
		printf("stack under flow: invalid infix expression");
		return failure;
	} else {
		item = stack[top];
		top = top - 1;
		return(item);
	}
}
/*
is_operator method takes in a character, it checks if the character is either a ^,
*, /, +, - or modulus. If it is, it returns 1, else it returns 0
*/
int is_operator(char symbol){
	if(symbol == '^'|| symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-' || symbol =='%'){
		return 1;
	} else {
		return 0;
	}
}
/*
precedence method takes in a character and returns its precedence to other operators
^ returns 3
*, /, % returns 2
+, - returns 1
if its none of these characters it returns 0
*/
int precedence(char symbol)
{

	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/' || symbol =='%')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
/*
The infix to postfix takes in 2 characters, both of which are arrays. The first
array has the infix expression stored in it and the other has an empty postfix
array where the result goes.
It first pushes a "(" to the Stack
It then takes the first item from the infix expresion and does some checks on it
It iterates through the infix expresion until Null character is found
*/
int InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;
	int number = 0;

	pushTest = push('(');// push '(' onto stack
	if(pushTest == 0){ //test if push was successful
		printf("Push failed\n");
		return 1;
	} else {
		pushTest = 0;
	}
	strcat(infix_exp,")");// add ')' to infix expression to close first bracket added
	i=0;
	j=0;
	item=infix_exp[i];//grab first item from infix expresion

	while(item != '\0')//run loop till end of infix expression
	{
		if(item == '(') //if item is (
		{
			pushTest = push(item); //push ( to the stack
			if(pushTest == 0){ // test if push was successful
				printf("Push failed\n");
				return 1;
			} else {
				pushTest = 0;
			}
		}
		else if( isdigit(item) || item == '.') //if character is a digit or point
		{
			postfix_exp[j] = item;//add operand symbol to postfix expr
			j++;
		}
		else if(is_operator(item) == 1) //means symbol is operator
		{
			postfix_exp[j] = newLine; //add new line to postfix expresion to seperate tokens
			j++; //increment marker of postfix expresion
			x=pop(); //get item from stack - items gaurenteed to be on stack as item is an operator
			if(x == 'F'){ //check for success
				return 1;
			}

			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			//while x is an operator and the precedence of x is greater than or equal
			//to the precedence of the previous operator
			{
				postfix_exp[j] = x; //add operator to postfix exression
				j++; //increment pointer
				postfix_exp[j] = newLine; //add a space after operator to seperate tokens
				j++;//increment pointer
				x = pop(); //get next item
				if(x == 'F'){ //test if pop is okay
					return 1;
				}
			}

			pushTest = push(x); //once an operator is not found, push x back to stack
			if(pushTest == 0){ //test if push is successful
				printf("Push failed\n");
				return 1;
			} else {
				pushTest = 0;
			}

			pushTest = push(item); // push current oprerator symbol onto stack
			if(pushTest == 0){ //test if push was successful
				printf("Push failed\n");
				return 1;
			} else {
				pushTest = 0;
			}
		}
		else if(item == ')') // if current item is ')' then
		{
			x = pop(); // pop previous item to this
			if(x == 'F'){ //test pop
				return 1;
			}
			if(set = 0){
				//test to see if space has already been added before current character
				//if there wasn't, add the space, else skip adding
				postfix_exp[j] = newLine;
				j++;
			}

			while(x != '(') // '(' encounterd
			{
				postfix_exp[j] = newLine; //add space
				j++; //increment pointer
				postfix_exp[j] = x; //add current item to postfix expression
				j++;

				x = pop(); //grab previous items on the stack to (
				if(x == 'F'){ //test pop
					return 1; //return failure
				}
				set = 1; //set to mark space has been added already
			}

		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");
			return 1; //return failure
		}
		i++; //increment marker for infix array
		item = infix_exp[i]; /* go to next symbol of infix expression */

	}
	if(top>0) //test stack at the end
	{
		printf("\nInvalid infix Expression\n");
		return 1;
	}

	postfix_exp[j] = '\0'; //add null character to end of array, so translating
												 //to string works easier
	return 0;

}
