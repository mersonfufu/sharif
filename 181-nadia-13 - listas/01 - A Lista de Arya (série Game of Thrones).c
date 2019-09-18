#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stInimigo *) calloc(1, sizeof(stInimigo))

typedef struct inimigo {
    struct inimigo *proximo;
    int id;
} stInimigo;

void inserirInimigo(stInimigo *lista){
    stInimigo *cabeca = lista;
    int pessoa, inimigo;
    scanf("%d %d", &pessoa, &inimigo);
    while(lista){
        if(lista->id == inimigo){
            stInimigo *aux = alocarNo;
            aux->id = pessoa;
            aux->proximo = lista->proximo;
            lista->proximo = aux;
            return;
        } else lista = lista->proximo;
    }
}

void removerInimigo(stInimigo **cabeca){
    stInimigo *anterior = *cabeca;
    stInimigo *lista = (*cabeca)->proximo;
    int inimigo;
    scanf("%d", &inimigo);
    if((*cabeca)->id == inimigo){
        stInimigo *aux = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(aux);
        return;
    }
    while(lista){
        if(lista->id == inimigo){
            stInimigo *aux = lista;
            lista = anterior->proximo = lista->proximo;
            free(aux);
            return;
        } else {
            lista = lista->proximo;
            anterior = anterior->proximo;
        }
    }
}

void contarInimigos(stInimigo *lista){
    int esquerda, direita, pesquerda, pdireita, contador = 0;
    scanf("%d %d", &esquerda, &direita);
    if(esquerda == direita)
        printf("-1\n");
    else {
        while(lista){
            contador++;
            if(lista->id == esquerda)
                pesquerda = contador;
            if(lista->id == direita)
                pdireita = contador;
            lista = lista->proximo;
        }
        if(pesquerda > pdireita)
            contador = pesquerda - pdireita - 1;
        else
            contador = pdireita - pesquerda - 1;
        printf("%d\n", contador);
    }
}

int main(){
    int ninimigos;
    stInimigo *cabeca = NULL, *lista = NULL;

    scanf("%d", &ninimigos);
    while(ninimigos--){
        if(!cabeca){
            cabeca = alocarNo;
            scanf("%d", &cabeca->id);
            lista = cabeca;
        } else {
            stInimigo *aux = alocarNo;
            scanf("%d", &aux->id);
            lista = lista->proximo = aux;
        }
    }

    char operacao;
    do {
        scanf(" %c", &operacao);
        switch(operacao){
            case 'I':
            case 'i': {
                inserirInimigo(cabeca);
                break;
            }
            case 'R':
            case 'r': {
                removerInimigo(&cabeca);
                break;
            }
            case 'Q':
            case 'q': {
                contarInimigos(cabeca);
                break;
            }
        }
    } while(operacao != 'F' && operacao != 'f');

    lista = cabeca;
    while(lista){
        stInimigo *aux = lista;
        lista = lista->proximo;
        free(aux);
    }

    return 0;
}