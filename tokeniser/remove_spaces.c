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

void remove_spaces(char string[]) {
    const char* d = string;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*string++ = *d++);
    
}
