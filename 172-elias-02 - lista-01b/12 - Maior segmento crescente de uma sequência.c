#include <stdio.h>

int main(){
	int quant, cont, numero, anterior, pontos = 1, mpontos = 1;
	scanf("%d", &quant);
	if(quant == 0)
		printf("O comprimento do segmento crescente maximo e: 0\n");
	else {
		for(cont = 1; scanf("%d", &numero); cont++){
			if(cont == 1)
				anterior = numero;
			else {
				if(anterior < numero){
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
		printf("O comprimento do segmento crescente maximo e: %d\n", mpontos);
	}
	return 0;
}