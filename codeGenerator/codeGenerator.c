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

void main() {
	FILE *fp;
	char buffer[100];

	fp = fopen("sample_input", "r");
	fscanf(fp, "%s", buffer);
	int string_compare = strcmp(buffer, "=");
	while (string_compare != 0) {
		operator_check(buffer);
		fscanf(fp, "%s", buffer);
		string_compare = strcmp(buffer, "=");
	}
	fclose(fp);
}

void operator_check(char buffer[100]) {
	char *current_operator;
	int add_comparison = strcmp(buffer, "+");
	int sub_comparison = strcmp(buffer, "-");
	int mul_comparison = strcmp(buffer, "*");
	int div_comparison = strcmp(buffer, "/");
	if (add_comparison == 0) {
		current_operator = "+";
	} else if (sub_comparison == 0) {
		current_operator = "-";
	} else if (mul_comparison == 0) {
		current_operator = "*";
	} else if (div_comparison == 0) {
		current_operator = "/";
	} else {
		current_operator = "NULL";
	}
	printf("%s\n", current_operator);
}
