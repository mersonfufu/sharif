#include <stdio.h>

int main(){
	int i, j, l, c, lmenor, cmenor, lmaior, cmaior, aux;
	int matriz[100][100];
	scanf("%d %d", &l, &c);
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			scanf("%d", &matriz[i][j]);
			if(i == 0 && j == 0){
				lmaior = lmenor = i;
				cmaior = cmenor = j;
			} else {
				if(matriz[i][j] < matriz[lmenor][cmenor]){
					lmenor = i;
					cmenor = j;
				} else if(matriz[i][j] > matriz[lmaior][cmaior]){
					lmaior = i;
					cmaior = j;
				}
			}
		}
	}
	aux = matriz[lmenor][cmenor];
	matriz[lmenor][cmenor] = matriz[lmaior][cmaior];
	matriz[lmaior][cmaior] = aux;
	for(i = 0; i < l; i++)
		for(j = 0; j < c; j++){
			printf("%d", matriz[i][j]);
			if(j < c - 1)
				printf(" ");
			else if(j == c - 1)
				printf("\n");
		}
	return 0;
}