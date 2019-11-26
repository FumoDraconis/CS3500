#include <ctap.h>
#include "tokeniser.c"

TESTS {
	ok(1 == 1, "1 does in fact equal 1");

	ok(checkInput("1+3") == 0 ,"valid input" );
	ok(checkInput("1") == -1 ,"invalid input its blank" );	
	ok(checkInput("1+s") == -2 ,"invalid input contains letters or special chars " );	
	ok(checkInput("++") == -3,"invalid input opt together ++ " );	
	ok(checkInput("12(+12)") == -4 ,"invalid input " );	
	ok(checkInput(".1+13") == -5 ,"invalid input . at the first " );	
	ok(checkInput("13+1.\n") == -5 ,"invalid input . at the end" );	
	ok(checkInput("(120)12") == -6 ,"invalid input (120)12" );	
	ok(checkInput("(12)(12") == -7 ,"invalid input broken bracks " );	
	
	ok(separator("12+23")==0,"working input");
	//ok(separator("1") == 7 ,"if it a digit" );
	//ok(separator(")(") == 8, "if its )( ");
	//ok(separator(")") == 9 ,"if it a )");
	//ok(separator("12(230)") == 10,"if it 12(230)" );
	//ok(separator("1(") == 11, "if ti 1(");
	//ok(separator("+(") == 12,"if it +(" );
	
}


