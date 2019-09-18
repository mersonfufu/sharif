#include <stdio.h>

int main(){
	int linhas, colunas, i, j, soma = 0, nula, slinha, scoluna;
	int matriz[500][500];
	scanf("%d %d", &linhas, &colunas);
	//entrada e soma
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++){
			scanf("%d", &matriz[i][j]);
			soma += matriz[i][j];
		}
	//linhas
	for(i = 0; i < linhas; i++){
		nula = 1;
		for(j = 0; j < colunas; j++){
			if(matriz[i][j] != 0){
				nula = 0;
				continue;
			}
		}
		if(nula == 1)
			printf("LINHA %d\n", i + 1);
	}
	//colunas
	for(i = 0; i < linhas; i++){
		nula = 1;
		for(j = 0; j < colunas; j++){
			if(matriz[j][i] != 0){
				nula = 0;
				continue;
			}
		}
		if(nula == 1)
			printf("COLUNA %d\n", i + 1);
	}
	//soma
	printf("SOMA: %d\n", soma);
	return 0;
}