/*
* cathal walsh 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
*removes spaces from the inputEquation enter by the user from the file
*@param: input from file 
*@returns: input without spaces
*/

void remove_spaces(char* s) {
    //printf("%s",s);
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
	
}
