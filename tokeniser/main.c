
#include "tokeniser.c"

//
// runs all the methods in tokerniser 
//
int main(int argc, char **argv ) {
	FILE *tokeniserInputPointer;
	char inputEquation[100];
	tokeniserInputPointer= fopen("tokeniser/tokeniserInput.txt", "r" );
	fscanf(tokeniserInputPointer, "%s",inputEquation);
	int checked = checkInput(inputEquation);
	if (checked == 0){
		return 1;	
	}
	remove_spaces(inputEquation);
	printf("%s\n",inputEquation);
	separator(inputEquation);
	return 0;
}


