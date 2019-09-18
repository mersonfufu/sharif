#include <stdio.h>

int main(){
	double raio, altura, custo;
	scanf("%lf %lf", &raio, &altura);
	custo = (100 * (2 * (M_PI * raio * raio) + (2 * M_PI * raio * altura)));
	printf("O VALOR DO CUSTO E = %.2lf\n", custo);
	return 0;
}