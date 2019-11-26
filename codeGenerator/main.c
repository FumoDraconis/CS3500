/*
* Adam Cashman
*/
#include "codeGenerator.c"
#include <stdio.h>
void main() {
/*
* defines the filename of the infix-to-postfix output
* calls read_file on that filename
*/
	char *filename = "translatorOutput.txt";
	read_file(filename);
}
