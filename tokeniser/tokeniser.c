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

int checkInput(char inputEquation[100]){
	char opt[] = "/*-+.";
	char real_opt[] = "/*-+";
	char fail_opt[] = "().";
	char all_opt[] = "/*-+()";
	int opt_check = 0;
	int breakes_check=0;
	int real_check = 0;
	int lastNumber = strlen(inputEquation);
	int num_brack =0;
	for (int counter = 0; counter < strlen(inputEquation); counter += 1 ){
		if (inputEquation[counter] == '(' || inputEquation[counter] == ')'){
			num_brack ++;
		}
		if(strchr(all_opt,inputEquation[counter])!= NULL ){
			opt_check =1;
		}
		if(strchr(real_opt,inputEquation[counter])!= NULL ){
			real_check =1;
		}
		if(inputEquation[counter] == '('  ){
			breakes_check += 1;
		}
		if ( strlen(inputEquation) <=1) {
			printf("invalid input:\n");
			printf("1");			
			return 0;
		}else if (isalpha(inputEquation[counter]) && inputEquation[counter] != *opt){
			printf("invalid input:\n");
			printf("2");	
			return 0;
		}else if(strchr(opt,inputEquation[counter])!= NULL 				&&strchr(opt,inputEquation[counter +1])!= NULL ){
			printf("invalid input:\n");
			printf("3");	
			return 0;
		}else if(inputEquation[counter] == '(' && isdigit(inputEquation[counter+1])==0 ){
			printf("invalid input:\n");
			printf("4");	
			return 0;
		}else if(inputEquation[0]== '.' || inputEquation[lastNumber-2 ]=='.'){
			printf("invalid input:\n");
			printf("5");	
			return 0;
}
}
	if(opt_check == 0){
			printf("invalid input:\n");
			printf("6");	
			return 0;
}
	if(breakes_check <= 1 && inputEquation[0] == '(' && real_check !=1){
			printf("invalid input:\n");
			printf("7");	
			return 0;			
}
	if(num_brack % 2 !=0 ){
			printf("invalid input:\n");
			printf("8");	
			return 0;	
	} 
	return 1;	
}
void separator(char input[100]){
	FILE *outputFile = fopen("out.txt", "w");
	for (int counter = 0; counter < strlen(input); counter += 1 ){
		char *namePtr = input;
		char data;
		if (isdigit(input[counter])!=0 || input[counter] =='.'){
			fputc(input[counter],outputFile);
			printf( "%c",*(namePtr +counter));
				
                }else if(input[counter]== ')' && input[counter+1] =='(' ){
			printf("\n%c\n",*(namePtr +counter));
			fprintf(outputFile,"\n%c",*(namePtr +counter));
		
 		}else if(input[counter]== ')' ){
			printf("\n%c",*(namePtr +counter));
			fprintf(outputFile,"\n%c",*(namePtr +counter));		

	
		}else if (input[counter] =='(' && isdigit(input[counter-1])!=0){
			printf("\n%c\n",*(namePtr +counter));
			fprintf(outputFile,"\n%c\n",*(namePtr +counter));

                }else if(input[counter] =='(' && isdigit(input[counter-1])==0){
			printf("%c\n",*(namePtr +counter));
			fprintf(outputFile,"%c\n",*(namePtr +counter));

                }else { 
			printf("\n%c\n", *(namePtr + counter));
			fprintf(outputFile,"\n%c\n",*(namePtr +counter));
		}	
	}		
	fclose(outputFile);
}
int main( ) {
	char inputEquation[100];
	printf("enter EQ:");
	fgets(inputEquation, 100, stdin);
	int checked = checkInput(inputEquation);
	if (checked == 0){
		return 0;	
	}
	remove_spaces(inputEquation);
	separator(inputEquation);
	return 0;
}





