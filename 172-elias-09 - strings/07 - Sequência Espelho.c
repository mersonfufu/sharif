#define _TAMANHO 6
#include <stdio.h>
#include <string.h>

/**
 * Preenche vetores com NULL em toda sua extensao.
 * @param *vetor o vetor que se quer preencher.
 */
void zerar_vetor(char *vetor){
	int i;
	for(i = 0; i < _TAMANHO; i++)
		vetor[i] = 0;
}

int main(){
	char string[_TAMANHO];
	int testes, t, first, last, i, j, quant;
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		scanf("%d %d", &first, &last);
		zerar_vetor(string);
		quant = (last - first) + 1;
		for(i = 0; i < quant; i++)
			printf("%d", first + i);
		for(quant; quant > 0; quant--){
			sprintf(string, "%d", first + quant - 1); //sprintf
			j = (unsigned int)strlen(string) - 1; //strlen
			for(j; j >= 0; j--)
				printf("%c", string[j]);
		}
		printf("\n");
	}
	return 0;
}