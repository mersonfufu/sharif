#include <stdio.h>

int main(){
	double salario, mensalidade, valor;
	int pessoas;
	char plano;
	scanf("%lf %d %c %lf", &salario, &pessoas, &plano, &mensalidade);
	if(salario <= 1800 && plano == 'E')
		valor = 0.25 * mensalidade * pessoas;
	else if(salario <= 1800 && plano == 'A')
		valor = 0.35 * mensalidade * pessoas;
	else if(salario > 1800 && salario <= 5000 && plano == 'E')
		valor = 0.28 * mensalidade * pessoas;
	else if(salario > 1800 && salario <= 5000 && plano == 'A')
		valor = 0.35 * mensalidade * pessoas;
	else if(salario > 5000 && plano == 'E')
		valor = 0.31 * mensalidade * pessoas;
	else if(salario > 5000 && plano == 'A')
		valor = 0.4 * mensalidade * pessoas;
	if(salario - valor < salario * 0.3){
		printf("DESCONTO NAO AUTORIZADO\n");
		return 0;
	}
	if(plano == 'E' || plano == 'e')
		printf("ENFERMARIA ");
	else if(plano == 'A' || plano == 'a')
		printf("APARTAMENTO ");
	else {
		printf("TIPO DE PLANO INVALIDO\n");
		return 0;
	}
	printf("%.2lf\n", valor);
	return 0;
}