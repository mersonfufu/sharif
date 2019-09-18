#define alocar_vetor(quantidade,tamanho) calloc(quantidade+1,tamanho)
#define _minimo 1200
#define _masculino 'M'
#define _feminino 'F'
#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario {
	int matricula, idade, numFilhos;
	char sexo;
	double salario;
	float rendapc;
} stFuncionario;

int main(){
	int i, tfuncionarios;
	int mediaidades = 0, mediafilhos = 0;
	int um, dois, tres, quatro;
	stFuncionario *funcionarioptr = NULL;
	scanf("%d", &tfuncionarios);
	funcionarioptr = (stFuncionario *) alocar_vetor(tfuncionarios, sizeof(stFuncionario));
	//entrada
	for(i = 0; i < tfuncionarios; i++){
		scanf("%d %d %d %c %lf",
			&funcionarioptr[i].matricula,
			&funcionarioptr[i].idade,
			&funcionarioptr[i].numFilhos,
			&funcionarioptr[i].sexo,
			&funcionarioptr[i].salario
		);
		mediaidades += funcionarioptr[i].idade;
		mediafilhos += funcionarioptr[i].numFilhos;
		if(funcionarioptr[i].numFilhos == 0)
			funcionarioptr[i].rendapc = funcionarioptr[i].salario;
		else
			funcionarioptr[i].rendapc = funcionarioptr[i].salario / (funcionarioptr[i].numFilhos + 1);
	}
	mediaidades /= tfuncionarios;
	mediafilhos /= tfuncionarios;
	//saida
	um = dois = tres = quatro = 0;
	for(i = 0; i < tfuncionarios; i++){
		if(funcionarioptr[i].idade > mediaidades && funcionarioptr[i].salario > 3 * _minimo)
			um++;
		if(funcionarioptr[i].sexo == _feminino && funcionarioptr[i].numFilhos > mediafilhos)
			dois++;
		if(funcionarioptr[i].sexo == _masculino && funcionarioptr[i].numFilhos > mediafilhos)
			tres++;
		if(funcionarioptr[i].idade > 47 && funcionarioptr[i].rendapc < 2 * _minimo)
			quatro++;
	}
	printf("%d %d %d %d", um, dois, tres, quatro);
	free(funcionarioptr);
	return 0;
}