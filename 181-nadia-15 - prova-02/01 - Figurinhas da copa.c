#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stFigura *) calloc(1, sizeof(stFigura))
 
typedef struct figura {
    struct figura *proximo;
    int valor;
} stFigura;
 
int main(){
    int tcarimbadas, tcompradas, valor;
    scanf("%*d %d %d", &tcarimbadas, &tcompradas);
 
    stFigura *cabeca = NULL, *lista = NULL;
    while(tcarimbadas--){
        scanf("%d", &valor);
        if(!cabeca){
            cabeca = alocarNo;
            cabeca->valor = valor;
            lista = cabeca;
        } else {
            stFigura *aux = alocarNo;
            aux->valor = valor;
            lista = lista->proximo = aux;
        }
    }
 
    while(tcompradas--){
        scanf("%d", &valor);
        lista = cabeca;
        while(lista){
            if(lista->valor == valor){
                lista->valor = -666;
                break;
            } else lista = lista->proximo;
        }
    }
 
    lista = cabeca;
    valor = 0;
    while(lista){
        if(lista->valor != -666)
            valor++;
        lista = lista->proximo;
    }
 
    lista = cabeca;
    while(lista){
        stFigura *aux = lista;
        lista = lista->proximo;
        free(lista);
    }
    
    printf("%d\n", valor);
 
    return 0;
}
