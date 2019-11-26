/*
* cathal walsh 
*/
#include <ctap.h>
#include "../tokeniser.c"
#include "../checkInput.c"
#include "../remove_spaces.c"
TESTS {
	ok(checkInput("1+3") == 0 ,"valid input" );
	ok(checkInput("1") == -1 ,"invalid input its blank" );	
	ok(checkInput("1+s") == -2 ,"invalid input contains letters or special chars " );	
	ok(checkInput("++") == -3,"invalid input opt together ++ " );	
	ok(checkInput("12(+12)") == -4 ,"invalid input 12(+12)" );	
	ok(checkInput(".1+13") == -5 ,"invalid input . at the first " );	
	ok(checkInput("13+1.\n") == -5 ,"invalid input . at the end" );	
	ok(checkInput("(120)12") == -6 ,"invalid input (120)12" );	
	ok(checkInput("(12)(12") == -7 ,"invalid input broken bracks " );	

	ok(separator("12+23")==1,"working input");
	ok(separator("")==0,"not wrting input");
}


