#include <stdio.h>

int main(){
	int dinheiro, n100, n50, n10, m1;
	float aux;
	scanf("%d", &dinheiro);
	n100 = dinheiro / 100;
	dinheiro = dinheiro - n100 * 100;
	n50 = dinheiro / 50;
	dinheiro = dinheiro - n50 * 50;
	n10 = dinheiro / 10;
	dinheiro = dinheiro - n10 * 10;
	printf("NOTAS DE 100 = %d\n", n100);
	printf("NOTAS DE 50 = %d\n", n50);
	printf("NOTAS DE 10 = %d\n", n10);
	printf("MOEDAS DE 1 = %d\n", dinheiro);
	return 0;
}