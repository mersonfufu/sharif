#include <stdio.h>

int main(){
	int i, j, n, m, maior, menor;
	float fmaior = 0, fmenor = 0;
	int matriz[100][100];
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &matriz[i][j]);
			if(i == 0 && j == 0){
				menor = matriz[i][j];
				maior = matriz[i][j];
			} else {
				if(matriz[i][j] < menor)
					menor = matriz[i][j];
				else if(matriz[i][j] > maior)
					maior = matriz[i][j];
			}
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(matriz[i][j] == menor)
				fmenor++;
			else if(matriz[i][j] == maior)
				fmaior++;
		}
	}
	printf("%d %.2f%%\n%d %.2f%%",
		menor,
		fmenor * 100 / (n * m),
		maior,
		fmaior * 100 / (n * m)
	);
	return 0;
}