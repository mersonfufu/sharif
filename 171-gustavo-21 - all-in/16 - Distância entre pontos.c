#include <math.h>
#include <stdio.h>

struct Ponto {
	float u, x, y, z;
} pontoa, pontob;

int main(){
	int i, j, pontos;
	float distancia;
	scanf("%i", &pontos);
	for(j = 1; j < pontos; j++){
		if(j == 1){
			scanf("%f %f %f %f", &pontoa.u, &pontoa.x, &pontoa.y, &pontoa.z);
			scanf("%f %f %f %f", &pontob.u, &pontob.x, &pontob.y, &pontob.z);
		} else {
			pontoa.u = pontob.u;
			pontoa.x = pontob.x;
			pontoa.y = pontob.y;
			pontoa.z = pontob.z;
			scanf("%f %f %f %f", &pontob.u, &pontob.x, &pontob.y, &pontob.z);
		}
		distancia =
			((pontoa.u - pontob.u) * (pontoa.u - pontob.u)) +
			((pontoa.x - pontob.x) * (pontoa.x - pontob.x)) +
			((pontoa.y - pontob.y) * (pontoa.y - pontob.y)) +
			((pontoa.z - pontob.z) * (pontoa.z - pontob.z));
		distancia = sqrt(distancia);
		printf("%.2f\n", distancia);
	}
	return 0;
}