#include <stdio.h>

void troca_valores(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int a, b, *p;
	scanf("%d %d", &a, &b);
	troca_valores(&a, &b);
	printf("%d %d", a, b);
	return 0;
}