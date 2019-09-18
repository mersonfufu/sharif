#include <stdio.h>

/**
 * Simplifica uma fracao a partir dos 5 primeiros numeros primos.
 * @param nt numerador da fracao.
 * @param dt denominador da fracao.
 */
void simplificar_fracao(double *nt, double *dt){
	double nti, dti;
	int i, j;
	for(;;){
		nti = *nt;
		dti = *dt;
		for(i = 0; i < 5; i++){
			if(i == 0)
				j = 2;
			else if(i == 1)
				j = 3;
			else if(i == 2)
				j = 5;
			else if(i == 3)
				j = 7;
			else if(i == 4)
				j = 10;
			if((long int)*nt % j == 0 && (long int)*dt % j == 0){
				*nt /= j;
				*dt /= j;
			}
		}
		if(nti == *nt && dti == *dt)
			break;
	}
}

/**
 * Calcula o valor de pi usando a serie de John Wallis.
 * @param termos quantidade de termos da serie.
 * @return o valor aproximado da constante pi.
 */
double calcular_pi(int termos){
	int i, n[500], d[500];
	double nt, dt;
	printf("frac = %.0lf/%.0lf\n", nt, dt);
}

int main(){
	int termos;
	scanf("%d", &termos);
	if(termos == 0)
		printf("0");
	else
		printf("%.12lf\n", calcular_pi(termos));
	return 0;
}