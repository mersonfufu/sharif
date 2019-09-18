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

void buscarNoh(stNo *raiz, int valor){
    if(!raiz)
        return;
    if(raiz->esquerda && raiz->direita){
        printf("I\n");
        return;
    }
    if(raiz->valor == valor){
        printf("V\n");
        return;
    }
    if(raiz->valor > valor)
        return buscarNoh(raiz->esquerda, valor);
    return buscarNoh(raiz->direita, valor);
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

int main(){
    stNo *arvore = NULL;
    int buscar, aux;

    scanf("%d", &buscar);
    while(scanf("%d", &aux) != EOF)
        arvore = inserirNoh(arvore, alocarNoh(aux));

    buscarNoh(arvore, buscar);

    arvore = removerArvore(arvore);

    return 0;
}