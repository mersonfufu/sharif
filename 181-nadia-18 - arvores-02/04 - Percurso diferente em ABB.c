#include <stdio.h>
#include <stdlib.h>

void ordemA(stNo *);
void ordemB(stNo *);

typedef struct no {
    struct no *esquerda, *direita;
    int valor;
} stNo;

stNo * alocarNoh(int valor){
    stNo *aux = (stNo *) calloc(1, sizeof(stNo));
    aux->valor = valor;
    return aux;
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

void ordemA(stNo *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        ordemA(raiz->esquerda);
        ordemB(raiz->direita);
    }
}

void ordemB(stNo *raiz){
    if(raiz){
        ordemB(raiz->esquerda);
        printf("%d ", raiz->valor);
        ordemA(raiz->direita);
    }
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
    stNo *arvore = NULL;
    int aux;

    while(scanf("%d", &aux) != EOF)
        arvore = inserirNoh(arvore, alocarNoh(aux));
    
    ordemA(arvore);

    arvore = removerArvore(arvore);

    return 0;
}