#ifndef CUBO_C
#define CUBO_C

#include <stdlib.h>

typedef struct cubo {
    float lado;
} stCubo;

stCubo * criarCubo(float lado){
    stCubo *cuboptr = malloc(sizeof(stCubo));
    if(cuboptr)
        cuboptr->lado = lado;
    return cuboptr;
}

void alterarLado(stCubo *cuboptr, float lado){
    cuboptr->lado = lado;
}

float acessarLado(stCubo *cuboptr){
    return cuboptr->lado;
}

float calcularPerimetro(stCubo *cuboptr){
    return 12 * cuboptr->lado;
}

float calcularArea(stCubo *cuboptr){
    return 6 * cuboptr->lado * cuboptr->lado;
}

float calcularVolume(stCubo *cuboptr){
    return cuboptr->lado * cuboptr->lado * cuboptr->lado;
}

stCubo * destruirCubo(stCubo *cuboptr){
    free(cuboptr);
    return NULL;
}

#endif //CUBO_C