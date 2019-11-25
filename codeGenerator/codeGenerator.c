#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void checker(char buffer[100], FILE *writing_file_pointer) {
	char *current_operator;
	int add_comparison = strcmp(buffer, "+");
	int sub_comparison = strcmp(buffer, "-");
	int mul_comparison = strcmp(buffer, "*");
	int div_comparison = strcmp(buffer, "/");
    int exp_comparison = strcmp(buffer, "^");
	if (add_comparison == 0) {
		current_operator = "ADD\n";
		fputs(current_operator, writing_file_pointer);
	} else if (sub_comparison == 0) {
		current_operator = "SUB\n";
		fputs(current_operator, writing_file_pointer);
	} else if (mul_comparison == 0) {
		current_operator = "MUL\n";
		fputs(current_operator, writing_file_pointer);
	} else if (div_comparison == 0) {
		current_operator = "DIV\n";
		fputs(current_operator, writing_file_pointer);
	} else if (exp_comparison == 0) {
        current_operator = "EXP\n";
        fputs(current_operator, writing_file_pointer);
    }  else {
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
		} else {
			fputs("LOADINT ", writing_file_pointer);
			fputs(buffer, writing_file_pointer);
			fputs("\n", writing_file_pointer);
		}
	}
}
int main() {
	FILE *reading_file_pointer;
	FILE *clearing_file_pointer;
	FILE *writing_file_pointer;
	char buffer[100];
	reading_file_pointer = fopen("codeGenerator/translatorOutput.txt", "r");
	clearing_file_pointer = fopen("virtualMachine/codeGeneratorOutput.txt", "w");
	writing_file_pointer = fopen("virtualMachine/codeGeneratorOutput.txt", "a");
	fclose(clearing_file_pointer);
	while (fscanf(reading_file_pointer, "%s", buffer) != EOF) {
		checker(buffer, writing_file_pointer);
	}
	fclose(reading_file_pointer);
	fclose(writing_file_pointer);
	return 0;
}
