#ifndef ESFERA_H
#define ESFERA_H

typedef struct esfera stEsfera;

stEsfera * criarEsfera(float);

void alterarRaio(stEsfera *, float);

float acessarRaio(stEsfera *);

float calcularArea(stEsfera *);

float calcularVolume(stEsfera *);

stEsfera * destruirEsfera(stEsfera *);

#endif //ESFERA_H