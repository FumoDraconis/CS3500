#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int write_operator ( char *operator ){
	FILE *appending_file_pointer;
	appending_file_pointer = fopen("codeGeneratorOutput.txt", "a");
	if (fputs(operator, appending_file_pointer) != EOF) {
		fclose(appending_file_pointer);
		return 1;
	} else {
		fclose(appending_file_pointer);
		return 0;
	}
}

int write_float(char buffer[100]) {
	FILE *appending_file_pointer;
	appending_file_pointer = fopen("codeGeneratorOutput.txt", "a");
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
	FILE *appending_file_pointer;
	appending_file_pointer = fopen("codeGeneratorOutput.txt", "a");
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
	char *current_operator;
	int add_comparison = strcmp(buffer, "+");
	int sub_comparison = strcmp(buffer, "-");
	int mul_comparison = strcmp(buffer, "*");
	int div_comparison = strcmp(buffer, "/");
	int exp_comparison = strcmp(buffer, "^");
	int mod_comparison = strcmp(buffer, "%");
	if (add_comparison == 0) {
		current_operator = "ADD\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (sub_comparison == 0) {
		current_operator = "SUB\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (mul_comparison == 0) {
		current_operator = "MUL\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (div_comparison == 0) {
		current_operator = "DIV\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (exp_comparison == 0) {
		current_operator = "EXP\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	} else if (mod_comparison == 0) {
		current_operator = "MOD\n";
		if (write_operator(current_operator) == 1) {
			return 1;
		}
	}else {
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
	}
	return 0;
}


int read_file(char *filename) {
	FILE *reading_file_pointer;
	FILE *writing_file_pointer;
	writing_file_pointer = fopen("codeGeneratorOutput.txt", "w");
	fclose(writing_file_pointer);
	char buffer[100];
	reading_file_pointer = fopen(filename, "r");
	while (fscanf(reading_file_pointer, "%s", buffer) != EOF) {
		if (checker(buffer) == 0) {
			return 0;
		} 
	}
	fclose(reading_file_pointer);
	return 1;

}
