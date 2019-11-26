//Author: Patrick O'Donoghue
#include "translator.c"

int main(){
	char var[100]; //storage for token when iterating through
	int test; //target for reponce to
	FILE *file; //target file
	file = fopen("tokeniserOutput.txt","r");
	/*
		while the current item in the input file isn't equal to NULL keep iterating
		over the file. Add the current selected item to myString
	*/
	while(fgets(var, sizeof(var), file)!=NULL){

		len = strlen(var);
		strncat(myString, var, len-1);

		counter = counter + 1;
	}

	fclose(file);
  len = strlen(myString); //calculate len of string to gaurentee space in the arrays

	char infix[counter*2], postfix[counter*2]; // defining space for input and output

	strcpy(infix, myString); //pass myString into array for easier use

	test = InfixToPostfix(infix, postfix); //call Infix to Postfix, editing postfix to give result
																				 //returns 0 if passed and 1 if failed
	if (test == 0){ //testing to see if infix to postfix passed
		myString[0] = '\0'; //clear myString
		len = strlen(postfix); //len of output for strncat buffer and iterate over the array
		strncat(myString, postfix, len); //add postfix answer back to myString
		FILE *filepointer; //point to file
		filepointer = fopen("../codeGenerator/translatorOutput.txt", "w");
		//open file to write answers to
		for(int i = 0; i < len; i++){ //iterate over the sting to output to files
			if(myString[i] == ' '){ //if the current item is a space
				fprintf(filepointer, "\n"); //add new line
			} else {
				fprintf(filepointer,"%c", myString[i]); //add current token to file
			}
		}
		fclose(filepointer); //close file
	} else {
		printf("Failed\n"); //print failed if output wasn't executed
	}

	return 0;
}
