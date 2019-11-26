#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//
// removes spaces from the inputEquation enter by the user from the file
//
char remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
	return *s;
}
