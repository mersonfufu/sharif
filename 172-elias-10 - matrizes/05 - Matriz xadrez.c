#include <stdio.h>

int main(){
	int i, j, l, c, cor = 1;
	int matriz[1000][1000];
	scanf("%d %d", &l, &c);
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			if(cor == 1){
				matriz[i][j] = 1;
				printf("%d", matriz[i][j]);
			} else {
				matriz[i][j] = 0;
				printf("%d", matriz[i][j]);
			}
			if(j != c - 1)
				cor *= -1;
			if(j == c - 1 && i != l - 1)
				printf("\n");
		}
	}
	printf("\n");
	return 0;
}