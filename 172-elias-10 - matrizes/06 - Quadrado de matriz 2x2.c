#include <stdio.h>

int main(){
	int i, j;
	float matriz[2][2], resultante[2][2];
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++)
			scanf("%f", &matriz[i][j]);
	}
	resultante[0][0] = matriz[0][0] * matriz[0][0] + matriz[0][1] * matriz[1][0];
	resultante[0][1] = matriz[0][0] * matriz[0][1] + matriz[0][1] * matriz[1][1];
	resultante[1][0] = matriz[1][0] * matriz[0][0] + matriz[1][1] * matriz[1][0];
	resultante[1][1] = matriz[1][0] * matriz[0][1] + matriz[1][1] * matriz[1][1];
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			printf("%.3f", resultante[i][j]);
			if(j < 1)
				printf(" ");
			else if(j == 1 && i != 1)
				printf("\n");
		}
	}
	return 0;
}