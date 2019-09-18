#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stPessoa *) calloc(1, sizeof(stPessoa))

typedef struct pessoa {
	int id;
	struct pessoa *proximo;
} stPessoa;

void removerPessoa(stPessoa **cabeca, int pessoa){
	stPessoa *anterior = *cabeca;
	stPessoa *lista = (*cabeca)->proximo;
	while(lista != *cabeca){
		if(lista->id == pessoa){
			stPessoa *aux = lista;
			anterior->proximo = anterior->proximo->proximo;
			free(aux);
			return;
		} else {
			anterior = lista;
			lista = lista->proximo;
		}
	}
}

int main(){
	int npessoas, pessoa;
	stPessoa *cabeca = alocarNo;
	stPessoa *lista = cabeca;

	scanf("%d", &npessoas);
	while(npessoas--){
		stPessoa *aux = alocarNo;
		scanf("%d", &aux->id);
		lista = lista->proximo = aux;
	}

	scanf("%d", &npessoas);
	while(npessoas--){
		scanf("%d", &pessoa);
		removerPessoa(&cabeca, pessoa);
	}

	lista = cabeca->proximo;
	while(lista){
		printf("%d", lista->id);
		printf(lista->proximo ? " " : "\n");
		lista = lista->proximo;
	}

	lista = cabeca;
	while(lista){
		stPessoa *aux = lista;
		lista = lista->proximo;
		free(aux);
	}

	return 0;
}