#include <stdio.h>

int main(){
	int i, j, d, traco = 0;
	int matriz[100][100], transposta[100][100];
	scanf("%d", &d);
	for(i = 0; i < d; i++){
		for(j = 0; j < d; j++){
			scanf("%d", &matriz[i][j]);
			if(i == j)
				traco += matriz[i][j];
			transposta[j][i] = matriz[i][j];
		}
	}
	for(i = 0; i < d; i++){
		for(j = 0; j < d; j++){
			printf("%d",
				matriz[i][j]*traco + transposta[i][j]
			);
			if(j < d - 1)
				printf(" ");
			else if(j == d - 1 && i != d - 1)
				printf("\n");
		}
	}
	return 0;
}