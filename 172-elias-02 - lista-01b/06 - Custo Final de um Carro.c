#include <stdio.h>

int main(){
	float um, dois, tres, custo;
	scanf("%f %f %f", &um, &dois, &tres);
	custo = um + (um * dois / 100) + (um * tres / 100);
	printf("O VALOR DO CARRO E = %.2f\n", custo);
	return 0;
}