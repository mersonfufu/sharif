#include <stdio.h>

int main(){
	int numero;
	scanf("%d", &numero);
	if(numero < 1)
		printf("Y = %d\n", numero);
	else if(numero == 1)
		printf("Y = %d\n", 0);
	else
		printf("Y = %d\n", numero * numero);
	return 0;
}