#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//
// removes spaces from the inputEquation enter by the user from the file
//
void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
//
// checkes the input equation to make sure it a valid equation 
//
int checkInput(char inputEquation[100]){
	char opt[] = "/*-+.^";
	char real_opt[] = "/*-+^";
	char fail_opt[] = "().";
	char all_opt[] = "/*-+().^";
	char dot_les[] = "/*-+()^";
	int opt_check = 0;
	int real_check = 0;
	int ch = 0;
	int num_brack =0;
	int neg_check =0;  
	int lastNumber = strlen(inputEquation);
	//
	// intertgrates over the whole equation one character at a time 
	//
	for (int counter = 0; counter < strlen(inputEquation); counter += 1 ){
		//
		// check if the character is a number from 0 to 9 or if that character is equal to a (/,*,-,+,.,%,^) otherwise ch = 1 used later 
		//
		if (inputEquation[counter-1]>='0' && inputEquation[counter-1]<='9' || strchr(all_opt,inputEquation[counter-1])!= NULL ){
			ch = 0;	
		}else{
			ch =1;		
		}
		//
		// if the currently charatcer is = to a ( or a ) add 1 to the brack counter 
		//
		if (inputEquation[counter] == '(' || inputEquation[counter] == ')'){
			num_brack ++;
		}
		//
		// check if the equation contents a opt /,*,-,+,(,),. used to make sure there is opteraion in the equation
		//
		if(strchr(all_opt,inputEquation[counter])!= NULL ){
			opt_check =1;
		}
		//
		// check if the equation contents a opt  /,*,-,+ used to check () problem later
		//
		if(strchr(real_opt,inputEquation[counter])!= NULL ){
			real_check =1;=
		}
		//
		// checks if the inputEquation is less then a single characters
		//
		if ( strlen(inputEquation) <=1) {
			printf("invalid input:\n");	
			return -1;
		//
		// checks if the current chara is a letter and not a opt /,*,-,+,. and the early check was false 
		//
		}else if (isalpha(inputEquation[counter]) && inputEquation[counter] != *opt || ch ==1  ){
			printf("invalid input:\n");
			return -2;
		//
		// checks is current char and the next character are both opt /,*,-,+,.,%,^ 
		//
		}else if(strchr(opt,inputEquation[counter])!= NULL &&strchr(opt,inputEquation[counter +1])!= NULL ){
			printf("invalid input:\n");
			return -3;
		//
		// checks that the current char = ( and the next char is not a digit and not ( 
		//
		}else if(inputEquation[counter] == '(' && isdigit(inputEquation[counter+1])==0 && inputEquation[counter+1] != '(' ){
			//
			// checks if the next character is a - 
			//	
			if(inputEquation[counter+1]!='-'){
			printf("invalid input:\n");
			return -4;
		}
		//
		// checks if the first character is a . or is the last character is a . 
		//
		}else if(inputEquation[0]== '.' || inputEquation[lastNumber-2 ]=='.'){
			printf("invalid input:\n");
			return -5;
		//
		//	checks if the current char = ) and the next character is not in /,*,-,+,(,),^,% and the last characher is not a )
		//
		}else if(inputEquation[counter]== ')' && strchr(dot_les,inputEquation[counter + 1])== NULL &&inputEquation[lastNumber-2 ]!= ')' ){
			printf("invalid input:\n");
			return -6;
			}
		}
		//
		// check that the number of brackes is even if not invalid input
		//
		if(num_brack % 2 !=0 ){
			printf("invalid input:\n");
			return -7;	
		} 
	return 0;	
}
//
// breakes the input equation in to line basic on if it a number or opt 
// 
int separator(char input[100]){
	//
	// opnes a write file 
	//
	FILE *outputFile = fopen("translator/tokeniserOutput.txt", "w");
	//
	// loop thought every charcter in the equation 
	//
	for (int counter = 0; counter < strlen(input); counter += 1 ){
		char *namePtr = input;
		char data;
		//
		// if the current char is a digit or a . write it to the file
		//
		if (isdigit(input[counter])!=0 || input[counter] =='.'){
			fputc(input[counter],outputFile);
		//
		// if the current char = ) and the next one is a ( write it to the file with a * between on separated lines	
		//
                }else if(input[counter]== ')' && input[counter+1] =='(' ){
			fprintf(outputFile,"\n%c\n*\n",*(namePtr +counter));
		//
		// if the current char = ) write it to the file on a separated line
		//
 		}else if(input[counter]== ')' ){
			fprintf(outputFile,"\n%c",*(namePtr +counter));		
		//
		// if the current char = ( and the prev char is a digit write it to the file with a * between them or separated lines	
		//
		}else if (input[counter] =='(' && isdigit(input[counter-1])!=0){
			fprintf(outputFile,"\n*\n%c\n",*(namePtr +counter));
		//
		// if the current char = ( and the is not a digit write it to the file on separated lines	
		//
                }else if(input[counter] =='(' && isdigit(input[counter-1])==0){
			fprintf(outputFile,"%c\n",*(namePtr +counter));
		//
		// else just write it to the file with on separated lines	
		//
		}else { 
			fprintf(outputFile,"\n%c\n",*(namePtr +counter));
		}	
	}	
	//
	//close the file
	//		
	fclose(outputFile);
	return 0;
}








