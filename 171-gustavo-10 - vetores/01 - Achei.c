#include <stdio.h>

int main(){
	int tamanho, i, j, buscas, buscado, sucesso;
	int vetor[1001];
	scanf("%d", &tamanho);
	for(i = 0; i < tamanho; i++)
		scanf("%d", &vetor[i]);
	scanf("%d", &buscas);
	for(i = 0; i < buscas; i++){
		sucesso = 0;
		scanf("%d", &buscado);
		for(j = 0; j < tamanho; j++){
			if(vetor[j] == buscado){
				sucesso = 1;
				break;
			}
		}
		if(sucesso == 1)
			printf("ACHEI\n");
		else
			printf("NAO ACHEI\n");
	}
	return 0;
}