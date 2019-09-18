#include <stdio.h>

int menor(int a, int b){
	if(a < b) return a;
	return b;
}

int floodfill(int l, int c, int linhas, int colunas, char matriz[110][110]){
	int teste;
	if(l < 0 || l >= linhas || c < 0 || c >= colunas) return 1;
	if(matriz[l][c] == '.') return 1;
	if(matriz[l][c] == '#'){
		matriz[l][c] = '.';
		floodfill(l, c + 1, linhas, colunas, matriz);
		floodfill(l, c - 1, linhas, colunas, matriz);
		floodfill(l + 1, c, linhas, colunas, matriz);
		floodfill(l - 1, c, linhas, colunas, matriz);
		return 0;
	}
	matriz[l][c] = '.';
	teste = 1;
	teste = menor(teste, floodfill(l, c + 1, linhas, colunas, matriz));
	teste = menor(teste, floodfill(l, c - 1, linhas, colunas, matriz));
	teste = menor(teste, floodfill(l + 1, c, linhas, colunas, matriz));
	teste = menor(teste, floodfill(l - 1, c, linhas, colunas, matriz));
	return teste;
}

int main(){
	int linhas, colunas, l, c, disparos;
	char tabuleiro[110][110];
	scanf("%d %d", &linhas, &colunas);
	for(l = 0 ; l < linhas ; l++)
		for(c = 0 ; c < colunas ; c++)
			scanf(" %c", &tabuleiro[l][c]);
	scanf("%d", &disparos);
	while(disparos--){
		scanf("%d %d", &l, &c);
		if(tabuleiro[--l][--c] == '#')
			tabuleiro[l][c] = 'X';
	}
	disparos = 0;
	for(l = 0 ; l < linhas ; l++)
		for(c = 0 ; c < colunas ; c++)
			if(tabuleiro[l][c] == 'X')
				disparos += floodfill(l, c, linhas, colunas, tabuleiro);
	printf("%d\n", disparos);
	return 0;
}