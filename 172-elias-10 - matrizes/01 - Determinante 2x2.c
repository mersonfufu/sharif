#include <stdio.h>

int main(){
	short i, j;
	float det;
	short matriz[2][2];
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++)
			scanf("%d", &matriz[i][j]);
	}
	det = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	printf("%.2f", det);
	return 0;
}