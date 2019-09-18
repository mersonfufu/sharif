#ifndef CILINDRO_C
#define CILINDRO_C

#include <stdlib.h>

typedef struct cilindro {
	float raio, altura;
} stCilindro;

const double PI = 3.14159265358979323846;

stCilindro * criarCilindro(float raio, float altura){
	stCilindro *cilindroptr = malloc(sizeof(stCilindro));
	if(cilindroptr){
		cilindroptr->altura = altura;
		(*cilindroptr).raio = raio;
	}
	return cilindroptr;
}

void alterarRaio(stCilindro *cilindroptr, float raio){
	cilindroptr->raio = raio;
}

void alterarAltura(stCilindro *cilindroptr, float altura){
	cilindroptr->altura = altura;
}

float acessarAltura(stCilindro *cilindroptr){
	return cilindroptr->altura;
}

float acessarRaio(stCilindro *cilindroptr){
	return cilindroptr->raio;
}

float calcularVolume(stCilindro *cilindroptr){
	//altura do pirralho quadrado
	return cilindroptr->altura * PI * cilindroptr->raio * cilindroptr->raio;
}

stCilindro * destruirCilindro(stCilindro *cilindroptr){
	free(cilindroptr);
	return NULL;
}

#endif //CILINDRO_C