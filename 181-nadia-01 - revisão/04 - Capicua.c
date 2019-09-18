#include <stdio.h>

int main(){
	int testes, numero;
	scanf("%d", &testes);
	while(testes--){
		scanf("%d", &numero);
		if(numero / 1000 == numero % 10 && (numero / 100) % 10 == (numero / 10) % 10)
			printf("S\n");
		else
			printf("N\n");
	}
	return 0;
}