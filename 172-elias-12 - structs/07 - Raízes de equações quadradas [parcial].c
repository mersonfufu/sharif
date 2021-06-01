#include <math.h>
#include <stdio.h>

typedef struct Complex {
	float real, imaginaria;
} stComplex;

typedef struct RaizEqu2 {
	struct Complex c1, c2;
} stRaizes;

/**
 * Fun��o que calula as ra�zes de uma equa��o de segundo grau.
 * @param a coeficiente quadrado
 * @param b coeficiente linear
 * @param c constante
 * @return uma estrutura RaizEqu2 com dois n�meros complexos
 */
struct RaizEqu2 calcula_raiz_equ_2(float a, float b, float c){
	float delta;
	struct Complex c1 = {0, 0}, c2 = {0, 0};
	struct RaizEqu2 r;
	delta = b * b - 4 * a * c;
	b == 0 ? (c1.real = c2.real = b) : (c1.real = c2.real = -b);
	if(delta < 0){
		c1.imaginaria = sqrt(-delta);
		if((int)c1.real % (int)2 * a == 0 && (int)c1.imaginaria % (int)2 * a == 0){
			c1.real /= (2 * a);
			c1.imaginaria /= (2 * a);
		}
		c2.imaginaria = -sqrt(-delta);
		if((int)c2.real % (int)2 * a == 0 && (int)c2.imaginaria % (int)2 * a == 0){
			c2.real /= (2 * a);
			c2.imaginaria /= (2 * a);
		}
	} else {
		c1.real += sqrt(delta);
		(int)c1.real % (int)2 * a == 0 ? c1.real /= (int)2 * a : 0;
		c2.real += -sqrt(delta);
		(int)c2.real % (int)2 * a == 0 ? c2.real /= (int)2 * a : 0;
	}
	r.c1 = c1;
	r.c2 = c2;
	return r;
}

/**
 * Imprime numeros complexos na sa�da padr�o do sistema. A impress�o segue o formato
 * a+bi,onde a � a parte real e b a imagin�ria. Os valores s�o apresentados
 * somente se forem diferente de zero. No caso de a e b forem zero,o valor 0 �
 * apresentado. Se o valor de b for 1 ou-1,somente o caracter i ou-i � apresentado.
 *
 * @param c Numero complexo a ser impresso.
 *
 */
void complex_print(struct Complex c){
	if(c.real == 0 && c.imaginaria == 0)
		printf("0.00");
	else {
		if(c.real != 0)
			printf("%.2f", c.real);
		if(c.imaginaria == -1)
			printf("-i");
		else {
			if(c.imaginaria < -1)
				printf("%.2f", c.imaginaria);
			else {
				if(c.imaginaria != 0){
					c.real != 0 ? printf("+") : 0;
					c.imaginaria == 1 ? printf("i") : printf("%.2f", c.imaginaria);
				}
			}
		}
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