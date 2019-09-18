#include <stdio.h>
#include <stdlib.h>

int insertionSort(int *vetor, int nelementos){
	int i = 0, j = 1, aux = 0;
	int ttrocas = 0; //saida
	while(j < nelementos){
		aux = vetor[j];
		i = j - 1;
		while((i >= 0) && (vetor[i] > aux)){
			vetor[i + 1] = vetor[i];
			i--;
			ttrocas++; //saida
		}
		vetor[i + 1] = aux;
		j++;
		ttrocas++; //saida
	}
	return ttrocas;
}

int selectionSort(int *vetor, int nelementos){
	int i, j, imenor, aux;
	int ttrocas = 0; //saida
	for(i = 0; i < nelementos - 1; i++){
		imenor = i;
		for(j = i + 1; j < nelementos; j++)
			if(vetor[j] < vetor[imenor])
				imenor = j;
		if(imenor != i){
			aux = vetor[i];
			vetor[i] = vetor[imenor];
			vetor[imenor] = aux;
			ttrocas++; //saida
		}			
	}
	return ttrocas;
}

int main(){
	int i, nelementos;
	int *vetorIptr = NULL, *vetorSptr = NULL;
	
	scanf("%d", &nelementos);
	if(
		!(vetorIptr = (int *) calloc(nelementos, sizeof(int))) ||
		!(vetorSptr = (int *) calloc(nelementos, sizeof(int)))
	){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < nelementos; i++){
		scanf("%d", &vetorIptr[i]);
		vetorSptr[i] = vetorIptr[i];
		//string.h = memcpy(vetor2ptr, vetorptr, nelementos * sizeof(int));
	}
	
	int diferenca = insertionSort(vetorIptr, nelementos) - selectionSort(vetorSptr, nelementos);
	printf("%d\n", diferenca > 0 ? diferenca : -diferenca);
	
	free(vetorIptr);
	free(vetorSptr);
	vetorIptr = vetorSptr = NULL;
	return 0;
}
