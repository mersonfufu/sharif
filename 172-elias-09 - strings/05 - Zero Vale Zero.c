#define _TAMANHO 1000001
#include <stdio.h>

/**
 * Funcao que imprime os caracteres diferentes de zero de um vetor.
 * @param string um vetor com todos os caracteres
 */
void imprimir_100_zeros(char *vetor){
	int i;
	for(i = 0; vetor[i] != '\0'; i++)
		if(vetor[i] != '0')
			printf("%c", vetor[i]);
}

int main(){
	int a, b, i;
	char string[_TAMANHO];
	do {
		scanf("%d %d", &a, &b);
		if(a == 0 && b == 0)
			break;
		sprintf(string, "%d", a + b);
		imprimir_100_zeros(string);
		printf("\n");
	} while(1 && !0);
	return 0;
}