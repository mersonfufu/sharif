#include <math.h>
#include <stdio.h>

int main(){
	float xa, ya, xb, yb, dist;
	scanf("%f %f %f %f", &xa, &ya, &xb, &yb);
	dist = pow(xb - xa, 2) + pow(yb - ya, 2);
	dist = sqrt(dist);
	printf("A DISTANCIA ENTRE A e B = %.2f\n", dist);
	return 0;
}