#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct numero stNumero;

stNumero * criarNumero(int, unsigned);

void alterarEsquerda(stNumero *, int);

void alterarDireita(stNumero *, unsigned);

double acessarNumero(stNumero *);

double somarNumeros(stNumero *, stNumero *);

double multiplicarNumeros(stNumero *, stNumero *);

#endif //CALCULADORA_H
