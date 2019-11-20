#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_spaces(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

void separator(char input[100]){
	FILE *outputFile = fopen("out.txt", "w");
 	char afshsdfuiah;

	char legnth = strlen(input);


	for (int counter = 0; counter < strlen(input); counter += 1 ){
		char *namePtr = input;
		if (isdigit(input[counter])==0 || input[counter] == '.'){
			printf( "\n%c\n",*(namePtr +counter));	
			}else{	
				printf("%c", *(namePtr + counter));		
							
	
			
}

}		
}
//if (random == "+" || random == "-" || random == "/" || random == "*" ){
//			printf("Works here3");
//			afshsdfuiah = "\n";
//			afshsdfuiah += input[counter];
//			afshsdfuiah += "\n";
//			}
//		printf("%d", afshsdfuiah );
//		fputs(afshsdfuiah, outputFile);
//	}
//	fclose(outputFile);
//}


int main( ) {
	char inputEquation[100];
	
	printf("enter EQ:\n");

	fgets(inputEquation, 100, stdin);
	if (inputEquation )

	remove_spaces(inputEquation);

	printf("%s",inputEquation);


	separator(inputEquation);

	return 0;
}


