#include <stdio.h>
#include <stdlib.h>

int contar_maior_sequencia(int *vetor, int elementos){
	int posicao = 0, contador, maior = 1;
	while(posicao < elementos){
		contador = 1;
		while(vetor[posicao + 1] == vetor[posicao]){
			contador++;
			posicao++;
		}
		contador > maior ? maior = contador : 0;
		posicao++;
	}
	return maior;
}

void quickSort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim;
	int pivot = vetor[(inicio + fim) / 2];
	int aux;
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
	int i, testes, npessoas, hh, mm;
	int *pessoaptr = NULL;
	
	scanf("%d", &testes);
	while(testes--){
		scanf("%d", &npessoas);
		if(!(pessoaptr = (int *) calloc(npessoas, sizeof(int)))){
			printf("Erro de alocassaum\n");
			return 1;
		}
		
		for(i = 0; i < npessoas; i++){
			scanf("%d %d", &hh, &mm);
			pessoaptr[i] = 100 * hh + mm;
		}
		
		quickSort(pessoaptr, 0, npessoas - 1);
		
		printf("%d\n", contar_maior_sequencia(pessoaptr, npessoas));
		
		free(pessoaptr);
		pessoaptr = NULL;
	}
	return 0;
}
