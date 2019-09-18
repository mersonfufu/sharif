#include <stdio.h>

int main(){
	int testes, teste, i, j, soma, imenor;
	int anoes[9];
	scanf("%d", &testes);
	for(teste = 1; teste <= testes; teste++){
		soma = 0;
		for(i = 0; i < 9; i++){
			scanf("%d", &anoes[i]);
			soma += anoes[i];
		}
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(i == j)
					continue;
				if(soma - anoes[i] - anoes[j] == 100){
					anoes[i] = 0;
					anoes[j] = 0;
					soma = 100;
					break;
				}
			}
			if(soma == 100)
				break;
		}
		for(i = 0; i < 9; i++){
			imenor = i;
			for(j = i + 1; j < 9; j++)
				if(anoes[j] < anoes[imenor])
					imenor = j;
			if(i != imenor){
				soma = anoes[i];
				anoes[i] = anoes[imenor];
				anoes[imenor] = soma;
			}
		}
		for(i = 2; i < 9; i++)
			printf("%d\n", anoes[i]);
	}
	return 0;
}