#include <stdio.h>

/**
 * Conta a quantidade de leds necessaria pra mostrar um caractere.
 * @param num o numero que se quer mostrar no letreiro.
 * @return a quantidade de leds necessaria pra mostrar o num num letreiro.
 */
int totalizar_leds(int num){
	if(num == 1)
		return 2;
	if(num == 7)
		return 3;
	if(num == 4)
		return 4;
	if(num == 2 || num == 3 || num == 5)
		return 5;
	if(num == 6 || num == 9 || num == 0)
		return 6;
	if(num == 8)
		return 7;
}

int main(){
	int testes, t, total, i;
	char string[1001];
	scanf("%d", &testes);
	for(t = 0; t < testes; t++){
		total = 0;
		scanf("%s", string);
		for(i = 0; string[i] != '\0'; i++)
			total += totalizar_leds((int)string[i] - '0');
		printf("%d leds\n", total);
	}
	return 0;
}