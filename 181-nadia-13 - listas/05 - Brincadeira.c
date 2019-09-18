#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alocarNo (stPessoa *) calloc(1, sizeof(stPessoa))

typedef struct pessoa {
    bool cabeca;
    struct pessoa *anterior;
    struct pessoa *proximo;
    char nome[101];
} stPessoa;

void imprimirLista(stPessoa cabeca){
    stPessoa *lista = NULL;
    for(lista = cabeca.proximo; !lista->cabeca; lista = lista->proximo)
        printf("%s\n", lista->nome);
}

void adicionarPessoa(stPessoa *cabeca, char *buffer){
    stPessoa *aux = alocarNo;
    strcpy(aux->nome, buffer);
    aux->proximo = cabeca;
    cabeca->anterior = aux;
    stPessoa *lista = cabeca;
    while(!lista->proximo->cabeca)
        lista = lista->proximo;
    lista->proximo = aux;
    aux->anterior = lista;
}

bool palpitePessoa(stPessoa *cabeca, char *buffer, char *direcao){
    stPessoa *lista = cabeca, *anterior = cabeca;
    int passos = 2;
    while(passos--){
        // movimento
        if(strcmp(direcao, "dir") == 0){
            if(lista == anterior)
                lista = lista->proximo;
            else {
                lista = lista->proximo;
                anterior = anterior->proximo;
            }
        } else {
            if(lista == anterior)
                lista = lista->anterior;
            else {
                lista = lista->anterior;
                anterior = anterior->anterior;
            }
        }
        // busca
        if(strcmp(lista->nome, buffer) == 0){
            if(strcmp(direcao, "dir") == 0){
                anterior->proximo = lista->proximo;
                lista->proximo->anterior = anterior;
            } else {
                anterior->anterior = lista->anterior;
                lista->anterior->proximo = anterior;
            }
            free(lista);
            return 1;
        }
    }
    return 0;
}

int main(){
    stPessoa cabeca = {1, &cabeca, &cabeca, "Arlete"};
    stPessoa *lista = &cabeca;
    char buffer[101];
    int pirralhos = 0;

    while(1){
        scanf("%s", buffer);
        if(strcmp(buffer, "Fim") != 0)
            adicionarPessoa(&cabeca, buffer);
        else break;
        pirralhos++;
    }

    int pontos = 0;
    while(pirralhos--){
        char direcao[3];
        scanf("%s %s", buffer, direcao);
        pontos += palpitePessoa(&cabeca, buffer, direcao);
    }
    printf("%d\n", pontos);

    lista = cabeca.proximo;
    while(lista){
        stPessoa *aux = lista;
        lista = lista->proximo;
        free(aux);
    }
    cabeca.proximo = cabeca.anterior = NULL;

    return 0;
}