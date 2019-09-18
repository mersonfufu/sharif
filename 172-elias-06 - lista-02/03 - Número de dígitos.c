#include <stdio.h>

/**
 * Conta a quantidade de digitos de um numero inteiro.
 * @param n um numero inteiro.
 * @return quantidade de digitos de n.
 */
int contar_digitos(long int n){
	int i = 0;
	while(n != 0){
		n /= 10;
		i++;
	}
	return i;
}

int main(){
	long int n;
	scanf("%ld", &n);
	n == 0 ? printf("Numero de digitos: 1") : printf("Numero de digitos: %d", contar_digitos(n));
	return 0;
}