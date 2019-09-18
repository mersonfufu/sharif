#include <stdio.h>

int main(){
	int quant = 1, cont, desordem;
	float numero, anterior;
	while(quant){
		scanf("%d", &quant);
		if(quant == 0)
			return 0;
		else {
			cont = 1;
			desordem = 0;
			while(scanf("%f", &numero)){
				if(cont == 1)
					anterior = numero;
				else if(numero < anterior)
					desordem = 1;
				anterior = numero;
				cont++;
				if(cont > quant)
					break;
			}
			if(desordem == 1)
				printf("DESORDENADA\n");
			else
				printf("ORDENADA\n");
		}
	}
	return 0;
}