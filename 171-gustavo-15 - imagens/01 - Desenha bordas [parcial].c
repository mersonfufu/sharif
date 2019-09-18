#include <stdio.h>

int main(){
	int i, j, largura, altura, borda, vborda;
	int matriz[100][100] = {0};
	scanf("%d %d %d %d", &largura, &altura, &borda, &vborda);
	printf("P2\n%d %d\n255\n", largura, altura);
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			if(
				i <= borda - 1 || j <= borda - 1 ||
				i > altura - borda - 1 || j > largura - borda - 1
			)
				printf("%d", vborda);
			else
				printf("%d", matriz[i][j]);
			if(j < largura - 1)
				printf(" ");
			else if(j == largura - 1 && i < altura - 1)
				printf("\n");
		}
	}
	return 0;
}