#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stSimbolo *) calloc(1, sizeof(stSimbolo))
 
typedef struct simbolo {
    struct simbolo *proximo;
    char simbolo;
} stSimbolo;
 
int main(){
    int testes;
    char caractere;
 
    scanf("%d\n", &testes);
    while(testes--){
        stSimbolo *cabeca = NULL, *pilha = NULL;
        int diamantes = 0;
 
        do {
            if(scanf("%c", &caractere) != EOF){
                if(caractere == '<'){
                    if(!cabeca){
                        cabeca = alocarNo;
                        cabeca->simbolo = caractere;
                        pilha = cabeca;
                    } else {
                        stSimbolo *aux = alocarNo;
                        aux->simbolo = caractere;
                        pilha = pilha->proximo = aux;
                    }
                } else {
                    if(caractere == '>' && cabeca){
                        diamantes++;
                        stSimbolo *aux = cabeca;
                        while(aux != pilha)
                            aux = aux->proximo;
                        free(aux->proximo);
                        aux->proximo = NULL;
                    }
                }
            } else break;
        } while(caractere != '\n');
 
        printf("%d\n", diamantes);
 
        pilha = cabeca;
        while(pilha){
            stSimbolo *aux = pilha;
            pilha = pilha->proximo;
            free(aux);
        }
    }
 
    return 0;
}
