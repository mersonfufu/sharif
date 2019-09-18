#include <stdio.h>

int main(){
	int tamanho, inteiro, i, cont = 0;
	int vetor[1001];
	do
		scanf("%d", &tamanho);
	while(tamanho < 1 || tamanho > 1000);
	for(i = 0; i < tamanho; i++)
		scanf("%d", &vetor[i]);
	scanf("%d", &inteiro);
	for(i = 0; i < tamanho; i++)
		if(vetor[i] >= inteiro)
			cont++;
	printf("%d\n", cont);
	return 0;
}