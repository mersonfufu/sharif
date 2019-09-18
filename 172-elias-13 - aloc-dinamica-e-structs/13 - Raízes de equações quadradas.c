#include <math.h>
#include <stdio.h>

typedef struct Complex {
	float real, imaginaria;
} stComplex;

typedef struct RaizEqu2 {
	struct Complex c1, c2;
} stRaizes;

/**
 * Funcao que calula as raizes de uma equacao de segundo grau.
 * @param a coeficiente quadrado.
 * @param b coeficiente linear.
 * @param c constante.
 * @return uma estrutura RaizEqu2 com dois numeros complexos.
 */
struct RaizEqu2 calcula_raiz_equ_2(float a, float b, float c){
	float delta;
	struct Complex c1 = {0, 0}, c2 = {0, 0};
	struct RaizEqu2 r;
	delta = b * b - 4 * a * c;
	if(delta < 0){
		c1.real = c2.real = -b / (2 * a);
		c1.imaginaria = sqrt(-delta) / (2 * a);
		c2.imaginaria = -sqrt(-delta) / (2 * a);
	} else {
		c1.real = (-b + sqrt(delta)) / (2 * a);
		c2.real = (-b - sqrt(delta)) / (2 * a);
	}
	r.c1 = c1;
	r.c2 = c2;
	return r;
}

/**
 * Imprime numeros complexos na saida padrao do sistema. A impressao segue o formato
 * a + bi,onde a e a parte real e b a imaginaria. Os valores sao apresentados
 * somente se forem diferentes de zero. No caso de a e b forem zero,o valor 0 e
 * apresentado. Se o valor de b for 1 ou-1,somente o caracter i ou-i e apresentado.
 * @param c Numero complexo a ser impresso.
 */
void complex_print(struct Complex c){
	if(c.real == 0 && c.imaginaria == 0)
		printf("0.00");
	else {
		if(c.real != 0)
			printf("%.2f", c.real);
		if(c.imaginaria < 0 && c.imaginaria != -1)
			printf("%.2fi", c.imaginaria);
		else if(c.imaginaria == -1)
			printf("-i");
		else if(c.imaginaria > 0 && c.imaginaria != 1)
			printf("+%.2fi", c.imaginaria);
		else if(c.imaginaria == 1 && c.real != 0)
			printf("+i");
		else if(c.imaginaria == 1 && c.real == 0)
			printf("i");
	}
	printf("\n");
}

int main(){
	float a, b, c;
	struct RaizEqu2 raizes;
	scanf("%f %f %f", &a, &b, &c);
	raizes = calcula_raiz_equ_2(a, b, c);
	printf("x1 = ");
	complex_print(raizes.c1);
	printf("x2 = ");
	complex_print(raizes.c2);
	return 0;
}