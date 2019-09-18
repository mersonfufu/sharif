#include <stdio.h>

int main(){
	char validade = 's';
	int i, j, soma = 0;
	int sudoku[9][9];
	//entrada
	for(i = 0; i < 9; i++)
		for(j = 0; j < 9; j++){
			scanf("%d", &sudoku[i][j]);
			if(sudoku[i][j] < 1 || sudoku[i][j] > 9)
				validade = 'n';
			soma += sudoku[i][j];
		}
	//teste geral
	if(validade != 'n')
		if(soma != 405)
			validade = 'n';
	//teste das linhas
	if(validade != 'n'){
		for(i = 0; i < 9; i++){
			soma = 0;
			for(j = 0; j < 9; j++)
				soma += sudoku[i][j];
			if(soma != 45){
				validade = 'n';
				break;
			}
		}
	}
	//teste das colunas
	if(validade != 'n'){
		for(i = 0; i < 9; i++){
			soma = 0;
			for(j = 0; j < 9; j++)
				soma += sudoku[j][i];
			if(soma != 45){
				validade = 'n';
				break;
			}
		}
	}
	//teste da soma interna
	if(validade != 'n'){
		for(i = 0; i < 9; i += 3){
			for(j = 0; j < 9; j += 3){
				if(
					sudoku[i][j] + sudoku[i][j + 1] + sudoku[i][j + 2] +
					sudoku[i + 1][j] + sudoku[i + 1][j + 1] + sudoku[i + 1][j + 2] +
					sudoku[i + 2][j] + sudoku[i + 2][j + 1] + sudoku[i + 2][j + 2]
					!= 45
				){
					validade = 'n';
					break;
				}
			}
			if(validade == 'n')
				break;
		}
	}
	//saida
	validade == 's' ? printf("valido") : printf("invalido");
	return 0;
}