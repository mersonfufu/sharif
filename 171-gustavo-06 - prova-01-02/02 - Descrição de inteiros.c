#include <stdio.h>

int main(){
	int numeroi, numero, m, c, d, u;
	scanf("%d", &numeroi);
	if(numeroi <= 0 || numeroi > 9999){
		printf("Numero invalido!");
		return 0;
	} else {
		numero = numeroi;
		m = numero / 1000;
		numero = numero - m * 1000;
		c = numero / 100;
		numero = numero - c * 100;
		d = numero / 10;
		numero = numero - d * 10;
		u = numero;
		//ordem
		if(numeroi >= 1000 && numeroi <= 9999)
			printf("(quarta ordem) ");
		if(numeroi >= 100 && numeroi <= 999)
			printf("(terceira ordem) ");
		if(numeroi >= 10 && numeroi <= 99)
			printf("(segunda ordem) ");
		if(numeroi >= 1 && numeroi <= 9)
			printf("(primeira ordem) ");
		printf("%d=", numeroi);
		//milhares
		if(m == 1)
			printf("%d unidade de milhar", m);
		else if(m > 1)
			printf("%d unidades de milhar", m);
		if(m != 0 && (c != 0 || d != 0 || u != 0))
			printf("+");
		//centenas
		if(c == 1)
			printf("%d centena", c);
		else if(c > 1)
			printf("%d centenas", c);
		if(c != 0 && (d != 0 || u != 0))
			printf("+");
		//dezenas
		if(d == 1)
			printf("%d dezena", d);
		else if(d > 1)
			printf("%d dezenas", d);
		if(d != 0 && u != 0)
			printf("+");
		//unidades
		if(u == 1)
			printf("%d unidade", u);
		else if(u > 1)
			printf("%d unidades", u);
		printf("=");
		//+
		if(m != 0)
			printf("%d", m * 1000);
		if(m != 0 && (c != 0 || d != 0 || u != 0))
			printf("+");
		if(c != 0)
			printf("%d", c * 100);
		if(c != 0 && (d != 0 || u != 0))
			printf("+");
		if(d != 0)
			printf("%d", d * 10);
		if(d != 0 && u != 0)
			printf("+");
		if(u != 0)
			printf("%d", u);
	}
	return 0;
}