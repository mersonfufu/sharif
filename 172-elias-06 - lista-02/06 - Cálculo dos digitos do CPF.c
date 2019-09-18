#include <stdio.h>

/**
 * Calcula os digitos verificadores do CPF.
 * @param n os 9 primeiros digitos do CPF do qual se quer descobrir os verificadores.
 * @return os digitos verificadores do cpf.
 */
int calcular_verificadores(int n){
	int i, soma;
	int cpf[10] = {99};
	for(i = 8; i >= 0; i--){
		cpf[i] = n % 10;
		n /= 10;
	}
	//digito-10
	soma = 0;
	for(i = 0; i < 9; i++)
		soma += cpf[i] * (10 - i);
	soma % 11 == 0 || soma % 11 == 1 ? (cpf[9] = 0) : (cpf[9] = 11 - soma % 11); //digito-11
	soma = 0;
	for(i = 0; i < 10; i++)
		soma += cpf[i] * (11 - i);
	soma % 11 == 0 || soma % 11 == 1 ? (cpf[10] = 0) : (cpf[10] = 11 - soma % 11);
	i = cpf[9] * 10 + cpf[10];
	return i;
}

int main(){
	int n, i;
	scanf("%d", &n);
	i = calcular_verificadores(n);
	i <= 9 ? printf("0%d", i) : printf("%d", i);
	return 0;
}