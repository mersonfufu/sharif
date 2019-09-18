#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *esquerda, *direita;
    int valor, nivel;
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

void quantidadeNohsNivel(stNo *raiz, int telementos){
    stNo **vetor = (stNo **) calloc(telementos, sizeof(stNo *));
    vetor[0] = raiz;
    int i = 1, passo = 0;
    while(i < telementos){
        if(!vetor[passo]->esquerda && !vetor[passo]->direita)
            passo++;
        else {
            int nulo;
            for(nulo = 0; nulo < telementos; nulo++)
                if(!vetor[nulo])
                    break;
            if(!vetor[passo]->esquerda || !vetor[passo]->direita){
                if(!vetor[passo]->direita)
                    vetor[nulo] = vetor[passo]->esquerda;
                else
                    vetor[nulo] = vetor[passo]->direita;
                i++;
                passo++;
            } else {
                vetor[nulo] = vetor[passo]->esquerda;
                vetor[nulo + 1] = vetor[passo]->direita;
                i += 2;
                passo++;
            }
        }
    }
    int mnivel = 0;
    for(i = 0; i < telementos; i++){
        vetor[i]->nivel = profundidadeNoh(raiz, vetor[i]->valor, 1) - 1;
        if(vetor[i]->nivel > mnivel)
            mnivel = vetor[i]->nivel;
    }
    int *vquantidades = calloc(mnivel + 1, sizeof(int));
    for(i = 0; i < telementos; i++)
        vquantidades[vetor[i]->nivel]++;
    for(i = 0; i < mnivel + 1; i++)
        printf("%d ", vquantidades[i]);
    free(vetor);
    vetor = NULL;
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
    int aux, telementos = 0;

    while(scanf("%d", &aux) != EOF){
        arvore = inserirNoh(arvore, alocarNoh(aux));
        telementos++;
    }
    
    quantidadeNohsNivel(arvore, telementos);

    arvore = removerArvore(arvore);

    return 0;
}