#include <stdio.h>

/**
 * Função que verifica se a matriz é de permutação
 * @param matriz Indica a matriz a ser verificada
 * @param n indica a dimensão da matriz
 * @param *soma parâmetro de saída,que armazenará a soma de todos os 'n' elementos da matriz.
 * @return 0 para nao permutacao e 1 para permutacao
 */
int ehPermutacao(int matriz[500][500], int n, int *soma){
	int i, j, slinha = 0, scoluna = 0; //linha
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(matriz[i][j] != 0 && matriz[i][j] != 1)
				return 0;
			else
				slinha += matriz[i][j];
		}
		if(slinha != 1)
			return 0;
		slinha = 0;
	}
	//coluna
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(matriz[j][i] != 0 && matriz[j][i] != 1)
				return 0;
			else
				scoluna += matriz[j][i];
		}
		if(scoluna != 1)
			return 0;
		scoluna = 0;
	}
	//default
	return 1;
};

int main(){
	int ordem, i, j, soma = 0;
	int matriz[500][500];
	scanf("%d", &ordem);
	for(i = 0; i < ordem; i++)
		for(j = 0; j < ordem; j++){
			scanf("%d", &matriz[i][j]);
			soma += matriz[i][j];
		}
	printf("%d\n", ordem);
	if(ehPermutacao(matriz, ordem, &soma))
		printf("PERMUTACAO");
	else
		printf("NAO EH PERMUTACAO");
	printf("\n");
	printf("%d\n", soma);
	return 0;
}