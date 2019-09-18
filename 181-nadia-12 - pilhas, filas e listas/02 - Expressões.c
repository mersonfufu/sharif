#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stLetra *) calloc(1, sizeof(stLetra))

typedef struct letra {
    char caractere;
    struct letra *proximo;
} stLetra;

int main(){
    int testes;
    char caractere;

    scanf("%d\n", &testes);
    while(testes--){
        stLetra *cabeca = alocarNo;
        stLetra *lista = cabeca;

        while(scanf("%c", &caractere) != EOF){
            stLetra *aux = alocarNo;
            aux->caractere = caractere;
            lista = lista->proximo = aux;
        }

        lista = cabeca->proximo;
        int parentese = 0, colchete = 0, chave = 0;
        while(lista){
            switch(lista->caractere){
                case '(': parentese++; break;
                case ')': parentese--; break;
                case '[': colchete++; break;
                case ']': colchete--; break;
                case '{': chave++; break;
                case '}': chave--; break;
            }
            if(parentese < 0 || colchete < 0 || chave < 0)
                while(lista->caractere != '\n' && lista)
                    lista = lista->proximo;
            if(lista->caractere == '\n' && lista){
                printf(parentese == 0 && colchete == 0 && chave == 0 ? "S\n" : "N\n");
                parentese = colchete = chave = 0;
            }
            lista = lista->proximo;
        }

        lista = cabeca;
        while(lista){
            stLetra *aux = lista;
            lista = lista->proximo;
            free(aux);
        }
    }

    return 0;
}