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

    printf("%d\n", alturaNoh(arvore) + 1);

    arvore = removerArvore(arvore);

    return 0;
}