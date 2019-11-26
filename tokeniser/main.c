/*
* cathal walsh 
*/
#include "tokeniser.c"
#include "checkInput.c"

/*
* call was the functions create to form the tokerniser
*@param: no param
*@returns: 0 if completed without error 1 if errors occur
*/
void remove_spaces(char string[]) {

    const char* d = string;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*string++ = *d++);
}

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
	
	

	
	separator(inputEquation);
	return 0;
}


