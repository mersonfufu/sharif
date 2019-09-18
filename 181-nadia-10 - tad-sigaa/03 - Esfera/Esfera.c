#ifndef ESFERA_C
#define ESFERA_C

#include <stdlib.h>

typedef struct esfera {
	float raio;
} stEsfera;

const double PI = 3.14159265358979323846;

stEsfera * criarEsfera(float raio){
	stEsfera *esferaptr = malloc(sizeof(stEsfera));
	if(esferaptr)
		esferaptr->raio = raio;
	return esferaptr;
}

void alterarRaio(stEsfera *esferaptr, float raio){
	esferaptr->raio = raio;
}

float acessarRaio(stEsfera *esferaptr){
	return esferaptr->raio;
}

float calcularArea(stEsfera *esferaptr){
	return 4 * PI * esferaptr->raio * esferaptr->raio;
}

float calcularVolume(stEsfera *esferaptr){
	return (4 * PI * esferaptr->raio * esferaptr->raio * esferaptr->raio) / 3;
}

stEsfera * destruirEsfera(stEsfera *esferaptr){
	free(esferaptr);
	return NULL;
}

#endif //ESFERA_C