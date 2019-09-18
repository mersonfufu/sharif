#include <stdio.h>
#include <math.h>

struct ponto {
	float u, x, y, z, norma;
} stPonto;

int main(){
	int tpontos, i, j, imenor;
	struct ponto pontos[1000], aux[1000];
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