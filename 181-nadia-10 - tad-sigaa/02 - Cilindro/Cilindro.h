#ifndef CILINDRO_H
#define CILINDRO_H

typedef struct cilindro stCilindro;

stCilindro * criarCilindro(float, float);

void alterarRaio(stCilindro *, float);

void alterarAltura(stCilindro *, float);

float acessarAltura(stCilindro *);

float acessarRaio(stCilindro *);

float calcularVolume(stCilindro *);

stCilindro * destruirCilindro(stCilindro *);

#endif //CILINDRO_H