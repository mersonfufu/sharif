#include <stdio.h>

int main(){
	int numero;
	scanf("%d", &numero);
	if(numero < 3)
		printf("O VALOR A PAGAR E = %.2f\n", (float)5 * numero);
	else
		printf("O VALOR A PAGAR E = %.2f\n", (float)((numero / 3) * 10 + (numero % 3) * 5));
	return 0;
}