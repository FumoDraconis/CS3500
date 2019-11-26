/*
* cathal walsh 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*
*writes out to the file separating the input
*@param: input from file 
*@returns: 1 if works 0 if failed 
*/
int separator(char input[100]){
	// opnes a write file 
	int flag = 0;
	FILE *outputFile = fopen("translator/tokeniserOutput.txt", "w");
	// loop thought every charcter in the equation 
	for (int counter = 0; counter < strlen(input); counter += 1 ){
		char *namePtr = input;
		char data;
		// if the current char is a digit or a . write it to the file
		if (isdigit(input[counter])!=0 || input[counter] =='.'){
			fputc(input[counter],outputFile);
			flag = 1;
		// if the current char = ) and the next one is a ( write it to the file with a * between on separated lines	
                }else if(input[counter]== ')' && input[counter+1] =='(' ){
			fprintf(outputFile,"\n%c\n*\n",*(namePtr +counter));
			flag = 1;
		// if the current char = ) write it to the file on a separated line
 		}else if(input[counter]== ')' ){
			fprintf(outputFile,"\n%c",*(namePtr +counter));	
			flag = 1;	
		// if the current char = ( and the prev char is a digit write it to the file with a * between them or separated lines	
		}else if (input[counter] =='(' && isdigit(input[counter-1])!=0){
			fprintf(outputFile,"\n*\n%c\n",*(namePtr +counter));
			flag = 1;
		// if the current char = ( and the is not a digit write it to the file on separated lines	
                }else if(input[counter] =='(' && isdigit(input[counter-1])==0){
			fprintf(outputFile,"%c\n",*(namePtr +counter));
			flag = 1;
		// else just write it to the file with on separated lines	
		}else { 
			fprintf(outputFile,"\n%c\n",*(namePtr +counter));
			flag = 1;
		}	
	}
	//close the file
	fclose(outputFile);
	if (flag == 1){	
		return 1;	
	}else{
		return 0;
	}
}







