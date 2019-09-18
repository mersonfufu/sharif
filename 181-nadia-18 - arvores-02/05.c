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
    int *vetorOrdem = NULL, *vetorNivel = NULL;
    int aux, telementos = 0;

    while(scanf("%d", &aux) != EOF){
        telementos++;
        vetorOrdem = realloc(vetorOrdem, telementos * sizeof(int));
        vetorOrdem[telementos - 1] = aux;
    }

    vetorNivel = calloc(telementos / 2, sizeof(int));
    for(aux = telementos / 2; aux < telementos; aux++)
        vetorNivel[aux - telementos / 2] = vetorOrdem[aux];

    vetorOrdem = realloc(vetorOrdem, (telementos / 2) * sizeof(int));

    for(aux = 0; aux < telementos; aux++)
        printf("%d ", vetorOrdem[aux]);
    printf("\n");

    for(aux = 0; aux < telementos/2; aux++)
        printf("%d ", vetorNivel[aux]);
    printf("\n");

    free(vetorOrdem);
    free(vetorNivel);
    vetorOrdem = vetorNivel = NULL;

    return 0;
}