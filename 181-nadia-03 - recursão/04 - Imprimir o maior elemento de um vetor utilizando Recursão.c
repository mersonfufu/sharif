#include <stdio.h>

int maior_valor(int indice, int *vetor) {
	int maior;
	if(indice == 0)
        maior = vetor[0];
    else {
        maior = maior_valor(indice - 1, vetor);
        if(maior < vetor[indice - 1])
            maior = vetor[indice - 1];
    }
	return maior;
}

int main(){
	int elementos, i;
	scanf("%d", &elementos);
	int vetor[elementos];
	for(i = 0; i < elementos ; i++)
		scanf("%d", &vetor[i]);
	printf("%d\n", maior_valor(elementos, vetor));
	return 0;
}