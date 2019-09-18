#include <stdio.h>

int main(){
	int quant, cont, numero, anterior, pontos = 1, mpontos = 1;
	scanf("%d", &quant);
	for(cont = 1; scanf("%d", &numero); cont++){
		if(cont == 1)
			anterior = numero;
		else {
			if(anterior == numero){
				pontos++;
				if(pontos > mpontos)
					mpontos = pontos;
				anterior = numero;
			} else {
				pontos = 1;
				anterior = numero;
			}
		}
		if(cont == quant)
			break;
	}
	printf("O comprimento do segmento de numeros iguais e: %d\n", mpontos);
	return 0;
}