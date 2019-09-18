//algoritmo errado
#include <stdio.h>

int main(){
	int testes, t, dv1, dv2, i, soma;
	int cpf[12];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		for(i = 0; i < 11; i++)
			scanf("%d", &cpf[i]);
		soma = 0;
		for(i = 0; i < 9; i++)
			soma = soma + (cpf[i] * (i + 1));
		dv1 = soma % 11 % 10;
		soma = 0;
		for(i = 0; i < 9; i++)
			soma = soma + (cpf[i] * (9 - i));
		dv2 = soma % 11 % 10;
		if(dv1 == cpf[9] && dv2 == cpf[10])
			printf("CPF valido\n");
		else
			printf("CPF invalido\n");
	}
	return 0;
}