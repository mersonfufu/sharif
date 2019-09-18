#ifndef CUBO_H
#define CUBO_H

typedef struct cubo stCubo;

stCubo * criarCubo(float);

void alterarLado(stCubo *, float);

float acessarLado(stCubo *);

float calcularPerimetro(stCubo *);

float calcularArea(stCubo *);

float calcularVolume(stCubo *);

stCubo * destruirCubo(stCubo *);

#endif //CUBO_H