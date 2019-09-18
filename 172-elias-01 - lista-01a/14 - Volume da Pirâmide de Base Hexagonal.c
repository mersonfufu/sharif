#include <stdio.h>

int main(){
	float alt, ars;
	double vol;
	scanf("%f %f", &alt, &ars);
	vol = 3 * ars * ars * 1.7320508075688772935274463415059 / 2;
	vol = vol / 3 * alt;
	printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS", vol);
	return 0;
}