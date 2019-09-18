#include <stdio.h>

/**
 * Le um numero double via terminal e retorna seu valor.
 * @return n o valor lido.
 */
double ler_numero(){
	double n;
	scanf("%lf", &n);
	return n;
}

int main(){
	int casos, i;
	double soma = 0;
	scanf("%d", &casos);
	for(i = 0; i < casos; i++)
		soma += ler_numero();
	printf("%.2lf\n", soma / casos);
	return 0;
}