#include <stdio.h>

int main(){
	float vi, v0, vf, v;
	float mlucro = 0, mvalor = 0, lucro;
	float quant, mquant;
	scanf("%f %f %f", &vi, &v0, &vf);
	if(v0 >= vf){
		printf("INTERVALO INVALIDO!");
		return 0;
	}
	v = v0;
	while(v <= vf){
		if(v < vi)
			quant = 120 + (vi - v0) * 50;
		else
			quant = 120 - (v - vi) * 60;
		lucro = quant * v - (200 + quant * 0, 05);
		if(lucro >= mlucro){
			mlucro = lucro;
			mvalor = vi;
			mquant = quant;
		}
		printf("V: %.2f, N: %.2f, L: %.2f\n", v, quant, lucro);
		v++;
	}
	printf("Melhor valor final: %.2f\nLucro: %.2f\nNumero de ingressos: %.2f\n", mvalor, mlucro, mquant);
	return 0;
}