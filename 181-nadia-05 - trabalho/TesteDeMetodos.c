/**
 * Trabalho de AED1
 * Hemerson e Paulo Henrique Santos
 *
 * Analise dos metodos de ordenacao
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "AnalisesDosMetodos.h"

/**
 * Imprime uma matriz de elementos
 * Hemerson
 */
void mostrarMatriz(int **matriz, int nvetores, int nelementos, int tipo){
	int i, j;
	tipo == 0 ? printf("\n--- Matriz inicial ---\n") : printf("\n--- Matriz ordenada ---\n");
	for(i = 0; i < nvetores; i++){
		for(j = 0; j < nelementos; j++)
			printf("%04d ", matriz[i][j]);
		printf("\n");
	}
}

int main(){
	int tinicial = time(NULL);
	int nvetores, nelementos;
	int **matriz = NULL;
	int i, j;
	
	//entrada
	printf("Numero de vetores e elementos de cada vetor... ");
	scanf("%d %d", &nvetores, &nelementos);
	//nvetores = 20; nelementos = 20;
	printf("\n%d vetores com %d posicoes\n", nvetores, nelementos);
	
	//alocar matriz
	printf("Alocando...\n");
	if(!(matriz = malloc(nvetores * sizeof(int *)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	for(i = 0; i < nvetores; i++)
		if(!(matriz[i] = malloc(nelementos * sizeof(int)))){
			printf("Erro de alocassaum\n");
			return 1;
		}
	
	//preencher matriz
	printf("Preenchendo...\n");
	for(i = 0; i < nvetores; i++){
		srand(time(NULL) * (i * i));
		for(j = 0; j < nelementos; j++)
			matriz[i][j] = rand() % 9999 + 1;
	}
	
	//mostrarMatriz(matriz, nvetores, nelementos, 0); //mostrar matriz
	
	//metodos
	printf("Ordenando...\n");
	for(i = 0; i < nvetores; i++)
		//selectionSort(matriz[i], nelementos);
		//insertionSort(matriz[i], nelementos);
	    //bubbleSort(matriz[i], nelementos);
		//mergeSort(matriz[i], 0, nelementos - 1);
		//quickSort(matriz[i], 0, nelementos - 1);
		//countingSort(matriz[i], nelementos);
	    //bucketSort(matriz[i], nelementos);
	
	//mostrarMatriz(matriz, nvetores, nelementos, 1); //mostrar matriz
	
	//liberar matriz
	for(i = 0; i < nvetores; i++)
		free(matriz[i]);
	free(matriz);
	matriz = NULL;
	
	int tfinal = time(NULL);
	printf("\nTempo de execucao = %d segundo(s)\n", tfinal - tinicial);
	
	return 0;
}

/**
 * Selection Sort
 * Hemerson
 */
void selectionSort(int *vetor, int nelementos){
	int i, j, imenor, aux;
	for(i = 0; i < nelementos - 1; i++){
		imenor = i;
		for(j = i + 1; j < nelementos; j++)
			if(vetor[j] < vetor[imenor])
				imenor = j;
		if(imenor != i){
			aux = vetor[i];
			vetor[i] = vetor[imenor];
			vetor[imenor] = aux;
		}			
	}
}

/**
 * Insertion Sort
 * Paulo
 */
void insertionSort(int *vetor, int nelementos){
	int aux, i, j;
	for(i = 1; i < nelementos; i++){
		aux = vetor[i];
		for(j = i; (j > 0) && (aux < vetor[j-1]); j--)
			vetor[j] = vetor[j-1];
		vetor[j] = aux;
	}
}

/**
 * Bubble Sort
 * Hemerson
 */
void bubbleSort(int *vetor, int nelementos){
	int i, troca, aux;
	do {
		troca = 0;
		for(i = 0; i < nelementos - 1; i++){
			if(vetor[i] > vetor[i + 1]){
				printf("%d <-> %d\n", vetor[i], vetor[i + 1]); //saida
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				troca = 69;
			}
		}
		nelementos--;
	} while(troca);
}

/**
 * Merge Sort
 * Paulo Henrique
 * CÓPIA: https://programacaodescomplicada.wordpress.com/2014/05/19/ed1-aula-51-ordenacao-mergesort/
 */
void merge(int *vetor, int inicio, int meio, int fim){
	int *temp, tam1, tam2, tamanho, i, j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	tam1 = inicio;
	tam2 = meio+1;
	temp = (int *) malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i = 0; i < tamanho; i++){
			if(!fim1 && !fim2){
				if(vetor[tam1] < vetor[tam2])
					temp[i] = vetor[tam1++];
				else
					temp[i] = vetor[tam2++];
				if(tam1 > meio) fim1 = 1;
				if(tam2 > fim) fim2 = 1;
			}
			else{
				if(!fim1)
					temp[i] = vetor[tam1++];
				else
					temp[i] = vetor[tam2++];
			}
		}
		for(j = 0, k = inicio; j < tamanho; k++, j++)
			vetor[k] = temp[j];
	}
	free(temp);
}

void mergeSort(int *vetor, int inicio, int fim){
	if(inicio < fim){
		int meio = (inicio + fim) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

/**
 * Quick Sort
 * Hemerson
 */
void quickSort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim, aux;
	int pivot = vetor[(inicio + fim) / 2];
	do {
		while(vetor[i] < pivot)
			i++;
		while(vetor[f] > pivot)
			f--;
		if(i <= f){
			aux = vetor[i];
			vetor[i++] = vetor[f];
			vetor[f--] = aux;
		}
	} while(i < f);
	if(inicio < f)
		quickSort(vetor, inicio, f);
	if(i < fim)
		quickSort(vetor, i, fim);
}

/**
 * Radix Sort
 * Paulo Henrique
 */
void radixSort();

/**
 * Counting Sort
 * Paulo Henrique
 */
#define MAX 10000
void countingSort(int *vetor, int nelementos){
	int i, j, k;
	int indices[MAX];
	
	for(i = 0; i < MAX; i++)
		indices[i] = 0;

	//contagem de n vezes do indice
	//onde incrementa +1 no mesmo se o elemento v[i]==indice[vetor[i]]
	//ex.: v[i] == 2
	//		indice[2] == v[i]
	//		entao indice[2]++; 
	for(i = 0; i < nelementos; i++)
		indices[vetor[i]]++;
	
	for(i = 0, j = 0; j < MAX; j++){
		for(k = indices[j]; k > 0; k--)
			vetor[i++] = j; 
	}
}	

/**
 * Bucket Sort
 * Paulo Henrique
 * CÓPIA: https://programacaodescomplicada.wordpress.com/2018/03/26/ed-aula-124-ordenacao-bucketsort/
 *
 */
#define MAX 10000
struct balde {
    int qtd;
    int valores[MAX];
};
 
void bucketSort(int *vetor, int nelementos){
	int i, j, maior, menor, nBaldes, pos;
	struct balde *bd;
	
	maior = menor = vetor[0];
	for(i = 1; i < nelementos; i++){
		if(vetor[i] > maior) maior = vetor[i];
		if(vetor[i] < menor) menor = vetor[i];
	}	
	
	nBaldes = (maior-menor) / MAX+1;
	bd = (struct balde *) malloc(nBaldes * sizeof(struct balde));
	
	for(i = 0; i < nBaldes; i++)
		bd[i].qtd = 0;
	
	for(i = 0; i < nelementos; i++){
		pos = (vetor[i] - menor) / MAX;
		bd[pos].valores[bd[pos].qtd] = vetor[i];
		bd[pos].qtd++;
	}
	
	pos = 0;
	for(i = 0; i < nBaldes; i++){
		mergeSort(bd[i].valores, 0, bd[i].qtd -1);
		for(j = 0; j < bd[i].qtd; j++){
			vetor[pos] = bd[i].valores[j];
			pos++;
		}
	}
	free(bd);
}