#include <stdio.h>

int main(){
	short i, j, soma, masoma;
	short matriz[6][6];
	for(i = 0; i < 6; i++)
		for(j = 0; j < 6; j++)
			scanf("%d", &matriz[i][j]);
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			soma =
				matriz[i][j] +
				matriz[i][j + 1] +
				matriz[i][j + 2] +
				matriz[i + 1][j + 1] +
				matriz[i + 2][j] +
				matriz[i + 2][j + 1] +
				matriz[i + 2][j + 2];
			if(i == 0 && j == 0){
				masoma = soma;
				continue;
			} else if(soma > masoma)
				masoma = soma;
		}
	}
	printf("%d", masoma);
	return 0;
}