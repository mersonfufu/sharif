#define _ORDEM 500
#include <stdio.h>

int main(){
	int i, j, l, c, cont = 1, cor = 1;
	int matriz[_ORDEM][_ORDEM];
	scanf("%d %d", &l, &c);
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			if(cor == 1)
				matriz[i][j] = 0;
			else
				matriz[i][j] = cont++;
			cor *= -1;
			if(j == c - 1 && j % 2 == 1)
				cor *= -1;
		}
	}
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			printf("%d", matriz[i][j]);
			if(j < c - 1)
				printf(" ");
			else if(j == c - 1 && i != l - 1)
				printf("\n");
		}
	}
	return 0;
}