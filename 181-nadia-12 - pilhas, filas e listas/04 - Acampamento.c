#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stPirralho *) calloc(1, sizeof(stPirralho))

typedef struct pirralho {
    struct pirralho *anterior;
    struct pirralho *proximo;
    char nome[31];
    int numero;
} stPirralho;

// void imprimirLista(stPirralho cabeca){
//     stPirralho *lista = NULL;
//     for(lista = cabeca.proximo; lista->numero; lista = lista->proximo)
//         printf("[%.03d] %s\n", lista->numero, lista->nome);
// }

void adicionarPirralho(stPirralho **lista){
    printf("adicionar... \n");
    stPirralho *aux = alocarNo;
    scanf("%s %d", aux->nome, &aux->numero);
    if(!*lista){
        *lista = aux;
    }
}

//     stPirralho *aux = alocarNo;
//     scanf("%s %d", aux->nome, &aux->numero);
//     aux->proximo = cabeca;
//     cabeca->anterior = aux;
//     stPirralho *lista = cabeca;
//     while(lista->proximo->numero != 0)
//         lista = lista->proximo;
//     lista->proximo = aux;
//     aux->anterior = lista;
// }

// void removerPirralho(stPirralho *cabeca, char *buffer, char *direcao){
    // stPirralho *lista = cabeca, *anterior = cabeca;
    // while(passos--){
    //     // movimento
    //     if(strcmp(direcao, "dir") == 0){
    //         if(lista == anterior)
    //             lista = lista->proximo;
    //         else {
    //             lista = lista->proximo;
    //             anterior = anterior->proximo;
    //         }
    //     } else {
    //         if(lista == anterior)
    //             lista = lista->anterior;
    //         else {
    //             lista = lista->anterior;
    //             anterior = anterior->anterior;
    //         }
    //     }
    //     // busca
    //     if(strcmp(lista->nome, buffer) == 0){
    //         if(strcmp(direcao, "dir") == 0){
    //             anterior->proximo = lista->proximo;
    //             lista->proximo->anterior = anterior;
    //         } else {
    //             anterior->anterior = lista->anterior;
    //             lista->anterior->proximo = anterior;
    //         }
    //         free(lista);
    //         return 1;
    //     }
    // }
    // return 0;
// }

int main(){
    stPirralho *lista = NULL;
    int tpirralhos;

    printf("valor... ");
    scanf("%d", &tpirralhos);
    while(tpirralhos--)
        adicionarPirralho(&lista);
    
    // removerPirralhos(&cabeca);
    // imprimirLista(cabeca);

    return 0;
}