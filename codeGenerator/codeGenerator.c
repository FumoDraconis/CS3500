#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void checker(char buffer[100], FILE *writing_file_pointer) {
	char *current_operator;
	int add_comparison = strcmp(buffer, "+");
	int sub_comparison = strcmp(buffer, "-");
	int mul_comparison = strcmp(buffer, "*");
	int div_comparison = strcmp(buffer, "/");
	int eq_comparison = strcmp(buffer, "=");
	if (add_comparison == 0) {
		current_operator = "ADD\n";
		fputs(current_operator, writing_file_pointer);
		printf("%s", current_operator);
	} else if (sub_comparison == 0) {
		current_operator = "SUB\n";
		fputs(current_operator, writing_file_pointer);
		printf("%s", current_operator);
	} else if (mul_comparison == 0) {
		current_operator = "MUL\n";
		fputs(current_operator, writing_file_pointer);
		printf("%s", current_operator);
	} else if (div_comparison == 0) {
		current_operator = "DIV\n";
		fputs(current_operator, writing_file_pointer);
		printf("%s", current_operator);
	} else {
		int float_flag = 0;
		char *sp;
		for ( sp=&buffer[0]; *sp != '\0'; sp++ ) {
			if (*sp == '.') {
				float_flag = 1;
			}
		}
		if (float_flag == 1) {
			fputs("LOADFLOAT ", writing_file_pointer);
			fputs(buffer, writing_file_pointer);
			fputs("\n", writing_file_pointer);
			printf("LOADFLOAT %s\n", buffer);
		} else {
			fputs("LOADINT ", writing_file_pointer);
			fputs(buffer, writing_file_pointer);
			fputs("\n", writing_file_pointer);
			printf("LOADINT %s\n", buffer);
		}
	}
}
void main() {
	FILE *reading_file_pointer;
	FILE *clearing_file_pointer;
	FILE *writing_file_pointer;
	char buffer[100];
	reading_file_pointer = fopen("translatorOutput.txt", "r");
	clearing_file_pointer = fopen("../virtualMachine/codeGeneratorOutput.txt", "w");
	writing_file_pointer = fopen("../virtualMachine/codeGeneratorOutput.txt", "a");
	fclose(clearing_file_pointer);
	fscanf(reading_file_pointer, "%s", buffer);
	int string_compare = strcmp(buffer, "\0");
	while (string_compare != 0) {
		checker(buffer, writing_file_pointer);
		fscanf(reading_file_pointer, "%s", buffer);
		string_compare = strcmp(buffer, "=");
	}
	fclose(reading_file_pointer);
	fclose(writing_file_pointer);
}
