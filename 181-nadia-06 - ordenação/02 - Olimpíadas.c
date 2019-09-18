#include <stdio.h>
#include <stdlib.h>

typedef struct pais {
	int nome, ouro, prata, bronze;
} stPais;

void merge(stPais *vetor, int inicio, int meio, int fim){
	int tam1 = meio - inicio + 1;
	int tam2 = fim - meio;
	stPais metade1[tam1], metade2[tam2];
	int i, j, k;
	for(i = 0; i < tam1; i++)
		metade1[i] = vetor[inicio + i];
	for(j = 0; j < tam2; j++)
		metade2[j] = vetor[meio + 1 + j];
	i = j = 0;
	k = inicio;
	while(i < tam1 && j < tam2){
		if(metade1[i].ouro < metade2[j].ouro)
			vetor[k++] = metade1[i++];
		else if(metade1[i].ouro > metade2[j].ouro)
			vetor[k++] = metade2[j++];
		else if(metade1[i].prata < metade2[j].prata)
			vetor[k++] = metade1[i++];
		else if(metade1[i].prata > metade2[j].prata)
			vetor[k++] = metade2[j++];
		else if(metade1[i].bronze < metade2[j].bronze)
			vetor[k++] = metade1[i++];
		else if(metade1[i].bronze > metade2[j].bronze)
			vetor[k++] = metade2[j++];
		else if(metade1[i].nome < metade2[j].nome)
			vetor[k++] = metade2[j++];
		else
			vetor[k++] = metade1[i++];
	}
	while(i < tam1)
		vetor[k++] = metade1[i++];
	while(j < tam2)
		vetor[k++] = metade2[j++];
}

void mergeSort(stPais *vetor, int inicio, int fim){
	if(inicio < fim){
		int meio = (inicio + fim) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

int main(){
	int i, paises, modalidades, medalha;
	stPais *paisesptr = NULL;
	
	scanf("%d %d", &paises, &modalidades);
	if(!(paisesptr = (stPais *) calloc(paises, sizeof(stPais)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < paises; i++)
		paisesptr[i].nome = i + 1;
	
	while(modalidades--){
		scanf("%d", &medalha);
		paisesptr[medalha - 1].ouro++;
		scanf("%d", &medalha);
		paisesptr[medalha - 1].prata++;
		scanf("%d", &medalha);
		paisesptr[medalha - 1].bronze++;
	}
	
	mergeSort(paisesptr, 0, paises - 1);
	for(i = paises - 1; i >= 0; i--){
		printf("%d", paisesptr[i].nome);
		i > 0 ? printf(" ") : printf("\n");
	}
	
	free(paisesptr);
	paisesptr = NULL;
	return 0;
}
