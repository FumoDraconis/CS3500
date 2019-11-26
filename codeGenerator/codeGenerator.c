/*
* Adam Cashman
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "codeGenerator.h"
int write_operator ( char *operator ){
/*
* @parameters: Takes the current operator from the buffer
* opens the file that was created earlier again in order to append
* Tries to put the operator into the file
* @return: Returns a 1 on success and a 0 on failure
*/
	FILE *appending_file_pointer;
	appending_file_pointer = fopen("../virtualMachine/codeGeneratorOutput.txt", "a");
	if (fputs(operator, appending_file_pointer) != EOF) {
		fclose(appending_file_pointer);
		return 1;
	} else {
		fclose(appending_file_pointer);
		return 0;
	}
}
int write_float(char buffer[100]) {
/*
* @parameters: Takes the current operator from the buffer
* opens the file that was created earlier again in order to append
* Tries to put the float into the file 
* @returns: Returns a 1 on success and a 0 on failure
*/
	FILE *appending_file_pointer;
	appending_file_pointer = fopen("../virtualMachine/codeGeneratorOutput.txt", "a");
	if (fputs("LOADFLOAT ", appending_file_pointer) != EOF) {
		fputs(buffer, appending_file_pointer);
		fputs("\n", appending_file_pointer);
		fclose(appending_file_pointer);
		return 1;
	} else {
		fclose(appending_file_pointer);
		return 0;
	}
}
int write_int( char buffer[100]) {
/*
* @parameters: Takes the buffer which is the current character
* opens the file that was created earlier again in order to append
* Tries to put the integer into the file 
* returns: Returns a 1 on success and a 0 on failure
*/
	FILE *appending_file_pointer;
	appending_file_pointer = fopen("../virtualMachine/codeGeneratorOutput.txt", "a");
	if (fputs("LOADINT ", appending_file_pointer) != EOF) {
		fputs(buffer, appending_file_pointer);
		fputs("\n", appending_file_pointer);
		fclose(appending_file_pointer);
		return 1;
	} else {
		fclose(appending_file_pointer);
		return 0;
	}
}
int checker(char buffer[100]) {
/*
* @parameters: Takes in the buffer i.e. the current line that was read in from the file
* @Returns: Returns 1 if the correct opeator has been written to the output file
*/
	char *current_operator;
//	checks if the current character is +
	int add_comparison = strcmp(buffer, "+");
//	checks if the current character is -
	int sub_comparison = strcmp(buffer, "-");
//	checks if the current character is *
	int mul_comparison = strcmp(buffer, "*");
//	checks if the current character is /
	int div_comparison = strcmp(buffer, "/");
//	checks if the current character is ^
	int exp_comparison = strcmp(buffer, "^");
//	checks if the current character is %
	int mod_comparison = strcmp(buffer, "%");	
	if (add_comparison == 0) {
//	calls the write_operator function with ADD\n as the parameters
		current_operator = "ADD\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (sub_comparison == 0) {
//	calls the write_operator function with SUB\n as the parameters
		current_operator = "SUB\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (mul_comparison == 0) {
//	calls the write_operator function with MUL\n as the parameters
		current_operator = "MUL\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (div_comparison == 0) {
//	calls the write_operator function with DIV\n as the parameters
		current_operator = "DIV\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (exp_comparison == 0) {
//	calls the write_operator function with EXP\n as the parameters
		current_operator = "EXP\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (mod_comparison == 0) {
//	calls the write_operator function with MOD\n as the parameters
		current_operator = "MOD\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else {
/*
* this checks if the current character is a integer or a float
* does this by checking the current line for a . and if there is it raises a float flag
* then calls the correct writing function
*/
		int float_flag = 0;
		char *sp;
		for ( sp=&buffer[0]; *sp != '\0'; sp++ ) {
			if (*sp == '.') {
				float_flag = 1;
			}
		}
		if (float_flag == 1) {
			if (write_float(buffer) == 1) {
				return 1;
			}
		} else if (isdigit(buffer[0]) != 0){
			if (write_int(buffer) == 1) {
				return 1;
			}
		}
	}return 0;
}
int read_file(char *filename) {
/*
* @parameters: Takes in the infix-to-postfix filename
* @Returns: returns 1 if the correct file is read and 0 if the wrong file is read
* reads the infix-to-postix output file
* creates a new file for the output of the code generator
* iterates through the input file
* calls the checker function on each line of the input file
* closes both files
*/
	FILE *reading_file_pointer;
	FILE *writing_file_pointer;
	writing_file_pointer = fopen("../virtualMachine/codeGeneratorOutput.txt", "w");
	fclose(writing_file_pointer);
	char buffer[100];
	if (fopen(filename, "r")){
		reading_file_pointer = fopen(filename, "r");
	} else {
		return 0;
	}
	while (fscanf(reading_file_pointer, "%s", buffer) != EOF) {
		if (checker(buffer) == 0) {
			return 0;
		} 
	}
	fclose(reading_file_pointer);
	return 1;
}
