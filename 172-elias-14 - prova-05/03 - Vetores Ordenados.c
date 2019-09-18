#define alocar_vetor(quantidade,tamanho) calloc(quantidade+1,tamanho)
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto {
	float u, x, y, z, norma;
} stPonto;

int main(){
	int tpontos, i, j, imenor;
	stPonto *pontoptr = NULL, aux;
	scanf("%d", &tpontos);
	pontoptr = (stPonto *) alocar_vetor(tpontos, sizeof(stPonto));
	//entrada
	for(i = 0; i < tpontos; i++){
		scanf("%f %f %f %f", &pontoptr[i].u, &pontoptr[i].x, &pontoptr[i].y, &pontoptr[i].z);
		pontoptr[i].norma = sqrt(
				(pontoptr[i].u * pontoptr[i].u) +
				(pontoptr[i].x * pontoptr[i].x) +
				(pontoptr[i].y * pontoptr[i].y) +
				(pontoptr[i].z * pontoptr[i].z)
			);
	}
	//selection
	for(i = 0; i < tpontos; i++){
		imenor = i;
		for(j = i + 1; j < tpontos; j++)
			if(pontoptr[j].norma < pontoptr[imenor].norma)
				imenor = j;
		if(imenor != i){
			aux = pontoptr[i];
			pontoptr[i] = pontoptr[imenor];
			pontoptr[imenor] = aux;
		}
	}
	//saida
	for(i = 0; i < tpontos; i++)
		printf("Vetor: (%.2f, %.2f, %.2f, %.2f) Norma:%.2f\n",
			pontoptr[i].u,
			pontoptr[i].x,
			pontoptr[i].y,
			pontoptr[i].z,
			pontoptr[i].norma
		);
	//free
	free(pontoptr);
	return 0;
}