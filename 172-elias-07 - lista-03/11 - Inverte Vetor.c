#include <stdio.h>

int main(){
	int tamanho, i, mm, mn;
	int vetorv[1001], vetorw[1001];
	scanf("%d", &tamanho);
	//primeiro
	for(i = 0; i < tamanho; i++){
		scanf("%d", &vetorv[i]);
		if(i == 0)
			mm = vetorv[i];
		else if(vetorv[i] > mm)
			mm = vetorv[i];
	}
	for(i = 0; i < tamanho; i++){
		printf("%d", vetorv[i]);
		if(i < tamanho - 1)
			printf(" ");
		else
			printf("\n");
	}
	//segundo
	for(i = 0; i < tamanho; i++){
		vetorw[tamanho - 1 - i] = vetorv[i];
		if(i == 0)
			mn = vetorw[tamanho - 1 - i];
		else if(vetorw[tamanho - 1 - i] < mn)
			mn = vetorw[tamanho - 1 - i];
	}
	for(i = 0; i < tamanho; i++){
		printf("%d", vetorw[i]);
		if(i < tamanho - 1)
			printf(" ");
		else
			printf("\n");
	}
	//menor-maior
	printf("%d\n%d\n", mm, mn);
	return 0;
}