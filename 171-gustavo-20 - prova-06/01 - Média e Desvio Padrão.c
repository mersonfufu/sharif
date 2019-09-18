#include <stdio.h>
#include <math.h>

int main(){
	int i, j, testes, tamanho;
	int conjunto[10000];
	float media, desvio;
	scanf("%i", &testes);
	for(i = 0; i < testes; i++){
		media = 0;
		desvio = 0;
		scanf("%i", &tamanho);
		for(j = 0; j < tamanho; j++)
			scanf("%i", &conjunto[j]);
		for(j = 0; j < tamanho; j++)
			media += conjunto[j];
		media /= tamanho;
		for(j = 0; j < tamanho; j++)
			desvio += ((conjunto[j] - media) * (conjunto[j] - media));
		desvio /= tamanho;
		desvio = sqrt(desvio);
		printf("Media = %.2f Desvio Padrao = %.2f\n", media, desvio);
	}
	return 0;
}