#include <stdio.h>

int main(){
	int numero, c, d, u;
	scanf("%d", &numero);
	c = numero / 100;
	numero = numero - c * 100;
	d = numero / 10;
	numero = numero - d * 10;
	u = numero;
	numero = (c + d * 3 + u * 5) % 7;
	printf("O NOVO NUMERO E = %d%d%d%d\n", c, d, u, numero);
	return 0;
}