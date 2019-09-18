#include <stdio.h>
#include <stdlib.h>

int main( ) {
	char inputEquation[100];
	
	printf("enter EQ:\n");
	fgets(inputEquation, 100, stdin);	

	FILE *outputFile = fopen("out.txt", "w");
	fputs(inputEquation, outputFile);
	fclose(outputFile);

	return 0;
}
