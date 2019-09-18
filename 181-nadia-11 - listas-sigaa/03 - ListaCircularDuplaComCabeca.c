#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stNo *) calloc(1, sizeof(stNo))

typedef struct no {
    bool cabeca;
    int valor;
    struct no *anterior;
    struct no *proximo;
} stNo;

void adicionarNo(stNo *cabeca, int valor){
    stNo *aux = alocarNo;
    aux->valor = valor;
    aux->proximo = cabeca;
    cabeca->anterior = aux;
    stNo *lista = cabeca;
    while(!lista->proximo->cabeca)
        lista = lista->proximo;
    lista->proximo = aux;
    aux->anterior = lista;
}

void adicionarNoOrdenado(stNo *cabeca, int valor){
    if(cabeca->proximo->cabeca)
        adicionarNo(cabeca, valor);
    else {
        stNo *anterior = cabeca;
        stNo *lista = cabeca->proximo;
        while(
            lista->valor < valor &&
            !lista->cabeca
        ){
            anterior = anterior->proximo;
            lista = lista->proximo;
        }
        stNo *aux = alocarNo;
        aux->valor = valor;
        anterior->proximo = aux;
        aux->proximo = lista;
        lista->anterior = aux;
        aux->anterior = anterior;
    }
}

void apagarLista(stNo *cabeca){
    stNo *lista = cabeca->proximo;
    cabeca->proximo = cabeca;
    while(!lista->cabeca){
        stNo *aux = lista;
        lista = lista->proximo;
        free(aux);
    }
}

void buscarLista(stNo cabeca, int valor){
    stNo *lista = cabeca.proximo;
    while(!lista->cabeca){
        if(lista->valor == valor){
            printf("O elemento %d esta na lista\n", valor);
            return;
        }
        lista = lista->proximo;
    }
    printf("O elemento %d naum esta na lista\n", valor);
}

void imprimir(stNo cabeca){
    stNo *lista = cabeca.proximo;
    while(!lista->cabeca){
        printf("%d", lista->valor);
        printf(lista->proximo->cabeca ? "\n" : " ");
        lista = lista->proximo;
    }
}

void imprimirReverso(stNo cabeca){
    stNo *lista = cabeca.anterior;
    while(!lista->cabeca){
        printf("%d", lista->valor);
        printf(lista->anterior->cabeca ? "\n" : " ");
        lista = lista->anterior;
    }
}

void removerNo(stNo *cabeca, int valor){
    stNo *anterior = cabeca;
    stNo *lista = cabeca->proximo;
    while(!lista->cabeca){
        if(lista->valor == valor){
            stNo *aux = lista;
            anterior->proximo = anterior->proximo->proximo;
            lista->proximo->anterior = anterior;
            free(aux);
            printf("O elemento %d saiu da lista\n", valor);
            return;
        } else {
            anterior = lista;
            lista = lista->proximo;
        }
    }
    printf("O elemento %d naum esta na lista\n", valor);
}

int main(){
    stNo cabeca = {1, 0, &cabeca, &cabeca};
    stNo *lista = NULL;
    
    adicionarNo(&cabeca, 11);
    adicionarNo(&cabeca, 22);
    adicionarNo(&cabeca, 33);
    adicionarNo(&cabeca, 44);
    adicionarNo(&cabeca, 55);

    imprimir(cabeca);

    adicionarNoOrdenado(&cabeca, 10);
    adicionarNoOrdenado(&cabeca, 32);
    adicionarNoOrdenado(&cabeca, 34);
    adicionarNoOrdenado(&cabeca, 56);

    imprimir(cabeca);

    buscarLista(cabeca, 666);
    buscarLista(cabeca, 33);

    removerNo(&cabeca, 666);
    removerNo(&cabeca, 10);
    removerNo(&cabeca, 33);
    removerNo(&cabeca, 56);

    imprimir(cabeca);
    imprimirReverso(cabeca);

    apagarLista(&cabeca);

    return 0;
}
