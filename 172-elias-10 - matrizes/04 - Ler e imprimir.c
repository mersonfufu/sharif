#include <stdio.h>

int main(){
	int i, j, l, c;
	int matriz[10][10];
	do {
		scanf("%d", &l);
	} while(l < 1 || l > 10);
	do {
		scanf("%d", &c);
	} while(c < 1 || c > 10);
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++)
			scanf("%d", &matriz[i][j]);
	}
	for(i = 0; i < l; i++){
		printf("linha %d: ", i + 1);
		for(j = 0; j < c; j++){
			printf("%d", matriz[i][j]);
			if(j < c - 1)
				printf(",");
			else if(j == c - 1 && i != l - 1)
				printf("\n");
		}
	}
	return 0;
}