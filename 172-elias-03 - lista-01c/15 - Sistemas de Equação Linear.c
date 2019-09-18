#include <stdio.h>

int main(){
	float a, b, c, d, e, f, x, y, det, aux;
	scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);
	det = a * e - b * d;
	aux = c * e - b * f;
	x = aux / det;
	aux = a * f - c * d;
	y = aux / det;
	printf("O VALOR DE X E = %.2f\n", x);
	printf("O VALOR DE Y E = %.2f\n", y);
	return 0;
}