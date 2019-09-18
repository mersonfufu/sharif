#include <stdio.h>

int main(){
	double num, total = 0, termo, aux;
	int quant, cont, i;
	scanf("%lf %d", &num, &quant);
	while(num >= 6.28318530717958647692)
		num -= 6.28318530717958647692;
	for(cont = 0; cont <= quant; cont++){
		//primeiro
		termo = 1;
		//segundo
		aux = 1;
		for(i = 1; i <= cont; i++)
			aux *= num;
		//termo
		termo *= aux;
		//terceiro
		aux = 1;
		for(i = cont; i >= 1; i--)
			aux *= i;
		//total
		termo /= aux;
		total += termo;
	}
	printf("e^%.2lf = %.6lf\n", num, total);
	return 0;
}