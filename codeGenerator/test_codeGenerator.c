#include <ctap.h>
#include "codeGenerator.c"

TESTS {
	ok(checker("\"") == 0, "this character does not work with the file");
	ok(checker("_") == 0, "This character does not work when it's not supposed to");
}
