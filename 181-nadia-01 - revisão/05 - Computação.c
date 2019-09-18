#include <stdio.h>
//#include <stdlib.h>

int main(){
	int testes, numero, digito, i;
	char vetor[99];
	scanf("%d", &testes);
	while(testes--){
		scanf("%d", &numero);
		/*
		itoa(numero,vetor,4);
		printf("%s\n",vetor);
		*/
		digito = 0;
		while(numero != 0){
			vetor[digito++] = numero % 4;
			numero = numero / 4;
		}
		for(i = digito - 1; i >= 0; i--){
			printf("%d", vetor[i]);
			i == 0 ? printf("\n") : 0;
		};
	}
	return 0;
}