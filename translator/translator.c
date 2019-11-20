#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char myString[100] = "";
char space[1] = " ";
int len;
int top = -1;
char stack[500];
int counter = 0;
char newLine = ' ';



void push(char item){
	if(top >= 100 - 1){
		printf("\n Stack Overflow.");
	} else {
		top = top + 1;
		stack[top] = item;
	}
}

char pop(){
	char item;

	if (top < 0){
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	} else {
		item = stack[top];
		top = top - 1;
		return(item);
	}
}

int is_operator(char symbol){
	if(symbol == '^'|| symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-' ){
		return 1;
	} else {
		return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
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

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;
	int number = 0;

	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */
	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/
	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item) || item == '.')
		{
			postfix_exp[j] = item;              /* add operand symbol to postfix expr */
			j++;
			number = 1;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = newLine;                  /* so pop all higher precendence operator and */
				j++;
				postfix_exp[j] = x;                  /* so pop all higher precendence operator and */
				j++;
				x = pop();                       /* add them to postfix expresion */
			}
			postfix_exp[j] = newLine;
			j++;

			push(x);
			/* because just above while loop will terminate we have
			oppped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();
			postfix_exp[j] = newLine;                  /* so pop all higher precendence operator and */
			j++;                  /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
			//postfix_exp[j] = newLine;                  /* so pop all higher precendence operator and */
			//j++;
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.pepe\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* go to next symbol of infix expression */
		//postfix_exp[j] = newLine;
		//j++;
		//push(newLine);
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression. hehe\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression. tete\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

}


int main(){
	char var[100];
	int test = 0;
	FILE *file;
	file = fopen("sample","r");
	while(fgets(var, sizeof(var), file)!=NULL){

		//infix[counter] = var;
		len = strlen(var);
		strncat(myString, var, len-1);

		//strncat(myString, space, 1);
		counter = counter + 1;
	}

	fclose(file);
	char infix[counter*2], postfix[counter*2];
	//strcpy(infix, myString);
	#define SIZE counter
	strcpy(infix, myString);
	//puts(infix);
	InfixToPostfix(infix, postfix);
	printf("%s\n", postfix);

	return 0;
}




/*https://www.includehelp.com/c/infix-to-postfix-conversion-using-stack-with-c-program.aspx*/
