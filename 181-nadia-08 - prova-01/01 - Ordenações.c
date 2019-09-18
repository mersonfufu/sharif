#include <stdio.h>
#include <stdlib.h>
 
int insertionSort(int *vetor, int nelementos){
    int i = 0, j = 1, aux = 0, ttrocas = 0;
    while(j < nelementos){
        aux = vetor[j];
        i = j - 1;
        while((i >= 0) && (vetor[i] > aux)){
            vetor[i + 1] = vetor[i];
            i--;
            ttrocas++;
        }
        vetor[i + 1] = aux;
        j++;
    }
    return ttrocas;
}
 
int selectionSort(int *vetor, int nelementos){
    int i, j, imenor, aux, ttrocas = 0;
    for(i = 0; i < nelementos - 1; i++){
        imenor = i;
        for(j = i + 1; j < nelementos; j++)
            if(vetor[j] < vetor[imenor])
                imenor = j;
        if(imenor != i){
            aux = vetor[i];
            vetor[i] = vetor[imenor];
            vetor[imenor] = aux;
            ttrocas++;
        }            
    }
    return ttrocas;
}
 
int bubbleSort(int *vetor, int nelementos){
    int i, troca, aux, ttrocas = 0;
    do {
        troca = 0;
        for(i = 0; i < nelementos - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = 1;
                ttrocas++;
            }
        }
        nelementos--;
    } while(troca);
    return ttrocas;
}
 
int main(){
    int j, nelementos;
    int *vetorIptr = NULL, *vetorSptr = NULL, *vetorBptr = NULL;
    
    scanf("%d", &nelementos);
    if(
        !(vetorIptr = (int *) calloc(nelementos, sizeof(int))) || 
        !(vetorSptr = (int *) calloc(nelementos, sizeof(int))) || 
        !(vetorBptr = (int *) calloc(nelementos, sizeof(int)))
    ){
        printf("Erro de alocassaum\n");
        return 1;
    }    
    
    for(j = 0; j < nelementos; j++){
        scanf("%d", &vetorIptr[j]);
        vetorSptr[j] = vetorBptr[j] = vetorIptr[j];
    }
    
    typedef struct metodo {
        char nome;
        int trocas;
    } stMetodo;
    
    stMetodo metodos[3];
    metodos[0].nome = 'i';
    metodos[0].trocas = insertionSort(vetorIptr, nelementos);
    metodos[1].nome = 's';
    metodos[1].trocas = selectionSort(vetorSptr, nelementos);
    metodos[2].nome = 'b';
    metodos[2].trocas = bubbleSort(vetorBptr, nelementos);
    
    int menor = metodos[0].trocas;
    for(j = 1; j < 3; j++)
        if(metodos[j].trocas < menor)
            menor = metodos[j].trocas;
    
    for(j = 0; j < 3; j++)
        if(metodos[j].trocas == menor)
            printf("%c", metodos[j].nome);
    printf(" %d\n", menor);
    
    free(vetorIptr);
    free(vetorSptr);
    free(vetorBptr);
    vetorIptr = vetorSptr = vetorBptr = NULL;
    return 0;
}
