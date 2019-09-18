#include <stdio.h>
#include <stdlib.h>

void quickSort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim, aux;
	int pivot = vetor[(inicio + fim) / 2];
	do {
		while(vetor[i] < pivot)
			i++;
		while(vetor[f] > pivot)
			f--;
		if(i <= f){
			aux = vetor[i];
			vetor[i++] = vetor[f];
			vetor[f--] = aux;
		}
	} while(i < f);
	if(inicio < f)
		quickSort(vetor, inicio, f);
	if(i < fim)
		quickSort(vetor, i, fim);
}

int main(){
	int i, ncidades, npessoas;
	int *alturaptr = NULL;
	
	scanf("%d", &ncidades);
	while(ncidades--){
		scanf("%d", &npessoas);
		if(!(alturaptr = (int *) calloc(npessoas, sizeof(int)))){
			printf("Erro de alocassaum\n");
			return 1;
		}
		
		for(i = 0; i < npessoas; i++)
			scanf("%d", &alturaptr[i]);
		
		quickSort(alturaptr, 0, npessoas - 1);
		
		for(i = 0; i < npessoas; i++){
			printf("%d", alturaptr[i]);
			i < npessoas - 1 ? printf(" ") : printf("\n");
		}
		
		free(alturaptr);
		alturaptr = NULL;
	}
	return 0;
}
