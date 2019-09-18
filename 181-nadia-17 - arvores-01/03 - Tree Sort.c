#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *esquerda, *direita;
    int chave, valor;
} stNo;

stNo * alocarNoh(int chave, int valor){
    stNo *aux = (stNo *) calloc(1, sizeof(stNo));
    aux->chave = chave;
    aux->valor = valor;
    return aux;
}

void imprimirArvore(stNo *raiz){
    if(raiz){
        imprimirArvore(raiz->esquerda);
        printf("%d\n", raiz->valor);
        imprimirArvore(raiz->direita);
    }
}

stNo * inserirNoh(stNo *raiz, stNo *no){
    if(!raiz)
        return no;
    if(no->chave < raiz->chave)
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
    int tentradas;

    scanf("%d", &tentradas);
    while(tentradas--){
        int chave, valor;
        scanf("%d %d", &chave, &valor);
        arvore = inserirNoh(arvore, alocarNoh(chave, valor));
    }

    imprimirArvore(arvore);

    arvore = removerArvore(arvore);

    return 0;
}