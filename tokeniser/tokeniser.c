#include <stdio.h>
#include <stdlib.h>

int main( ) {
	char str[100];
	FILE *ofp;

	ofp = fopen("out.txt", "");
	
	if(ofp == NULL)
	{
		printf("Error!");
		exit(1);
	}	
	
	printf( "enter EQ:\n");
	fgets(str,100,stdin);
	
	fprintf(ofp,"%s",str);	
	fclose(ofp);


	//printf ("entered: %s", str);

	//getchar();

	return 0;
}
