#include <math.h>
#include <stdio.h>

int main(){
	float um, dois, tres, area, T;
	scanf("%f %f %f", &um, &dois, &tres);
	T = (um + dois + tres) / 2;
	area = T * (T - um) * (T - dois) * (T - tres);
	area = sqrt(area);
	printf("A AREA DO TRIANGULO E = %.2f\n", area);
	return 0;
}