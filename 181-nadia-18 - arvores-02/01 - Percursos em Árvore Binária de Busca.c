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
        printf("%d ", raiz->valor);
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
    }
}

void imprimirNivelada(stNo *raiz, int telementos){
    stNo **vetor = (stNo **) calloc(telementos, sizeof(stNo *));
    vetor[0] = raiz;

    int contador = 1, passo = 0;
    while(contador < telementos){
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
                contador++;
                passo++;
            } else {
                vetor[nulo] = vetor[passo]->esquerda;
                vetor[nulo + 1] = vetor[passo]->direita;
                contador += 2;
                passo++;
            }
        }
    }
    for(contador = 0; contador < telementos; contador++)
        printf("%d ", vetor[contador]->valor);
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
    int aux, telementos = 0;

    while(scanf("%d", &aux) != EOF){
        arvore = inserirNoh(arvore, alocarNoh(aux));
        telementos++;
    }

    imprimirArvore(arvore);
    printf("\n");
    imprimirNivelada(arvore, telementos);

    arvore = removerArvore(arvore);

    return 0;
}