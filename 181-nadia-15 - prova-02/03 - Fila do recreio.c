#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stAluno *) calloc(1, sizeof(stAluno))
 
typedef struct aluno {
    struct aluno *proximo;
    int nota;
} stAluno;
 
int sortLista(stAluno *lista){
    int troca, ttrocas = 0;
    stAluno *atual = NULL;
    stAluno *proximo = NULL;
    do {
        troca = 0;
        atual = lista;
        while(atual->proximo){
            if(atual->nota < atual->proximo->nota){
                // printf("Troca %d e %d\n", atual->nota, atual->proximo->nota);
                int aux = atual->nota;
                atual->nota = atual->proximo->nota;
                atual->proximo->nota = aux;
                troca = 666;
                ttrocas += 2;
            }
            atual = atual->proximo;
        }
    }
    while(troca);
    return ttrocas;
}
 
int main(){
    int tcasos, talunos, valor;
 
    scanf("%d", &tcasos);
    while(tcasos--){
        stAluno *cabeca = NULL, *lista = NULL;
        scanf("%d", &talunos);
        int ctalunos = talunos;
        while(talunos--){
            scanf("%d", &valor);
            if(!cabeca){
                cabeca = alocarNo;
                cabeca->nota = valor;
                lista = cabeca;
            } else {
                stAluno *aux = alocarNo;
                aux->nota = valor;
                lista = lista->proximo = aux;
            }
        }
 
        valor = sortLista(cabeca);
        printf("%d\n", ctalunos - valor);
 
        lista = cabeca;
        while(lista){
            stAluno *aux = lista;
            lista = lista->proximo;
            free(lista);
        }
    }
 
    return 0;
}
