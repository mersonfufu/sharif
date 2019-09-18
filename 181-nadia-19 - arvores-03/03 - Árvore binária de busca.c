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

void imprimirArvore(stNo *raiz){
    if(raiz){
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirArvore(raiz->direita);
    }
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
    int aux;

    while(scanf("%d", &aux) != EOF){
        if(aux == 0)
            break;
        arvore = inserirNoh(arvore, alocarNoh(aux));
    }

    imprimirArvore(arvore);

    arvore = removerArvore(arvore);

    return 0;
}