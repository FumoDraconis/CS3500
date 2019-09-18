#include <stdio.h>
#include <stdlib.h>

int main( ) {
	char sum[100];
	FILE *OutPutFile;
	
	printf( "enter EQ:\n");
	fgets(sum,100,stdin);
		
	printf ("entered: %s", sum);
	getchar();

	OutPutFile = fopen("out.txt", "w");
	fputs(sum ,OutPutFile);
	

	fclose(OutPutFile);



	return 0;
}
