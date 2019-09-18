#include <stdio.h>

void binario(unsigned numero){
    /* static int i; */
    if(numero){
		binario(numero >> 1);
		printf("%c", numero & 1 ? '1' : '0');
		/*
		i++;
	    i % 8 == 0 ? printf(" ") : 0;
	    */
    }
}

int main(){
	unsigned numero;
	scanf("%u", &numero);
	binario(numero);
	printf("\n");
	return 0;
}