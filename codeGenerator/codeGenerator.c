/*
for line in file
	check if operand
		run operand function
	check integer
		run integer function
	else
		run float function

operand function
	if +
		append ADD
	if -
		append SUB
	if *
		append MUL
	if /
		append DIV

integer function
	append LOADINT + the integer

float function
	append LOADFLOAT + the float
*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

void main() {
	FILE *fp;
	char buffer[100];

	fp = fopen("sample_input", "r");
	fscanf(fp, "%s", buffer);
	int string_compare = strcmp(buffer, "=");
	while (string_compare != 0) {
		checker(buffer);
		fscanf(fp, "%s", buffer);
		string_compare = strcmp(buffer, "=");
	}
	fclose(fp);
}

void checker(char buffer[100]) {
	char *current_operator;
	int add_comparison = strcmp(buffer, "+");
	int sub_comparison = strcmp(buffer, "-");
	int mul_comparison = strcmp(buffer, "*");
	int div_comparison = strcmp(buffer, "/");
	if (add_comparison == 0) {
		current_operator = "ADD";
		printf("%s\n", current_operator);
	} else if (sub_comparison == 0) {
		current_operator = "SUB";
		printf("%s\n", current_operator);
	} else if (mul_comparison == 0) {
		current_operator = "MUL";
		printf("%s\n", current_operator);
	} else if (div_comparison == 0) {
		current_operator = "DIV";
		printf("%s\n", current_operator);
	} else {
		int float_flag = 0;
		char *sp;
		for ( sp=&buffer[0]; *sp != '\0'; sp++ ) {
			if (*sp == '.') {
				float_flag = 1;
			}
		}
		if (float_flag == 1) {
			printf("LOADFLOAT %s\n", buffer);
		} else {
			printf("LOADINT %s\n", buffer);
		}
	}
}
