#include <stdio.h>
#include <stdlib.h>

typedef struct __token {
	int type;
	int value;
	int stack[10];
	int sp;

} token;

void print_token(token *t) {
	printf("Token type = %d, value = %d\n", t->type, t->value);
}

token *create_token() {
	token *t= (token *)malloc(sizeof(token));
	t->value = 0;
	t->type = 0;
	return t;
}

int main(int argc, char **argv) {
	//token mytoken;
	token *mytoken = create_token ();
	mytoken->type = 1;
	mytoken->value = 42;
	print_token(mytoken);
	
	free(mytoken);
	char *s = "1.23";
	float f = atof(s);
	printf("%f\n",f);
	return 0;
};

