#include <stdio.h>

int main(){
	int opcao;
	scanf("%d", &opcao);
	if(opcao == 1)
		printf("char: %d\nchar*: %d", sizeof(char), sizeof(char *));
	else if(opcao == 2)
		printf("short: %d\nshort*: %d", sizeof(short), sizeof(short *));
	else if(opcao == 3)
		printf("int: %d\nint*: %d", sizeof(int), sizeof(int *));
	else if(opcao == 4)
		printf("long int: %d\nlong int*: %d", sizeof(long int), sizeof(long int *));
	else if(opcao == 5)
		printf("float: %d\nfloat*: %d", sizeof(float), sizeof(float *));
	else if(opcao == 6)
		printf("double: %d\ndouble*: %d", sizeof(double), sizeof(double *));
	else if(opcao == 7)
		printf("long double :%d\nlong double*: %d", sizeof(long double), sizeof(long double *));
	return 0;
}