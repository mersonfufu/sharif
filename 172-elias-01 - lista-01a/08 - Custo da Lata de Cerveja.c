#include <stdio.h>

int main(){
	float raio, altura, custo;
	scanf("%f %f", &raio, &altura);
	custo = (100 * (2 * (3.14159 * raio * raio) + (2 * 3.14159 * raio * altura)));
	printf("O VALOR DO CUSTO E = %.2f \n", custo);
	return 0;
}