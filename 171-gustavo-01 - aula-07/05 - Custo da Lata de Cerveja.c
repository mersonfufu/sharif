#include <stdio.h>

int main(){
	float raio, altura, custo;
	scanf("%f %f", &raio, &altura);
	custo = (100 * (2 * (2 * 3.14159265358979323846 * raio * raio) + (2 * 3.14159265358979323846 * raio * altura)));
	printf("O VALOR DO CUSTO E= %.2f \n", custo);
	return 0;
}