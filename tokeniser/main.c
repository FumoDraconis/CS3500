/*
* cathal walsh 
*/
#include "tokeniser.c"
#include "checkInput.c"
#include "remove_spaces.c"

/*
* call was the functions create to form the tokerniser
*@param: no param
*@returns: 0 if completed without error 1 if errors occur
*/


int main() {
	FILE *tokeniserInputPointer;
	char inputEquation[100];
	tokeniserInputPointer= fopen("tokeniser/tokeniserInput.txt", "r" );
	while (fgets(inputEquation, 100,tokeniserInputPointer) != NULL){
		remove_spaces(inputEquation);
	}
	int checked = checkInput(inputEquation);
	if (checked == 1){	
		return 1;	
	}
	printf("%s\n",inputEquation);
	separator(inputEquation);
	return 0;
}


