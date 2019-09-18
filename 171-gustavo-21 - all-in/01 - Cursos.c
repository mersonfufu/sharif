#include <stdio.h>

typedef struct Curso {
	int codigo;
	float vpcredito;
	char nome[100];
} stCurso;

typedef struct Aluno {
	char nome[500];
	int curso, quantcreditos;
} stAluno;

int main(){
	int tcursos, talunos, i, j;
	struct Curso cursos[30];
	struct Aluno alunos[1000];
	scanf("%d", &tcursos);
	for(i = 0; i < tcursos; i++){
		scanf("%d %f", &cursos[i].codigo, &cursos[i].vpcredito);
		scanf("%[^\n]s", cursos[i].nome);
	}
	scanf("%d", &talunos);
	for(i = 0; i < talunos; i++){
		scanf("%[^\n]s", alunos[i].nome);
		scanf("%d %d", &alunos[i].curso, &alunos[i].quantcreditos);
		printf("Aluno(a): %s ", alunos[i].nome);
		for(j = 0; j < tcursos; j++){
			if(alunos[i].curso == cursos[j].codigo){
				printf("Curso: %s ", cursos[j].nome);
				break;
			}
		}
		printf("Num. Creditos: %d ", alunos[i].quantcreditos);
		for(j = 0; j < tcursos; j++){
			if(alunos[i].curso == cursos[j].codigo){
				printf("Valor Credito: %.2f ", cursos[j].vpcredito);
				break;
			}
		}
		for(j = 0; j < tcursos; j++){
			if(alunos[i].curso == cursos[j].codigo){
				printf("Mensalidade: %.2f \n", cursos[j].vpcredito * alunos[i].quantcreditos);
				break;
			}
		}
	}
	return 0;
}