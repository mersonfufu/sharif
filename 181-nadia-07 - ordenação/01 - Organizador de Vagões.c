#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *vetor, int nelementos){
	int i, troca, aux, ttrocas = 0;
	do {
		troca = 0;
		for(i = 0; i < nelementos - 1; i++){
			if(vetor[i] > vetor[i + 1]){
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				troca = 69;
				ttrocas++; //saida
			}
		}
		nelementos--;
	} while(troca);
	return ttrocas;
}

int main(){
	int i, testes, nvagoes;
	int *vagaoptr = NULL;
	
	scanf("%d", &testes);
	while(testes--){
		scanf("%d", &nvagoes);
		if(!(vagaoptr = (int *) calloc(nvagoes, sizeof(int)))){
			printf("Erro de alocassaum\n");
			return 1;
		}
		
		for(i = 0; i < nvagoes; i++)
			scanf("%d", &vagaoptr[i]);
		
		printf("Numero ideal de trocas e de %d troca(s).\n", bubbleSort(vagaoptr, nvagoes));
		
		free(vagaoptr);
		vagaoptr = NULL;
	}
	return 0;
}
