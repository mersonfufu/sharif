#include <stdio.h>

int main(){
	int elementos, i, prima = 0, sega = 0;
	float media = 0;
	int vetor[1000];
	scanf("%d", &elementos);
	if(elementos < 4){
		printf("QUANTIDADE DE ELEMENTOS INVALIDOS!\n");
		return 0;
	} else {
		for(i = 0; i < elementos; i++){
			scanf("%d", &vetor[i]);
			media += vetor[i];
		}
		media /= elementos;
		//primeira
		for(i = 0; i < elementos / 2; i++)
			vetor[i] > media ? prima++ : 0;
		//segunda
		if(elementos % 2 == 0)
			for(i = elementos / 2; i < elementos; i++)
				vetor[i] > media ? sega++ : 0;
		else
			for(i = (elementos / 2) + 1; i < elementos; i++)
				vetor[i] > media ? sega++ : 0;
		printf("%.1f %d %d ", media, prima, sega);
		if(prima == sega)
			printf("EMPATE");
		else if(prima > sega)
			printf("PRIMEIRA METADE");
		else
			printf("SEGUNDA METADE");
		printf("\n");
	}
	return 0;
}