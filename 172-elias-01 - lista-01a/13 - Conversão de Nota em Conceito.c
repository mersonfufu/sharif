#include <stdio.h>

int main(){
	float nota;
	scanf("%f", &nota);
	printf("NOTA = %.1f CONCEITO = ", nota);
	if(nota >= 9)
		printf("A");
	else if(nota >= 7.5)
		printf("B");
	else if(nota >= 6)
		printf("C");
	else if(nota >= 0)
		printf("D");
	printf("\n");
	return 0;
}