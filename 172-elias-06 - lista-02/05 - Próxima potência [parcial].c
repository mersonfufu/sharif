#include <stdio.h>

/**
 * Calcula b multiplicada por ele mesmo um numero e-nesimo de vezes.
 * @param b valor da base.
 * @param e valor do expoente.
 * @return potencia b elevado a e.
 */
long int potencia_simples(int b, int e){
	int i;
	long int potencia = 1;
	for(i = 0; i < e; i++)
		potencia *= b;
	return potencia;
}

/**
 * Calcula a potencia de p mais proximo a n.
 * @param n valor inteiro.
 * @param p valor da potencia.
 * @return valor da potencia mais proxima.
 */
int potencia_mais_proxima(int n, int p){
	int i = 2;
	while(potencia_simples(i + 1, p) < n)
		i++;
	return i;
}

int main(){
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d -> %d^%d = %d",
		n,
		potencia_mais_proxima(n, p),
		p,
		potencia_simples(
			potencia_mais_proxima(n, p),
			p
		)
	);
	return 0;
}