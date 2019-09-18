#include <stdio.h>

/**
 * Calcula o fatorial de um numero n.
 * @param n um numero inteiro positivo.
 * @return o fatorial de n.
 */
unsigned long int calcular_fatorial(unsigned int n){
	unsigned long int f = 1;
	for(n; n; n--)
		f *= n;
	return f;
}

int main(){
	unsigned long int n;
	scanf("%lu", &n);
	printf("%lu! = %lu\n", n, calcular_fatorial(n));
	return 0;
}