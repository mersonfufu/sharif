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

stNo * buscarNoh(stNo *raiz, int valor){
    if(!raiz)
        return NULL;
    if(raiz->valor == valor)
        return raiz;
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

int profundidadeNoh(stNo *raiz, int valor, int profundidade){
    if(!raiz)
        return 0;
    if(raiz->valor == valor)
        return profundidade;
    profundidade++;
    if(raiz->valor > valor)
        return profundidadeNoh(raiz->esquerda, valor, profundidade);
    return profundidadeNoh(raiz->direita, valor, profundidade);
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
    int tinserir, tremover, tbuscar, aux;

    scanf("%d %d %d", &tinserir, &tremover, &tbuscar);

    while(tinserir--){
        scanf("%d", &aux);
        arvore = inserirNoh(arvore, alocarNoh(aux));
    }

    while(tremover--){
        scanf("%d", &aux);
        arvore = removerNoh(arvore, aux);
    }

    while(tbuscar--){
        scanf("%d", &aux);
        stNo *auxPtr = NULL;
        if(!(auxPtr = buscarNoh(arvore, aux)))
            printf("IMP");
        else
            printf("%d", profundidadeNoh(arvore, aux, 1));
        printf(tbuscar ? " " : "\n");
        free(auxPtr);
        auxPtr = NULL;
    }

    arvore = removerArvore(arvore);

    return 0;
}