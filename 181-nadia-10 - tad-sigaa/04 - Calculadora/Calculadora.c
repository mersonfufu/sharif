#ifndef CALCULADORA_C
#define CALCULADORA_C

#include <stdlib.h>

typedef struct numero {
	int esquerda;
	unsigned direita;
} stNumero;

stNumero * criarNumero(int esquerda, unsigned direita){
	stNumero *numeroptr = malloc(sizeof(stNumero));
	if(numeroptr){
		numeroptr->esquerda = esquerda;
		numeroptr->direita = direita;
	}
	return numeroptr;
}

void alterarEsquerda(stNumero *numeroptr, int esquerda){
	numeroptr->esquerda = esquerda;
}

void alterarDireita(stNumero *numeroptr, unsigned direita){
	numeroptr->direita = direita;
}

double acessarNumero(stNumero *numeroptr){
	double aux;
	//contador
	aux = numeroptr->direita;
	int digitos = 0;
	do {
		digitos++;
		aux = (int) aux / 10;
	} while(aux);
	//divisor
	aux = numeroptr->direita;
	while(digitos--)
		aux /= 10;
	return numeroptr->esquerda + aux;
}

double somarNumeros(stNumero *numero1ptr, stNumero *numero2ptr){
	return acessarNumero(numero1ptr) + acessarNumero(numero2ptr);
}

double multiplicarNumeros(stNumero *numero1ptr, stNumero *numero2ptr){
	return acessarNumero(numero1ptr) * acessarNumero(numero2ptr);
}

#endif
