#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int *vetor, int elementos, int vbuscado){
	int inicio = 0, fim = elementos - 1, meio;
	while(inicio <= fim){
		meio = (inicio + fim) / 2;
		if(vetor[meio] == vbuscado){
			while(vetor[meio + 1] == vbuscado)
				meio++;
			return meio;
		}
		if(vetor[meio] < vbuscado)
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	while(vetor[fim + 1] == vetor[fim])
		fim++;
	return fim;
}

void quick_sort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim - 1, pivot = vetor[(i + f) / 2], aux;
	do {
		while(vetor[i] < pivot)
			i++;
		while(vetor[f] > pivot)
			f--;
		if(i <= f){
			aux = vetor[i];
			vetor[i] = vetor[f];
			vetor[f] = aux;
			i++;
			f--;
		}
	} while(i < f);
	if(inicio < f)
		quick_sort(vetor, inicio, f);
	if(i < fim)
		quick_sort(vetor, i, fim);
}

int main(){
	int i, lanchonetes, dias;
	int *lanchoneteptr = NULL, *diaptr = NULL;
	
	scanf("%d", &lanchonetes);
	lanchoneteptr = calloc(lanchonetes, sizeof(int));
	for(i = 0; i < lanchonetes; i++)
		scanf("%d", &lanchoneteptr[i]);
	
	scanf("%d", &dias);
	diaptr = calloc(dias, sizeof(int));
	for(i = 0; i < dias; i++)
		scanf("%d", &diaptr[i]);
	
	quick_sort(lanchoneteptr, 0, lanchonetes);
	
	for(i = 0; i < dias; i++)
		printf("%d\n", busca_binaria(lanchoneteptr, lanchonetes, diaptr[i]) + 1);
	
	free(lanchoneteptr);
	lanchoneteptr = NULL;
	free(diaptr);
	diaptr = NULL;
	
	return 0;
}