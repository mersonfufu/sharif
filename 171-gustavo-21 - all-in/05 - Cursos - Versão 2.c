#define alocar_vetor(quantidade,tamanho) calloc(quantidade,tamanho)
#define testar_alocacao(vetor) if(vetor==NULL){printf("Erro de alocacao. O programa sera finalizado\n");return 1;}
#include <stdio.h>
#include <stdlib.h>

typedef struct Curso {
	int codigo;
	float vpcredito;
	char *nomeptr;
} stCurso;

typedef struct Aluno {
	char *nomeptr;
	int curso, quantcreditos;
} stAluno;

int main(){
	char buffer[1000];
	int tcursos, talunos, i, j, quantidade;
	stCurso *cursosptr = NULL;
	stAluno *alunosptr = NULL;
	scanf("%d", &tcursos);
	cursosptr = (stCurso *) alocar_vetor(tcursos, sizeof(stCurso));
	testar_alocacao(cursosptr);
	for(i = 0; i < tcursos; i++){
		scanf("%d %f", &cursosptr[i].codigo, &cursosptr[i].vpcredito);
		scanf("%[^\n]s", buffer);
		quantidade = sprintf(buffer, "%s", buffer);
		cursosptr[i].nomeptr = (char *) alocar_vetor(quantidade, sizeof(char));
		testar_alocacao(cursosptr[i].nomeptr);
		for(j = 0; j < quantidade; j++)
			cursosptr[i].nomeptr[j] = buffer[j];
	}
	//entrada alunos
	scanf("%d", &talunos);
	alunosptr = (stAluno *) alocar_vetor(talunos, sizeof(stAluno));
	testar_alocacao(alunosptr);
	for(i = 0; i < talunos; i++){
		scanf("%[^\n]s", buffer);
		quantidade = sprintf(buffer, "%s", buffer);
		alunosptr[i].nomeptr = (char *) alocar_vetor(quantidade, sizeof(char));
		testar_alocacao(alunosptr[i].nomeptr);
		for(j = 0; j < quantidade; j++)
			alunosptr[i].nomeptr[j] = buffer[j];
		scanf("%d", &alunosptr[i].curso);
		scanf("%d", &alunosptr[i].quantcreditos);
		printf("Aluno(a): %s ", alunosptr[i].nomeptr);
		for(j = 0; j < tcursos; j++){
			if(alunosptr[i].curso == cursosptr[j].codigo){
				printf("Curso: %s ", cursosptr[j].nomeptr);
				break;
			}
		}
		printf("Num. Creditos: %d ", alunosptr[i].quantcreditos);
		for(j = 0; j < tcursos; j++){
			if(alunosptr[i].curso == cursosptr[j].codigo){
				printf("Valor Credito: %.2f ", cursosptr[j].vpcredito);
				break;
			}
		}
		for(j = 0; j < tcursos; j++){
			if(alunosptr[i].curso == cursosptr[j].codigo){
				printf("Mensalidade: %.2f \n", cursosptr[j].vpcredito * alunosptr[i].quantcreditos);
				break;
			}
		}
	}
	//free
	for(i = 0; i < tcursos; i++)
		free(cursosptr[i].nomeptr);
	for(i = 0; i < talunos; i++)
		free(alunosptr[i].nomeptr);
	free(cursosptr);
	cursosptr = NULL;
	free(alunosptr);
	alunosptr = NULL;
	return 0;
}