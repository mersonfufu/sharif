#include <stdio.h>

int main(){
	int numero, soma = 0, divisor = 1;
	scanf("%d", &numero);
	printf("%d = ", numero);
	while(divisor < numero){
		if(numero % divisor == 0){
			soma += divisor;
			if(divisor > 1)
				printf("+");
			printf("%d ", divisor);
		}
		divisor++;
	}
	if(soma == numero)
		printf(" = %d (NUMERO PERFEITO)", soma);
	else
		printf(" = %d (NUMERO NAO E PERFEITO)", soma);
	return 0;
}