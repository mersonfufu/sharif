#include <stdio.h>

int main(){
	float fah, pol, cel, mm;
	scanf("%f %f", &fah, &pol);
	cel = (5 * fah - 160) / 9;
	mm = pol * 25.4;
	printf("O VALOR EM CELSIUS = %.2f\n", cel);
	printf("A QUANTIDADE DE CHUVA E = %.2f\n", mm);
	return 0;
}