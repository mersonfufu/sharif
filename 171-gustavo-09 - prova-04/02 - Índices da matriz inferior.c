#include <stdio.h>

int main(){
	int linhas, colunas, l, c;
	scanf("%d %d", &linhas, &colunas);
	int matriz[linhas * colunas];
	for(l = 1; l <= linhas; l++){
		for(c = 1; c <= colunas; c++){
			if(l > c){
				printf("(%d,%d)", l, c);
				if(l - c > 1 && c < colunas)
					printf("-");
				else if(c == colunas || l - c >= 1)
					printf("\n");
			}
		}
	}
	return 0;
}