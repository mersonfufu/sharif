#define _LINHAS 6
#define _COLUNAS 6
#define _TAMANHO 2
#include <stdio.h>

int main(){
	int elementos, i, kms = 0;
	int vetor[_TAMANHO] = {0};
	int distancias[_LINHAS][_COLUNAS] = {
		0, 63, 210, 190, -1, 190,
		63, 0, 160, 150, 95, 10,
		210, 160, 0, 10, 1, 10,
		190, 150, 10, 0, 10, 20,
		10, 95, 7, 21, 0, 80,
		190, 2, -1, 41, 80, 0
	};
	scanf("%d", &elementos);
	for(i = 0; i < elementos; i++){
		if(i == 0){
			scanf("%d %d", &vetor[0], &vetor[1]);
		} else {
			vetor[0] = vetor[1];
			scanf("%d", &vetor[1]);
		}
		if(distancias[vetor[0]][vetor[1]] != -1)
			kms += distancias[vetor[0]][vetor[1]];
		else {
			printf("rota invalida!\n");
			return 0;
		}
	}
	printf("%d\n", kms);
	return 0;
}