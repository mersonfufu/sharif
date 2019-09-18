#include <stdio.h>

int main(){
	int conta;
	float consumo;
	char tipo;
	scanf("%d %f %c", &conta, &consumo, &tipo);
	if(tipo == 'r' || tipo == 'R')
		consumo = 5 + consumo * 0.05;
	else {
		if(tipo == 'c' || tipo == 'C'){
			if(consumo <= 80)
				consumo = 500;
			else
				consumo = 500 + (consumo - 80) * 0.25;
		} else {
			if(tipo == 'i' || tipo == 'I'){
				if(consumo <= 100)
					consumo = 800;
				else
					consumo = 800 + (consumo - 100) * 0.04;
			}
		}
	}
	printf("CONTA = %d\nVALOR DA CONTA = %.2f\n", conta, consumo);
	return 0;
}