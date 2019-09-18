#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *esquerda, *direita;
    int valor;
} stNo;

stNo * alocarNoh(int valor){
    stNo *aux = (stNo *) calloc(1, sizeof(stNo));
    aux->valor = valor;
    return aux;
}

int alturaNoh(stNo *raiz){
    if(!raiz)
        return 0;
    int aux1 = alturaNoh(raiz->esquerda);
    int aux2 = alturaNoh(raiz->direita);
    return aux1 > aux2 ? aux1 + 1 : aux2 + 1;
}

stNo * inserirNoh(stNo *raiz, stNo *no){
    if(!raiz)
        return no;
    if(no->valor < raiz->valor)
        raiz->esquerda = inserirNoh(raiz->esquerda, no);
    else
        raiz->direita = inserirNoh(raiz->direita, no);
    return raiz;
}

stNo * inserirNohBalanceado(stNo *arvore, int *vetor, int inicio, int fim){
    if(inicio > fim)
        return;
    if(inicio == fim){
        arvore = inserirNoh(arvore, alocarNoh(vetor[inicio]));
        return;
    }
    int meio = (inicio + fim) / 2;
    arvore = inserirNoh(arvore, alocarNoh(vetor[meio]));
    inserirNohBalanceado(arvore, vetor, inicio, meio - 1);
    inserirNohBalanceado(arvore, vetor, meio + 1, fim);
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

stNo * removerArvore(stNo *raiz){
    if(raiz){
        removerArvore(raiz->esquerda);
        removerArvore(raiz->direita);
        free(raiz);
    }
    return NULL;
}

int main(){
    stNo *degenerada = NULL, *balanceada = NULL;
    int *vetor = NULL, aux, telementos = 0;

    while(scanf("%d", &aux) != EOF){
        telementos++;
        vetor = (int *) realloc(vetor, telementos * sizeof(int));
        vetor[telementos - 1] = aux;
    }

    quickSort(vetor, 0, telementos - 1);

    for(aux = 0; aux < telementos; aux++)
        degenerada = inserirNoh(degenerada, alocarNoh(aux));
        
    balanceada = inserirNohBalanceado(balanceada, vetor, 0, telementos - 1);
 
    printf("%d\n%d\n", alturaNoh(degenerada), alturaNoh(balanceada));

    free(vetor);
    vetor = NULL;
    degenerada = removerArvore(degenerada);
    balanceada = removerArvore(balanceada);

    return 0;
}