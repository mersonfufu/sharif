#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stLetra *) calloc(1, sizeof(stLetra))

typedef struct letra {
    char caractere;
    struct letra *proximo;
} stLetra;

int main(){
    char caractere;
    int balanco = 0;
    stLetra *cabeca = alocarNo;
    stLetra *lista = cabeca;

    while(scanf("%c", &caractere) != EOF){
        if(caractere == '(' || caractere == ')'){
            stLetra *aux = alocarNo;
            aux->caractere = caractere;
            lista = lista->proximo = aux;
        }
    }

    lista = cabeca->proximo;
    while(lista){
        lista->caractere == '(' ? balanco++ : balanco--;
        if(balanco < 0)
            break;
        lista = lista->proximo;
    }

    printf(balanco == 0 ? "Correta" : "Incorreta");

    lista = cabeca;
    while(lista){
        stLetra *aux = lista;
        lista = lista->proximo;
        free(aux);
    }

    return 0;
}