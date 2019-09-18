#define _MAXIMO 100
#include <stdio.h>

int main(){
	int linhas, colunas, borda, valor, i, j;
	int matriz[_MAXIMO][_MAXIMO];
	scanf("%d %d %d %d", &colunas, &linhas, &borda, &valor);
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++)
			matriz[i][j] = 0;
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++)
			if(
				i <= borda - 1 ||
				j <= borda - 1 ||
				i >= colunas - borda ||
				j >= colunas - borda
			)
				matriz[i][j] = valor;
	printf("P2\n");
	printf("%d %d\n", linhas, colunas);
	printf("255\n");
	for(i = 0; i < linhas; i++)
		for(j = 0; j < colunas; j++){
			printf("%d", matriz[i][j]);
			if(i < colunas)
				printf(" ");
			if(j == colunas - 1)
				printf("\n");
		}
	return 0;
}