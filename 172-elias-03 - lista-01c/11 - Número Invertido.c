#include <stdio.h>

int main(){
	int numero, c, d, u;
	scanf("%d", &numero);
	c = numero / 100;
	numero = numero - c * 100;
	d = numero / 10;
	numero = numero - d * 10;
	printf("%d%d%d\n", numero, d, c);
	return 0;
}