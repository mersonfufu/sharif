#define alocar_vetor(quantidade,tamanho) calloc(quantidade+1,tamanho)
#include <stdio.h>
#include <stdlib.h>

typedef struct Cartela {
	int numJogo, numero[6];
} stCartela;

int main(){
	int i, apostas, j, k;
	int acertos, premiado = 0;
	stCartela *cartelaptr = NULL, premiada;
	scanf("%d", &apostas);
	cartelaptr = (stCartela *) alocar_vetor(apostas, sizeof(stCartela));
	//entrada
	for(i = 0; i < apostas; i++){
		scanf("%d", &cartelaptr[i].numJogo);
		for(j = 0; j < 6; j++)
			scanf("%d", &cartelaptr[i].numero[j]);
	}
	scanf("%d", &premiada.numJogo);
	for(i = 0; i < 6; i++)
		scanf("%d", &premiada.numero[i]);
	//saida
	for(i = 0; i < apostas; i++){
		acertos = 0;
		for(j = 0; j < 6; j++){
			for(k = 0; k < 6; k++){
				if(premiada.numero[k] == cartelaptr[i].numero[j])
					acertos++;
			}
		}
		if(acertos == 4 || acertos == 5 || acertos == 6)
			premiado = 1;
		if(acertos == 4){
			printf("QUADRA %d:", cartelaptr[i].numJogo);
			for(j = 0; j < 6; j++){
				for(k = 0; k < 6; k++){
					if(premiada.numero[k] == cartelaptr[i].numero[j])
						printf("%d", premiada.numero[k]);
				}
			}
			printf("\n");
		} else if(acertos == 5){
			printf("QUINA %d:", cartelaptr[i].numJogo);
			for(j = 0; j < 6; j++){
				for(k = 0; k < 6; k++){
					if(premiada.numero[k] == cartelaptr[i].numero[j])
						printf("%d", premiada.numero[k]);
				}
			}
			printf("\n");
		} else if(acertos == 6){
			printf("SENA %d:", cartelaptr[i].numJogo);
			for(j = 0; j < 6; j++){
				for(k = 0; k < 6; k++){
					if(premiada.numero[k] == cartelaptr[i].numero[j])
						printf("%d", premiada.numero[k]);
				}
			}
			printf("\n");
		}
	}
	if(premiado != 1)
		printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", premiada.numJogo);
	//free
	free(cartelaptr);
	return 0;
}