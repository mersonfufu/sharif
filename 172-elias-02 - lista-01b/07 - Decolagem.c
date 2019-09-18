#include <stdio.h>

int main(){
	double massa, aceleracao, segundos;
	scanf("%lf %lf %lf", &massa, &aceleracao, &segundos);
	printf("VELOCIDADE = %.2lf\nESPACO PERCORRIDO = %.2lf\nTRABALHO REALIZADO = %.2lf\n",
		aceleracao * 3.6 * segundos,
		aceleracao * segundos * segundos / 2,
		massa * 1000 * aceleracao * segundos * aceleracao * segundos / 2
	);
	return 0;
}