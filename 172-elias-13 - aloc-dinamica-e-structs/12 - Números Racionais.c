#include <stdio.h>

typedef struct tRacional {
	int numerador, denominador;
} stRacional;

/**
 * Calcula o MDC de x e y.
 * @param x um numero.
 * @param y outro numero.
 * @return o maior divisor comum entre os numeros.
 */
int MDC(int x, int y){
	if(x % y == 0)
		return y;
	else
		MDC(y, x % y);
}

/**
 * Recebe dois inteiros a e b e retorna o racional.
 * @param a numerador.
 * @param b denominador.
 * @return o racional entre a e b.
 */
struct tRacional racional(int a, int b){
	stRacional racional = {a, b};
	return racional;
}

/**
 * Recebe um racional e retorna o seu negativo (-r).
 * @param r numero racional.
 * @return o negativo do numero.
 */
struct tRacional negativo(struct tRacional r){
	r.numerador = -r.numerador;
	return r;
}

/**
 * Recebe dois racionais e retorna a adicao de ambos (r1+r2).
 * @param r1 fator esquerdo da soma.
 * @param r2 fator direito da soma.
 * @return a soma entre os dois numeros.
 */
struct tRacional soma(struct tRacional r1, struct tRacional r2){
	stRacional soma = {r1.numerador *r2.denominador + r1.denominador * r2.numerador, r1.denominador * r2.denominador};
	return soma;
}

/**
 * Recebe dois racionais e retorna o produto de ambos (r1*r2).
 * @param r1 primeiro fator do produto.
 * @param r2 segundo fator do produto.
 * @return o produto dos numeros.
 */
struct tRacional mult(struct tRacional r1, struct tRacional r2){
	stRacional produto = {r1.numerador * r2.numerador, r1.denominador * r2.denominador};
	return produto;
}

/**
 * Recebe dois racionais e retorna o quociente de ambos (r1/r2).
 * @param r1 numerador.
 * @param r2 denominador.
 * @return o quociente dos numeros.
 */
struct tRacional div(struct tRacional r1, struct tRacional r2){
	stRacional quociente = {r1.numerador * r2.denominador, r1.denominador * r2.numerador};
	return quociente;
}

/**
 * Recebe um racional e reduz a fracao ao maximo.
 * @param r o numero racional a ser reduzido.
 */
void reduzFracao(struct tRacional *r){
	int modnumerador, moddenominador;
	int divisor = 2, limite;
	(*r).numerador >= 0 ? (modnumerador = r->numerador) : (modnumerador = -r->numerador);
	r->denominador >= 0 ? (moddenominador = r->denominador) : (moddenominador = -r->denominador);
	modnumerador < moddenominador ? (limite = modnumerador) : (limite = moddenominador);
	if(r->numerador % r->denominador == 0){
		r->numerador = r->numerador / r->denominador;
		r->denominador = 1;
	} else if(r->denominador % r->numerador == 0){
		r->denominador = r->denominador / r->numerador;
		r->numerador = 1;
	} else {
		while(divisor != limite){
			if(r->numerador % divisor == 0 && r->denominador % divisor == 0){
				r->numerador /= divisor;
				r->denominador /= divisor;
			} else
				divisor++;
		}
	}
	if(r->denominador < 0){
		r->numerador = -r->numerador;
		r->denominador = -r->denominador;
	};
}

int main(){
	char operacao;
	int num1, num2, num3, num4;
	stRacional r1, r2;
	while(scanf("%d %d %c %d %d", &num1, &num2, &operacao, &num3, &num4) != EOF){
		r1 = racional(num1, num2);
		r2 = racional(num3, num4);
		if(operacao == '+')
			r1 = soma(r1, r2);
		else if(operacao == '-'){
			r2 = negativo(r2);
			r1 = soma(r1, r2);
		} else if(operacao == '*')
			r1 = mult(r1, r2);
		else if(operacao == '/')
			r1 = div(r1, r2);
		reduzFracao(&r1);
		printf("%d %d\n", r1.numerador, r1.denominador);
	}
	return 0;
}