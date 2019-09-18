#include <stdio.h>

int main(){
	int n, cont = 2;
	double soma = 0;
	scanf("%d", &n);
	if(n < 1){
		printf("Numero invalido!");
		return 0;
	} else {
		while(cont <= n){
			soma = soma + (1.0 / cont);
			cont++;
		}
		soma++;
		printf("%f", soma);
	}
	return 0;
}