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
	int i, nelementos;
	int *vetorptr = NULL;
	
	scanf("%d", &nelementos);
	if(!(vetorptr = (int *) calloc(nelementos, sizeof(int)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < nelementos; i++)
		scanf("%d", &vetorptr[i]);
	
	quickSort(vetorptr, 0, nelementos - 1);
	
	for(i = 0; i < nelementos; i++)
		if(!(vetorptr[i] % 2))
			printf("%d\n", vetorptr[i]);
	
	for(i = nelementos - 1; i >= 0; i--)
		if(vetorptr[i] % 2)
			printf("%d\n", vetorptr[i]);
	
	free(vetorptr);
	vetorptr = NULL;
	return 0;
}
