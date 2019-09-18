#define NGORRO 4
#define NCAMISA 1111
#define NPES 8
#define NBRACOS 0
#include <stdio.h>

int main(){
	int i, j, l, c;
	int matriz[100][100];
	do {
		scanf("%d", &l);
	} while(l < 3);
	do {
		scanf("%d", &c);
	} while(c < 3);
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++)
			scanf("%d", &matriz[i][j]);
	}
	for(i = 0; i < l; i++){
		for(j = 0; j < c; j++){
			if(
				(matriz[i][j] == NCAMISA) &&
				(i - 1 < 0 || matriz[i - 1][j] == NGORRO) &&
				(j - 1 < 0 || matriz[i][j - 1] == NBRACOS) &&
				(j + 1 > c - 1 || matriz[i][j + 1] == NBRACOS) &&
				(i + 1 > l - 1 || matriz[i + 1][j] == NPES)
			){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("WALLY NAO ESTA NA MATRIZ");
	return 0;
}