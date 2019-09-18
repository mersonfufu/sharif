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

stNo * removerNoh(stNo *raiz, int valor){
    // Lado = 0: maior da esquerda
    // Lado = 1: menor da direita
    int lado = 1;
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
        if(lado){
            // Menor da direita
            paiSub = no;
            sub = no->direita;
            while(sub->esquerda){
                paiSub = sub;
                sub = sub->esquerda;
            }
            if(paiSub != no){
                paiSub->esquerda = sub->direita;
                sub->direita = no->direita;
            }
            sub->esquerda = no->esquerda;
        } else {
            // Maior da esquerda
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

int main(){
    stNo *arvore = NULL;
    int tentradas;

    scanf("%d", &tentradas);
    while(tentradas--){
        int operacao, valor;
        scanf("%d %d", &operacao, &valor);
        switch(operacao){
            case 1: {
                arvore = inserirNoh(arvore, alocarNoh(valor));
                break;
            }
            case 2: {
                arvore = removerNoh(arvore, valor);
            }
        }
    }

    printf("%d\n", alturaNoh(arvore));

    arvore = removerArvore(arvore);

    return 0;
}