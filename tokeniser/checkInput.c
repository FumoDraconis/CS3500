/*
* cathal walsh 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
*checkes the input equation to make sure it a valid equation 
*@param: input from file 
*@returns: 0 if works -1,-2,-3,-4,-5,-6,-7 if failed 
*/
int checkInput(char inputEquation[100]){
	char opt[] = "/*-+.^%";
	char real_opt[] = "/*-+^%";
	char fail_opt[] = "().";
	char all_opt[] = "/*-+().^%";
	char dot_les[] = "/*-+()^%";
	int opt_check = 0;
	int real_check = 0;
	int ch = 0;
	int num_brack =0;
	int neg_check =0;  
	int lastNumber = strlen(inputEquation);
	// intertgrates over the whole equation one character at a time 
	for (int counter = 0; counter < strlen(inputEquation); counter += 1 ){
		// check if the character is a number from 0 to 9 or if that character is equal to a (/,*,-,+,.,%,^) otherwise ch = 1 used later 
		if (inputEquation[counter-1]>='0' && inputEquation[counter-1]<='9' || strchr(all_opt,inputEquation[counter-1])!= NULL ){
			ch = 0;
		}else{
			ch =1;		
		}
		// if the currently charatcer is = to a ( or a ) add 1 to the brack counter 
		if (inputEquation[counter] == '(' || inputEquation[counter] == ')'){
			num_brack ++;
		}
		// check if the equation contents a opt /,*,-,+,(,),. used to make sure there is opteraion in the equation
		if(strchr(all_opt,inputEquation[counter])!= NULL ){
			opt_check =1;
		}
		// check if the equation contents a opt  /,*,-,+ used to check () problem later
		if(strchr(real_opt,inputEquation[counter])!= NULL ){
			real_check =1;
		}
		// checks if the inputEquation is less then a single characters
		if ( strlen(inputEquation) <=1) {
			printf("invalid input:\n");	
			return -1;
		// checks if the current chara is a letter and not a opt /,*,-,+,. and the early check was false 
		}else if (isalpha(inputEquation[counter]) && inputEquation[counter] != *opt || ch ==1  ){
			printf("invalid input:\n");
			return -2;
		// checks is current char and the next character are both opt /,*,-,+,.,%,^ 
		}else if(strchr(opt,inputEquation[counter])!= NULL &&strchr(opt,inputEquation[counter +1])!= NULL ){
			printf("invalid input:\n");
			return -3;
		// checks that the current char = ( and the next char is not a digit and not ( 
		}else if(inputEquation[counter] == '(' && isdigit(inputEquation[counter+1])==0 && inputEquation[counter+1] != '(' ){
			// checks if the next character is a - 	
			if(inputEquation[counter+1]!='-'){
			printf("invalid input:\n");
			return -4;
		}
		// checks if the first character is a . or is the last character is a . 
		}else if(inputEquation[0]== '.' || inputEquation[lastNumber-2 ]=='.'){
			printf("invalid input:\n");
			return -5;
		//	checks if the current char = ) and the next character is not in /,*,-,+,(,),^,% and the last characher is not a )
		}else if(inputEquation[counter]== ')' && strchr(dot_les,inputEquation[counter + 1])== NULL &&inputEquation[lastNumber-2 ]!= ')' ){
			printf("invalid input:\n");
			return -6;
			}
		}
		// check that the number of brackes is even if not invalid input
		if(num_brack % 2 !=0 ){
			printf("invalid input:\n");
			return -7;	
		} 
	return 0;	
}
