#include <stdio.h>

int main(){
	float sal, consumo;
	scanf("%f %f", &sal, &consumo);
	//0,7 aqui deveria ser 0,007
	printf("Custo por kW: R$ %.2f\nCusto do consumo: R$ %.2f\nCusto com desconto: R$ %.2f",
		sal * 0.7,
		sal * 0.7 * consumo,
		sal * 0.7 * consumo * 0.9
	);
	return 0;
}