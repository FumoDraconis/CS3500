/*
* Adam Cashman
*/
#include "codeGenerator.c"
#include <stdio.h>
int main() {
/*
* defines the filename of the infix-to-postfix output
* calls read_file on that filename
*/
	char *filename = "codeGenerator/translatorOutput.txt";
	read_file(filename);
	return 0;
}
