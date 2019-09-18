#include <stdio.h>
#include <stdlib.h>

void quickSort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim, pivot = vetor[(inicio + fim) / 2], aux;
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
	int i, tnumeros;
	int *posicoesptr = NULL, *primosptr = NULL;
	
	scanf("%d", &tnumeros);
	if(!(posicoesptr = (int *) calloc(tnumeros, sizeof(int)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < tnumeros; i++)
		scanf("%d", &posicoesptr[i]);
	
	quickSort(posicoesptr, 0, tnumeros - 1);
	
	if(!(primosptr = (int *) calloc(posicoesptr[tnumeros - 1], sizeof(int)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	i = 0;
	int numero = 1;
	while(i < posicoesptr[tnumeros - 1]){
		numero++;
		int divisores = 0, divisor = 1;
		for(divisor; divisor <= numero / 2; divisor++){
			if(numero % divisor == 0)
				divisores++;
		}
		if(divisores == 1){
			primosptr[i] = numero;
			i++;
		}
	}
	
	for(i = 0; i < tnumeros; i++){
		posicoesptr[i] = primosptr[posicoesptr[i] - 1];
		printf("%d", posicoesptr[i]);
		i < tnumeros - 1 ? printf(" ") : printf("\n") ;
	}
	
	free(posicoesptr);
	free(primosptr);
	posicoesptr = primosptr = NULL;
	return 0;
}
