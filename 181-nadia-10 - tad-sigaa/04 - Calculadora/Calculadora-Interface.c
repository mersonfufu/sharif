#include <stdio.h>
#include "Calculadora.h"

int main(){
	int esquerda;
	unsigned direita;
	stNumero *numero1ptr = NULL, *numero2ptr = NULL;
	
	printf("Insira parte inteira do primeiro numero... ");
	scanf("%d", &esquerda);
	printf("Insira parte decimal do primeiro numero... ");
	scanf("%u", &direita);
	printf("\n");
	numero1ptr = criarNumero(esquerda, direita);

	printf("Insira parte inteira do segundo numero... ");
	scanf("%d", &esquerda);
	printf("Insira parte decimal do segundo numero... ");
	scanf("%u", &direita);
	printf("\n");
	numero2ptr = criarNumero(esquerda, direita);
	
//	alterarEsquerda(numero1ptr, 3);
//	alterarDireita(numero1ptr, 141592653);
//
//	alterarEsquerda(numero2ptr, 1);
//	alterarDireita(numero2ptr, 618033988);

	printf("Primeiro = %.12lf\n", acessarNumero(numero1ptr));
	printf("Segundo  = %.12lf\n", acessarNumero(numero2ptr));
	printf("Soma = %.12lf\n", somarNumeros(numero1ptr, numero2ptr));
	printf("Produto = %.12lf\n", multiplicarNumeros(numero1ptr, numero2ptr));
	
	return 0;
}
