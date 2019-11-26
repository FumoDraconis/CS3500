/*
* Adam Cashman
*/	
#include <ctap.h>
#include "../codeGenerator.c"

char *workingFilename = "codeGenerator/translatorOutput.txt";
char *wrongFilename = "Random.txt";

TESTS {
	ok(checker("\"") == 0, "this character does not work with the file");
	ok(checker("+") == 1, "This character does work when it is supposed to");
	ok(checker("%") == 1, "% works");
	ok(read_file(workingFilename) == 1, "This test succeeds as %s exists", workingFilename);
	ok(read_file(wrongFilename) == 0, "This test succeed as %s does not exist", wrongFilename);
}
