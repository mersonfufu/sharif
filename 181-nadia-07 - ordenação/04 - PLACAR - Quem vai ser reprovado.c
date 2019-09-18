#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	char nome[20];
	int problemas;
} stAluno;

void selectionSort(stAluno *vetor, int nelementos){
	int i, j, imenor;
	stAluno aux;
	for(i = 0; i < nelementos - 1; i++){
		imenor = i;
		for(j = i + 1; j < nelementos; j++){
			if(vetor[j].problemas > vetor[imenor].problemas)
				imenor = j;
			else if(vetor[j].problemas == vetor[imenor].problemas){
				int k = 0;
				for(k = 0; vetor[j].nome[k] != '\0' && vetor[imenor].nome[k] != '\0'; k++){
					if(vetor[j].nome[k] < vetor[imenor].nome[k]){
						imenor = j;
						break;
					}
					else if(vetor[j].nome[k] > vetor[imenor].nome[k])
						break;
				}
			}
		}
		if(imenor != i){
			aux = vetor[i];
			vetor[i] = vetor[imenor];
			vetor[imenor] = aux;
		}			
	}
}

int main(){
	int i, nalunos;
	stAluno *alunoptr = NULL;
	
	scanf("%d", &nalunos);
	if(!(alunoptr = (stAluno *) calloc(nalunos, sizeof(stAluno)))){
		printf("Erro de alocassaum");
		return 1;
	}
	
	for(i = 0; i < nalunos; i++)
		scanf(" %s %d", &alunoptr[i].nome, &alunoptr[i].problemas);
	
	selectionSort(alunoptr, nalunos);
	
	for(i = 0; i < nalunos; i++)
		printf("%s %d\n", alunoptr[i].nome, alunoptr[i].problemas);
	
	return 0;
}
