#include <stdio.h>
#include "Esfera.h"

int main(){
	float raio;
	stEsfera *esferaptr = NULL;
	
	printf("Insira raio... ");
	scanf("%f", &raio);
	printf("\n");
	esferaptr = criarEsfera(raio);
	
//	alterarRaio(esferaptr, 5);
	
	printf("Raio = %.2f\nArea = %.2f\nVolume = %.2f\n",
		acessarRaio(esferaptr), calcularArea(esferaptr), calcularVolume(esferaptr)
	);
	
	esferaptr = destruirEsfera(esferaptr);
	
	return 0;
}