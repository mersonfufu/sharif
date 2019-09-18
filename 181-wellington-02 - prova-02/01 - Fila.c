#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stElemento *) calloc(1, sizeof(stElemento))

typedef struct elemento {
    struct elemento *proximo;
    int valor;
} stElemento;

void imprimirFila(stElemento *cabeca){
    while(cabeca){
        printf("%d", cabeca->valor);
        printf(cabeca->proximo ? " " : "\n");
        cabeca = cabeca->proximo;
    }
}

int main(){
    stElemento *cabeca = NULL, *fila = NULL;
    char opcao;

    do {
        scanf("%c", &opcao);
        switch(opcao){
            case 'd':
            case 'D': {
                if(!cabeca)
                    printf("Fila vazia\n");
                else {
                    stElemento *aux = cabeca->proximo;
                    free(cabeca);
                    cabeca = aux;
                    !cabeca ? printf("\n") : imprimirFila(cabeca);
                }
                break;
            }
            case 'e':
            case 'E': {
                int valor;
                scanf("%d", &valor);
                if(!cabeca){
                    if(!(cabeca = alocarNo))
                        printf("Fila cheia\n");
                    else
                        printf("%d\n", cabeca->valor = valor);
                }
                else {
                    fila = cabeca;
                    while(fila->proximo)
                        fila = fila->proximo;
                    stElemento *aux = alocarNo;
                    aux->valor = valor;
                    fila->proximo = aux;
                    imprimirFila(cabeca);
                }
                break;
            }
        }
    } while(opcao != 'T');

    fila = cabeca;
    while(fila){
        stElemento *aux = fila;
        fila = fila->proximo;
        free(aux);
    }

    return 0;
}