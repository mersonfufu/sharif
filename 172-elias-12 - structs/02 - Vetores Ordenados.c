#include <math.h>
#include <stdio.h>

typedef struct Ponto {
	float u, x, y, z, norma;
} stPonto;

int main(){
	int tpontos, i, j, imenor;
	struct Ponto pontos[1001], aux[1001];
	scanf("%d", &tpontos);
	for(i = 0; i < tpontos; i++){
		scanf("%f %f %f %f", &pontos[i].u, &pontos[i].x, &pontos[i].y, &pontos[i].z);
		pontos[i].norma = sqrt(
				(pontos[i].u * pontos[i].u) +
				(pontos[i].x * pontos[i].x) +
				(pontos[i].y * pontos[i].y) +
				(pontos[i].z * pontos[i].z)
			);
	}
	//selection-sort-vetorial
	for(i = 0; i < tpontos; i++){
		imenor = i;
		for(j = i + 1; j < tpontos; j++)
			if(pontos[j].norma < pontos[imenor].norma)
				imenor = j;
		if(imenor != i){
			aux[i] = pontos[i];
			pontos[i] = pontos[imenor];
			pontos[imenor] = aux[i];
		}
	}
	//saida
	for(i = 0; i < tpontos; i++)
		printf("Vetor: (%.2f, %.2f, %.2f, %.2f) Norma: %.2f\n",
			pontos[i].u,
			pontos[i].x,
			pontos[i].y,
			pontos[i].z,
			pontos[i].norma
		);
	return 0;
}