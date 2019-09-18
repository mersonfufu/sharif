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

stNo * removerNoh(stNo *raiz, int valor){
    stNo *no = raiz, *paiNo = NULL;
    stNo *sub = NULL, *paiSub = NULL;
    while(no){
        if(no->valor == valor)
            break;
        paiNo = no;
        if(no->valor > valor)
            no = no->esquerda;
        else
            no = no->direita;
    }
    if(!no)
        return raiz;
    if(!no->esquerda || !no->direita)
        if(!no->esquerda)
            sub = no->direita;
        else
            sub = no->esquerda;
    else {
        paiSub = no;
        sub = no->esquerda;
        while(sub->direita){
            paiSub = sub;
            sub = sub->direita;
        }
        if(paiSub != no){
            paiSub->direita = sub->esquerda;
            sub->esquerda = no->esquerda;
        }
        sub->direita = no->direita;
    }
    if(!paiNo){
        free(no);
        return sub;
    }
    if(paiNo->valor > valor)
        paiNo->esquerda = sub;
    else
        paiNo->direita = sub;
    free(no);
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
    char operacao;

    while(1){
        scanf(" %c", &operacao);
        if(operacao == 'S' || operacao == 's')
            break;
        switch(operacao){
            case 'I':
            case 'i': {
                int aux;
                scanf("%d", &aux);
                arvore = inserirNoh(arvore, alocarNoh(aux));
                break;
            }
            case 'R':
            case 'r': {
                int aux;
                scanf("%d", &aux);
                arvore = removerNoh(arvore, aux);
                break;
            }
            case 'M':
            case 'm': {
                imprimirArvore(arvore);
                printf("\n");
                break;
            }
        }
    }

    arvore = removerArvore(arvore);

    return 0;
}