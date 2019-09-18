#define _MAXIMO 100
#include <stdio.h>

int main(){
	int tamanho, i, j;
	int matriz[_MAXIMO][_MAXIMO];
	scanf("%d", &tamanho);
	for(i = 0; i <= tamanho; i++)
		for(j = 0; j <= tamanho; j++)
			scanf("%d", &matriz[i][j]);
	for(i = 0; i <= tamanho; i++)
		for(j = 0; j <= tamanho; j++)
			if(i + 1 <= tamanho && j + 1 <= tamanho){
				if(matriz[i][j] + matriz[i][j + 1] + matriz[i + 1][j] + matriz[i + 1][j + 1] > 1)
					printf("S");
				else
					printf("U");
				if(j + 1 == tamanho)
					printf("\n");
			}
	return 0;
}