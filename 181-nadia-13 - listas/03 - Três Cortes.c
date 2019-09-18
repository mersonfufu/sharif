#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define alocarNo (stPessoa *) calloc(1, sizeof(stPessoa))

typedef struct pessoa {
    struct pessoa *proximo;
    char nome[101];
} stPessoa;

void imprimirLista(stPessoa *cabeca){
    stPessoa *lista = cabeca->proximo;
    while(lista){
        printf("%s\n", lista->nome);
        lista = lista->proximo;
    }
}

void adicionarPessoa(stPessoa *lista, char *buffer){
    stPessoa *aux = alocarNo;
    strcpy(aux->nome, buffer);
    while(lista->proximo)
        lista = lista->proximo;
    lista->proximo = aux;
}

void removerPessoa(stPessoa *cabeca, char *buffer){
    stPessoa *anterior = cabeca;
    stPessoa *lista = cabeca->proximo;
    while(lista){
        if(strcmp(lista->nome, buffer) == 0){
            anterior->proximo = lista->proximo;
            free(lista);
            return;
        } else {
            anterior = anterior->proximo;
            lista = lista->proximo;
        }
    }
}

bool testarPessoa(stPessoa *cabeca, char *buffer){
    stPessoa *lista = cabeca->proximo;
    while(lista){
        if(strcmp(lista->nome, buffer) == 0)
            return 1;
        else
            lista = lista->proximo;
    }
    return 0;
}

int main(){
    stPessoa *cabeca = alocarNo, *lista = cabeca;
    char buffer[101];

    while(1){
        scanf("%s", buffer);
        if(strcmp(buffer, "Fim") != 0)
            adicionarPessoa(lista, buffer);
        else
            break;
    }

    int tjogadas;
    scanf("%d", &tjogadas);
    while(tjogadas--){
        int toques = 4;
        char aux[101] = "";
        while(toques--){
            scanf("%s", buffer);
            if(strcmp(buffer, "Errou") == 0)
                break;
            if(toques < 3 && strcmp(buffer, aux) == 0){
                removerPessoa(cabeca, buffer);
                break;
            }
            strcpy(aux, buffer);
            if(toques == 0 && strcmp(buffer, "Errou") != 0)
                if(testarPessoa(cabeca, buffer))
                    removerPessoa(cabeca, buffer);
                else
                    adicionarPessoa(cabeca, buffer);
        }
    }

    imprimirLista(cabeca);

    lista = cabeca;
    while(lista){
        stPessoa *aux = lista;
        lista = lista->proximo;
        free(aux);
    }

    return 0;
}