#include <stdio.h>
//global
int cont;
int calcularpiso(int n){
	if(n <= 1)
		return cont;
	cont++;
	return calcularpiso(n / 2);
}

int main(){
	int testes, i, numero;
	scanf("%d", &testes);
	for(i = 0; i < testes; i++){
		scanf("%d", &numero);
		cont = 0;
		calcularpiso(numero);
		printf("%d\n", cont);
	}
	return 0;
}