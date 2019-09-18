#include <stdio.h>
#include <stdlib.h>
#define alocarNo (stPaciente *) calloc(1, sizeof(stPaciente))

typedef struct paciente {
    struct paciente *proximo;
    int chegada;
    int atendimento;
    int condicaoCritica;
} stPaciente;

int main(){
    int pacientes, morreuMasPassaBem = 0;
    int primeiro = 420;
    stPaciente *cabeca = alocarNo;
    stPaciente *lista = cabeca;

    scanf("%d", &pacientes);
    while(pacientes--){
        stPaciente *aux = alocarNo;
        int hora, minuto;
        scanf("%d %d %d", &hora, &minuto, &aux->condicaoCritica);
        aux->chegada = hora * 60 + minuto;
        lista = lista->proximo = aux;
    }

    lista = cabeca->proximo;
    while(lista){
        if(lista == cabeca->proximo)
            lista->atendimento = lista->chegada;
        else {
            primeiro += 30;
            while(primeiro < lista->chegada)
                primeiro += 30;
            if((lista->atendimento = primeiro) > lista->chegada + lista->condicaoCritica)
                morreuMasPassaBem++;
        }
        lista = lista->proximo;
    }
    printf("%d", morreuMasPassaBem);

    lista = cabeca;
    while(lista){
        stPaciente *aux = lista;
        lista = lista->proximo;
        free(aux);
    }

    return 0;
}