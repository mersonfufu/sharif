#include <stdio.h>

unsigned long mdc(unsigned long num, unsigned long den){
	if(den == 0)
		return num;
	return mdc(den, num % den);
}

int main(){
	long unsigned posicao, num, den, cont;
	scanf("%lu", &posicao);
	while(posicao){
		cont = 0;
		for(den = 1; ; den++){
			for(num = 0; num <= den; num++){
				if(mdc(num, den) == 1){
					cont++;
					//printf("%d = %lu/%lu\n", cont, num, den); //debug
				}
				if(cont == posicao){
					printf("%lu/%lu\n", num, den);
					break;
				}
			}
			if(cont == posicao)
				break;
		}
		scanf("%lu", &posicao);
	}
	return 0;
}
