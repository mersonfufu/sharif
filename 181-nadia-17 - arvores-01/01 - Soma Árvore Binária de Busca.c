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

stNo * inserirNoh(stNo *raiz, stNo *no){
    if(!raiz)
        return no;
    if(no->valor < raiz->valor)
        raiz->esquerda = inserirNoh(raiz->esquerda, no);
    else
        raiz->direita = inserirNoh(raiz->direita, no);
    return raiz;
}

stNo * removerArvore(stNo *raiz){
    if(raiz){
        removerArvore(raiz->esquerda);
        removerArvore(raiz->direita);
        free(raiz);
    }
    return NULL;
}

int somaFolhas(stNo *raiz){
    if(!raiz)
        return 0;
    if(!raiz->esquerda && !raiz->direita)
        return raiz->valor;
    return somaFolhas(raiz->esquerda) + somaFolhas(raiz->direita);
}

int somaInterna(stNo *raiz){
    if(!raiz)
        return 0;
    if(!raiz->esquerda && !raiz->direita)
        return 0;
    return raiz->valor + somaInterna(raiz->esquerda) + somaInterna(raiz->direita);
}

int main(){
    stNo *arvore = NULL;
    int aux;

    while(scanf("%d", &aux) != EOF)
        arvore = inserirNoh(arvore, alocarNoh(aux));

    printf("%d %d\n", somaFolhas(arvore), somaInterna(arvore));

    arvore = removerArvore(arvore);

    return 0;
}