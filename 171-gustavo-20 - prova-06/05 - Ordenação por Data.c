#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
	char nome[201];
	int matricula, dia, mes, ano;
} stAluno;

/**
 * Compara duas datas de nascimentos de dois alunos.
 * @param a os dados de um aluno.
 * @param b os dados de um aluno.
 * @return 0 se o aluno a for mais novo e 1 se o aluno a for mais velho.
 */
int compara_data_nascimento(struct Aluno a, struct Aluno b){
	if(a.ano == b.ano){
		if(a.mes == b.mes){
			if(a.dia == b.dia)
				return 1;
			else
				return 0;
		} else {
			if(a.mes > b.mes)
				return 1;
			else
				return 0;
		}
	} else {
		if(a.ano > b.ano)
			return 1;
		else
			return 0;
	}
}

int main(){
	int talunos, i, j, imenor;
	struct Aluno alunos[30], aux;
	scanf("%d", &talunos);
	//entrada
	for(i = 0; i < talunos; i++){
		scanf("%d %d %d %d",
			&alunos[i].matricula,
			&alunos[i].dia,
			&alunos[i].mes,
			&alunos[i].ano
		);
		scanf("%[^\n]s", alunos[i].nome);
	}
	//selection-sort
	for(i = 0; i < talunos; i++){
		imenor = i;
		for(j = i + 1; j < talunos; j++){
			if(compara_data_nascimento(alunos[j], alunos[i]) == 1){
				aux = alunos[i];
				alunos[i] = alunos[j];
				alunos[j] = aux;
			}
		}
	}
	//saida
	for(i = 0; i < talunos; i++){
		printf("Matric.:%d ", alunos[i].matricula);
		printf("Nome:%s ", alunos[i].nome);
		printf("Data Nasc:%d/%d/%d\n", alunos[i].dia, alunos[i].mes, alunos[i].ano);
	}
	return 0;
}