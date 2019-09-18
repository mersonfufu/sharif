#include <stdio.h>

int main(){
	int testes, cont = 1, i, j = 1, divisor, soma1, soma2, aux = 0;
	scanf("%d", &testes);
	for(j; cont <= testes; j++){
		//soma dos divisores de j
		soma1 = 0;
		for(divisor = 1; divisor < j; divisor++)
			if(j % divisor == 0)
				soma1 += divisor;
		//soma dos divisores de soma1
		soma2 = 0;
		for(divisor = 1; divisor < soma1; divisor++)
			if(soma1 % divisor == 0)
				soma2 += divisor;
		//comparacao
		if(j != soma1 && j == soma2 && j != aux){
			aux = soma1;
			printf("(%d,%d)\n", j, soma1);
			cont++;
		}
	}
	return 0;
}