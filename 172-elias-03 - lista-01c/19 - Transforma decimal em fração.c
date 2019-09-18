#include <stdio.h>

int main(){
	float numero, decimal;
	int i = 0, j, numerador, denominador;
	scanf("%f", &numero);
	decimal = numero - (int)numero;
	while(decimal > 0){
		numero *= 10;
		decimal = numero - (int)numero;
		i++;
	}
	numerador = numero;
	denominador = 1;
	for(j = 0; j < i; j++)
		denominador *= 10;
	for(i = 1; i <= denominador / 2; i++)
		if(numerador % i == 0 && denominador % i == 0){
			numerador /= i;
			denominador /= i;
		}
	printf("%d/%d\n", numerador, denominador);
	return 0;
}