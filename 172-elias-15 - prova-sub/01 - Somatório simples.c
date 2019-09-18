#include <stdio.h>
int main(){
	int n, cont = 2;
	double soma = 0; //entrada
	scanf("%d", &n); //saida
	if(n < 3)
		printf("Numero invalido!");
	else {
		while(cont <= n){
			soma = soma + ((float)n / (cont * cont));
			cont++;
		}
		soma += n;
		printf("%.5f", soma);
	}
	return 0;
}